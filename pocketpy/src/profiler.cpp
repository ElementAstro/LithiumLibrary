#include "pocketpy/profiler.h"

namespace pkpy{

static std::string left_pad(std::string s, int width){
    int n = width - s.size();
    if(n <= 0) return s;
    return std::string(n, ' ') + s;
}

static std::string to_string_1f(f64 x){
    char buf[32];
    snprintf(buf, 32, "%.1f", x);
    return buf;
}

void LineProfiler::begin(){
    prev_time = 0;
    prev_record = nullptr;
    prev_line = -1;
    records.clear();
}

void LineProfiler::_step(Frame *frame){
    std::string_view filename = frame->co->src->filename.sv();
    int line = frame->co->lines[frame->_ip];
    // std::string_view function = frame->co->name.sv();

    if(prev_record == nullptr){
        prev_time = clock();
    }else{
        _step_end();
    }

    std::vector<LineRecord>& file_records = records[filename];
    if(file_records.empty()){
        int total_lines = frame->co->src->line_starts.size();
        file_records.resize(total_lines + 1);
        for(int i=1; i<=total_lines; i++){
            file_records[i].line = i;
        }
    }
    prev_record = &file_records.at(line);
}

void LineProfiler::_step_end(){
    clock_t now = clock();
    clock_t delta = now - prev_time;
    prev_time = now;
    if(prev_record->line != prev_line){
        prev_record->hits++;
        prev_line = prev_record->line;
    }
    prev_record->time += delta;
}

void LineProfiler::end(){
    _step_end();
}

Str LineProfiler::stats(){
    SStream ss;
    for(FuncDecl* decl: functions){
        int start_line = decl->code->start_line;
        int end_line = decl->code->end_line;
        if(start_line == -1 || end_line == -1) continue;
        std::string_view filename = decl->code->src->filename.sv();
        std::vector<LineRecord>& file_records = records[filename];
        if(file_records.empty()) continue;
        clock_t total_time = 0;
        for(int line = start_line; line <= end_line; line++){
            total_time += file_records.at(line).time;
        }
        ss << "Total time: " << (f64)total_time / CLOCKS_PER_SEC << "s\n";
        ss << "File: " << filename << "\n";
        ss << "Function: " << decl->code->name << " at line " << start_line << "\n";
        ss << "Line #      Hits         Time  Per Hit   % Time  Line Contents\n";
        ss << "==============================================================\n";
        for(int line = start_line; line <= end_line; line++){
            const LineRecord& record = file_records.at(line);
            if(!record.is_valid()) continue;
            ss << left_pad(std::to_string(line), 6);
            if(record.hits == 0){
                ss << std::string(10 + 13 + 9 + 9, ' ');
            }else{
                ss << left_pad(std::to_string(record.hits), 10);
                ss << left_pad(std::to_string(record.time), 13);
                ss << left_pad(std::to_string(record.time / record.hits), 9);
                if(total_time == 0){
                    ss << left_pad("0.0", 9);
                }else{
                    ss << left_pad(to_string_1f(record.time * (f64)100 / total_time), 9);
                }
            }
            // line_content
            auto [_0, _1] = decl->code->src->_get_line(line);
            ss << "  " << std::string_view(_0, _1-_0) << "\n";
        }
        ss << "\n";
    }
    return ss.str();
}

}   // namespace pkpy