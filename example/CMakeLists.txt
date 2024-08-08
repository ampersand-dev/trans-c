include_directories(../include)

add_executable(trans-c-pack pack.cpp)
add_executable(trans-c-var  var.cpp)
add_executable(trans-c-ops  ops.cpp)
add_executable(trans-c-fn   fn.cpp)

target_link_libraries(trans-c-pack PRIVATE ampersand trans-c)
target_link_libraries(trans-c-var  PRIVATE ampersand trans-c)
target_link_libraries(trans-c-ops  PRIVATE ampersand trans-c)
target_link_libraries(trans-c-fn   PRIVATE ampersand trans-c)