cmake_minimum_required(VERSION 3.21)
project(408DS_cpp)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
include_directories(base)
include_directories(Link-链表)

add_executable(408DS_cpp
        base/base_cpp.cpp
        base/base_struct.cpp
        Link-链表/single_link.h
        Link-链表/StaticLink.h
        Link-链表/test_link.cpp Stack&Queue-栈&队列/stack_queue_test.cpp Stack&Queue-栈&队列/Stack.h Stack&Queue-栈&队列/表达式转换代码.cpp Stack&Queue-栈&队列/translate_stack.h Stack&Queue-栈&队列/Queue.h Stack&Queue-栈&队列/利用栈求表达式的值.cpp)
