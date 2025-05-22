cmake_minimum_required(VERSION 3.30)
project(music_player)

set(CMAKE_CXX_STANDARD 20)

add_executable(music_player
        main.cpp
        User.cpp
        Admin.cpp
        Member.cpp
        Singer.cpp
        Music.cpp
        PlayList.cpp
)
