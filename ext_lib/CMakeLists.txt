# It is possible to omit the keyword defining what type of library to build. Unless the project
# specifically requires a particular type of library, the preferred practice is to not specify it and leave
# the choice up to the developer when building the project. In such cases, the library will be either
# STATIC or SHARED, with the choice determined by the value of a CMake variable called
# BUILD_SHARED_LIBS. If BUILD_SHARED_LIBS has been set to true, the library target will be a shared
# library, otherwise it will be static. Working with variables is covered in detail in Chapter 5,
# Variables, but for now, one way to set this variable is by including a -D option on the cmake

# cmake -S . -B build -DCMAKE_BUILD_TYPE=Debug -DBUILD_SHARED_LIBS=YES /path/to/source

# or

# set(BUILD_SHARED_LIBS YES)

#=== SETTING LIBRARY ===#
# add_library(${LIB_NAME} SHARED lib_name.cpp)
add_library(${EXT_LIB} lodepng.cpp)
set_target_properties(${EXT_LIB} PROPERTIES
    VERSION ${PROJECT_VERSION}
    SOVERSION 1
    PUBLIC_HEADER lodepng.h)
target_include_directories( ${EXT_LIB} PRIVATE . )
target_compile_features( ${EXT_LIB} PRIVATE cxx_std_14 )
