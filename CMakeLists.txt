cmake_minimum_required(VERSION 3.25)
project(gof
        VERSION 0.0.1
        LANGUAGES CXX
        HOMEPAGE_URL "https://github.com/khromenokroman/gof"
)


set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)


add_subdirectory(singleton)
add_subdirectory(strategy)