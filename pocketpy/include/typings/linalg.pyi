from typing import overload, Iterator

class _vecF[T]:
    ONE: T
    ZERO: T

    def __add__(self, other: T) -> T: ...
    def __sub__(self, other: T) -> T: ...
    @overload
    def __mul__(self, other: float) -> T: ...
    @overload
    def __mul__(self, other: T) -> T: ...
    def __truediv__(self, other: float) -> T: ...

    def dot(self, other: T) -> float: ...
    def length(self) -> float: ...
    def length_squared(self) -> float: ...
    def normalize(self) -> T: ...

    # dummy iter for unpacking
    def __iter__(self) -> Iterator[float]: ...

class _vecI[T]:
    ONE: T
    ZERO: T

    def __add__(self, other: T) -> T: ...
    def __sub__(self, other: T) -> T: ...
    @overload
    def __mul__(self, other: int) -> T: ...
    @overload
    def __mul__(self, other: T) -> T: ...

    def __hash__(self) -> int: ...

    def dot(self, other: T) -> int: ...

    # dummy iter for unpacking
    def __iter__(self) -> Iterator[int]: ...


class vec2(_vecF['vec2']):
    LEFT: vec2
    RIGHT: vec2
    UP: vec2
    DOWN: vec2

    @property
    def x(self) -> float: ...
    @property
    def y(self) -> float: ...

    def with_x(self, x: float) -> vec2: ...
    def with_y(self, y: float) -> vec2: ...
    def with_z(self, z: float) -> vec3: ...

    @overload
    def __init__(self, x: float, y: float) -> None: ...
    @overload
    def __init__(self, xy: vec2i) -> None: ...

    def rotate(self, radians: float) -> vec2: ...

    @staticmethod
    def angle(__from: vec2, __to: vec2) -> float:
        """Returns the angle in radians between vectors `from` and `to`.

        The result range is `[-pi, pi]`.
        
        + if y axis is top to bottom, positive value means clockwise
        + if y axis is bottom to top, positive value means counter-clockwise
        """

    @staticmethod
    def smooth_damp(current: vec2, target: vec2, current_velocity: vec2, smooth_time: float, max_speed: float, delta_time: float) -> tuple[vec2, vec2]:
        """Smoothly changes a vector towards a desired goal over time.

        Returns a new value that is closer to the target and current velocity.
        """


class mat3x3:
    def __init__(self, _11, _12, _13, _21, _22, _23, _31, _32, _33) -> None: ...

    def __getitem__(self, index: tuple[int, int]) -> float: ...
    def __setitem__(self, index: tuple[int, int], value: float) -> None: ...

    @overload
    def __matmul__(self, other: mat3x3) -> mat3x3: ...
    @overload
    def __matmul__(self, other: vec3) -> vec3: ...

    def __invert__(self) -> mat3x3: ...

    def matmul(self, other: mat3x3, out: mat3x3) -> mat3x3 | None: ...
    def determinant(self) -> float: ...

    def copy(self) -> mat3x3: ...
    def inverse(self) -> mat3x3: ...

    def copy_(self, other: mat3x3) -> None: ...
    def inverse_(self) -> None: ...

    @staticmethod
    def zeros() -> mat3x3: ...
    @staticmethod
    def identity() -> mat3x3: ...

    # affine transformations
    @staticmethod
    def trs(t: vec2, r: float, s: vec2) -> mat3x3: ...

    def copy_trs_(self, t: vec2, r: float, s: vec2) -> None: ...

    def t(self) -> vec2: ...
    def r(self) -> float: ...
    def s(self) -> vec2: ...

    def transform_point(self, p: vec2) -> vec2: ...
    def transform_vector(self, v: vec2) -> vec2: ...


class vec2i(_vecI['vec2i']):
    LEFT: vec2i
    RIGHT: vec2i
    UP: vec2i
    DOWN: vec2i

    @property
    def x(self) -> int: ...
    @property
    def y(self) -> int: ...

    def with_x(self, x: int) -> vec2i: ...
    def with_y(self, y: int) -> vec2i: ...

    def __init__(self, x: int, y: int) -> None: ...


class vec3i(_vecI['vec3i']):
    @property
    def x(self) -> int: ...
    @property
    def y(self) -> int: ...
    @property
    def z(self) -> int: ...

    def with_x(self, x: int) -> vec3i: ...
    def with_y(self, y: int) -> vec3i: ...
    def with_z(self, z: int) -> vec3i: ...

    def __init__(self, x: int, y: int, z: int) -> None: ...


class vec3(_vecF['vec3']):
    @property
    def x(self) -> float: ...
    @property
    def y(self) -> float: ...
    @property
    def z(self) -> float: ...

    @property
    def xy(self) -> vec2: ...

    def with_x(self, x: float) -> vec3: ...
    def with_y(self, y: float) -> vec3: ...
    def with_z(self, z: float) -> vec3: ...
    def with_xy(self, xy: vec2) -> vec3: ...

    @overload
    def __init__(self, x: float, y: float, z: float) -> None: ...
    @overload
    def __init__(self, xyz: vec3i) -> None: ...



