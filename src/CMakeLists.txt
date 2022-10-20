#=== Main App ===
add_executable( ${APP_NAME} canvas.cpp driver_canvas.cpp )
target_include_directories( ${APP_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/ext_lib )
target_compile_features( ${APP_NAME}  PUBLIC cxx_std_14 )
target_link_libraries( ${APP_NAME} PRIVATE ${EXT_LIB})
