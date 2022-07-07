#include "WindowBase.hpp"

WindowBase::WindowBase(const char *window_title, glm::ivec2 window_size)
{
  this->create(window_title, window_size);
}

// public
void WindowBase::create(const char *window_title, glm::ivec2 window_size) noexcept
{
  this->window_is_running = (
    this->renderer = (SDL_CreateRenderer(this->window = SDL_CreateWindow(window_title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, window_size.x, window_size.y, SDL_WINDOW_SHOWN), -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC))
  ) && this->window;
}
void WindowBase::close() noexcept
{
  this->window_is_running = false;
}
const bool &WindowBase::getWindowIsRunning() const noexcept
{
  return this->window_is_running;
}
SDL_Window *WindowBase::getSDL_Window() noexcept
{
  return this->window;
}
SDL_Renderer *WindowBase::getSDL_Renderer() noexcept
{
  return this->renderer;
}

// private


WindowBase::~WindowBase()
{
  SDL_DestroyWindow(this->window);
  SDL_DestroyRenderer(this->renderer);
}
