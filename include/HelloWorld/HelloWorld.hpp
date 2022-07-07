#pragma once

class HelloWorld final
{
  public:
    HelloWorld(const char name[256]) noexcept;
  
    virtual void exec() const noexcept;

    virtual ~HelloWorld();
  private:
    char __name[256];
};
