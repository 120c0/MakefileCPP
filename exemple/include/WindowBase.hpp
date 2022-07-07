#ifndef WINDOWBASE_HPP
#define WINDOWBASE_HPP

#include <SDL2/SDL.h>
#include <glm/glm.hpp>

class WindowBase
{
  public:
    WindowBase() = default;
    explicit WindowBase(const char*, glm::ivec2);

    virtual void create(const char*, glm::ivec2) noexcept;
    virtual void close() noexcept;
    const bool &getWindowIsRunning() const noexcept;
    SDL_Window *getSDL_Window() noexcept;
    SDL_Renderer *getSDL_Renderer() noexcept;

    virtual ~WindowBase();
  private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    bool window_is_running;
};

#endif
