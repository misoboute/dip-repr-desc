CMAKE_MINIMUM_REQUIRED(VERSION 3.0)
PROJECT(dip_repr_desc)

set(SOURCE_FILES
    main.cpp
)

set(HEADER_FILES
)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SOURCE_FILES} ${HEADER_FILES})

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARIES})

target_compile_features(${PROJECT_NAME} PRIVATE cxx_constexpr)
