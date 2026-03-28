cmake_minimum_required(VERSION 3.13)
project(CustomMenuButtons)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ✅ correct for GitHub Actions
set(GEODE_TARGET_PLATFORM Linux)

add_subdirectory(geode)

add_geode_mod(
    mr_funnykogames.custom_menu_buttons
    VERSION 1.0.0
    FILES main.cpp
)

geode_target_resources(mr_funnykogames.custom_menu_buttons
    RESOURCES
    logo.png
    Profilepic.png
)