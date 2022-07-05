#include "HelloWorld.hpp"

#include <cstring>
#include <iostream>

HelloWorld::HelloWorld(const char name[256]) noexcept
{
  strcpy(this->__name, name);
}

void HelloWorld::exec() const noexcept
{
  std::cout << "Hello, " << this->__name << "\n";
}

HelloWorld::~HelloWorld()
{
}
