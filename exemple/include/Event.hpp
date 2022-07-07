#ifndef EVENT_HPP
#define EVENT_HPP

#include <SDL2/SDL_events.h>

class Event
{
  public:
    Event() = default;

    virtual SDL_Event &getSDL_Event() noexcept;
    virtual int pollEvent() noexcept;

    virtual ~Event() = default;
  private:
    SDL_Event sdl_event;
};

#endif
