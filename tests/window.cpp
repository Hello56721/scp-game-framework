#include <scp/window.hpp>

int main()
{
    scp::window_t window(1280, 720, "SCP Game Framework Window Test");
    
    window.show();
    
    while (window.is_open())
    {
        scp::window_t::poll_events();
    }
}