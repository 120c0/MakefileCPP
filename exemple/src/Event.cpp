#include "Event.hpp"

SDL_Event &Event::getSDL_Event() noexcept
{
  return this->sdl_event;
}

int Event::pollEvent() noexcept
{
  return SDL_PollEvent(&this->sdl_event);
}
