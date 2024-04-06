
# Example executable
set(exe_sources
        examples.cpp
        )
		
add_executable(examples ${exe_sources})
target_include_directories(examples PRIVATE "${PROJECT_SOURCE_DIR}/include")
target_link_libraries(examples PUBLIC ${PROJECT_NAME})

target_compile_features(examples PRIVATE cxx_std_17)

execute_process(
  COMMAND ${Python_EXECUTABLE} "${PROJECT_SOURCE_DIR}/scripts/move_lookup.py" "${PROJECT_SOURCE_DIR}"
  TIMEOUT 30
  RESULT_VARIABLE generate_epJSON_schema_result)
