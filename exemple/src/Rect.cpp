#include "Rect.hpp"

Rect::Rect()
  : sdl_frect {0.f, 0.f, 10.f, 10.f}
{
}

Rect::Rect(SDL_FPoint center, float width, float height)
  : sdl_frect {center.x, center.y, width, height}
{
}

SDL_FRect &Rect::getSDL_FRect() noexcept
{
  return this->sdl_frect;
}
Rect::operator SDL_FRect *() noexcept
{
  return &this->sdl_frect;
}
Rect::operator SDL_Rect *() noexcept
{
  return &(this->sdl_irect_impl = {
    (int) std::ceil(this->sdl_frect.x),
    (int) std::ceil(this->sdl_frect.y),
    (int) std::ceil(this->sdl_frect.w),
    (int) std::ceil(this->sdl_frect.h)
  });
}
