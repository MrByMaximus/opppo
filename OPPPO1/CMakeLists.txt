cmake_minimum_required(VERSION 3.2)




set(SOURCES
Ball.cpp
Pyramid.cpp
Figures.cpp
FunctionReader.cpp
Reader.cpp
List.cpp
main.cpp
Node.cpp
Parallelepiped.cpp
ReaderPyramid.cpp
ReadOwner.cpp
ReadColor.cpp
)

set(HEADERS

Ball.h
Pyramid.h
ErrorCode.h
Figures.h
Reader.h
FunctionReader.h
List.h
Node.h
Parallelepiped.h
ReaderPyramid.h
ReadOwner.h
ReadColor.h)
add_executable(OPPPO ${SOURCES} ${HEADERS})
set_target_properties(
OPPPO PROPERTIES
CXX_STANDARD 11
CXX_STANDARD_REQUIRED ON
)