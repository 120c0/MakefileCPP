#include "HelloWorld/HelloWorld.hpp"

#include <iostream>
#include <cstring>

HelloWorld::HelloWorld(const char name[256]) noexcept
{
  std::strcpy(this->__name, name);
}

void HelloWorld::exec() const noexcept
{
  std::cout << "Hello, " << this->__name << "\n";
}

HelloWorld::~HelloWorld()
{
}
