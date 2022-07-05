#pragma once

#include <functional>

class Test
{
  public:
    Test(std::function<const bool&>&) noexcept;

    virtual ~Test();
  private:
    std::function<const bool&> *__test_code;
};
