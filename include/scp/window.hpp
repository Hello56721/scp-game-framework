#ifndef C23D629F_D9B0_4EDE_8118_1831B5064AE5
#define C23D629F_D9B0_4EDE_8118_1831B5064AE5

#include <string_view>
#include <cstdint>

#include <scp/macros.hpp>

// Forward declarations
struct GLFWwindow;

namespace scp
{
    // A simple class for displaying a window onto the screen. Currently uses 
    // GLFW as it's backend. As with all other classes, I will add features li-
    // ttle by little as I need them.
    class window_t
    {
    public:
        // Initialize GLFW
        static void init_glfw();
        
        // The width and height are specified in pixels. The title is self-exp-
        // lanitory.
        window_t(uint16_t width, uint16_t height, std::string_view title);
        
        // Show the window, since it's hidden by default.
        void show() const;
        
        // Returns if the window is still open.
        bool is_open() const;
        
        // Returns the width of the window.
        uint16_t get_width() const;
        
        // Returns the height of the window.
        uint16_t get_height() const;
        
        // Poll events
        static void poll_events();
        
        // Note: destructor only destroys the window, but does not terminates 
        // GLFW.
        ~window_t();
        
        // Terminate GLFW
        static void terminate_glfw();
        
    private:
        // Callbacks:
        // None, yet, but they will be added once the event system is in place.
        
        // The actual window handle.
        GLFWwindow* m_window;
        
        // The window width and height, since retrieving them via GLFW is kind 
        // of wierd
        uint16_t m_width;
        uint16_t m_height;
    };
}

#endif /* C23D629F_D9B0_4EDE_8118_1831B5064AE5 */
