#include "Window.hpp"

Window::Window(const char *window_title, glm::ivec2 window_size)
  : WindowBase(window_title, window_size)
{
}

// public
void Window::clear(SDL_Color color) noexcept
{
  SDL_SetRenderDrawColor(this->getSDL_Renderer(), color.r, color.g, color.b, color.a);
  SDL_RenderClear(this->getSDL_Renderer());  
}
void Window::display() noexcept
{
  SDL_RenderPresent(this->getSDL_Renderer());
}

// private

Window::~Window()
{
}
