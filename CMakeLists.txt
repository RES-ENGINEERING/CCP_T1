
cmake_minimum_required(VERSION 3.25)

project(CCP_T1 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

set(IMGUI_DIR "${CMAKE_SOURCE_DIR}/External/imgui")

find_package(OpenGL REQUIRED)

add_subdirectory(External/glfw)

add_executable(CCP_T1 WIN32
    Source/main.cpp
    Source/Window_Manager/window_mngr.cpp
    Source/GUI_Manager/gui_mngr.cpp
    Source/GUI_Code/Main_Menu/main_menu.cpp
    Source/System_Information_Obtainer/sys_info_obtainer.cpp
    Source/GUI_Manager/gui_element_mngr.cpp
    Source/Timestamp_System/timestamp_sys.cpp
    Source/Chrono_System/chrono_sys.cpp
    Source/Text_Format_System/text_format_sys.cpp
    

    ${IMGUI_DIR}/imgui.cpp
    ${IMGUI_DIR}/imgui_draw.cpp
    ${IMGUI_DIR}/imgui_tables.cpp
    ${IMGUI_DIR}/imgui_widgets.cpp
    ${IMGUI_DIR}/imgui_demo.cpp

    ${IMGUI_DIR}/backends/imgui_impl_glfw.cpp
    ${IMGUI_DIR}/backends/imgui_impl_opengl3.cpp
)

target_link_options(CCP_T1 PRIVATE "LINKER:/ENTRY:mainCRTStartup")

target_include_directories(CCP_T1 PRIVATE
    External
    Include
)

target_link_libraries(CCP_T1 PRIVATE
    glfw
    OpenGL::GL
    dwmapi
)

set_target_properties(CCP_T1 PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_SOURCE_DIR}/Binary/$<CONFIG>"
)
