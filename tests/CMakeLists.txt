add_executable("test-dummy" "dummy.cpp")
target_link_libraries("test-dummy" "scp-game-framework")

add_executable("test-window" "window.cpp")
target_link_libraries("test-window" "scp-game-framework")