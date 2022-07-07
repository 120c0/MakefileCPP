#ifndef RECT_HPP
#define RECT_HPP

#include <SDL2/SDL.h>
#include <iostream>

class Rect
{
  public:
    Rect();
    explicit Rect(SDL_FPoint, float, float);


    SDL_FRect &getSDL_FRect() noexcept;
    operator SDL_FRect *() noexcept;
    operator SDL_Rect *() noexcept;

    virtual ~Rect() = default;

    SDL_FRect sdl_frect;
  private:
    SDL_Rect sdl_irect_impl;
};

#endif
