cmake_minimum_required(VERSION 3.3.0)
set(CMAKE_C_COMPILER /usr/bin/clang)
set(CMAKE_CXX_COMPILER /usr/bin/clang)
project (fuzzer_target)
set(WORKSPACE_ROOT "./")
add_definitions(-DFUZZING)

add_executable(fuzzer_target ./fuzz_target.c fun.c)
target_compile_options(fuzzer_target PRIVATE -fsanitize=fuzzer -fsanitize=address -ggdb)
target_link_libraries(fuzzer_target PRIVATE -fsanitize=fuzzer -fsanitize=address -ggdb)

add_executable(fuzzer_target_cov ./fuzz_target.c fun.c)
target_compile_options(fuzzer_target_cov PRIVATE -fsanitize=fuzzer -fprofile-instr-generate -fcoverage-mapping -O0 -ggdb)
target_link_libraries(fuzzer_target_cov PRIVATE -fsanitize=fuzzer,address -fprofile-instr-generate -fcoverage-mapping -O0 -ggdb)