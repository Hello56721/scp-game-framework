#include <GLFW/glfw3.h>
#include <stdexcept>

#include <scp/window.hpp>

using scp::window_t;

void window_t::init_glfw()
{
    if (!glfwInit())
    {
        throw std::runtime_error("Failed to initialize GLFW.");
    }
}

window_t::window_t(uint16_t p_width, uint16_t p_height, std::string_view p_title)
{
    glfwWindowHint(GLFW_VISIBLE, GLFW_FALSE);
    
    m_width = p_width;
    m_height = p_height;
    
    m_window = glfwCreateWindow(p_width, p_height, p_title.data(), nullptr, nullptr);
    if (m_window == nullptr)
    {
        terminate_glfw();
        throw std::runtime_error("Failed to create GLFW window " + std::string(p_title.data()));
    }
}

void window_t::show() const
{
    glfwShowWindow(m_window);
}

bool window_t::is_open() const
{
    return !glfwWindowShouldClose(m_window);
}

uint16_t window_t::get_width() const
{
    return m_width;
}

uint16_t window_t::get_height() const
{
    return m_height;
}

void window_t::poll_events()
{
    glfwPollEvents();
}

window_t::~window_t()
{
    glfwDestroyWindow(m_window);
}

void window_t::terminate_glfw()
{
    glfwTerminate();
}
