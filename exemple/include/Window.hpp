#ifndef WINDOW_HPP
#define WINDOW_HPP

#include "WindowBase.hpp"

class Window : public WindowBase
{
  public:
    Window() = default;
    explicit Window(const char*, glm::ivec2);

    virtual void clear(SDL_Color) noexcept;
      virtual void display() noexcept;

    virtual ~Window();
  private:

};

#endif
