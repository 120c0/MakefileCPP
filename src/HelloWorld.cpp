#include "HelloWorld.h"

#include <iostream>
#include <string.h>

HelloWorld::HelloWorld(const char *name) noexcept
{
  strcpy(this->__name, name);
}

void HelloWorld::exec() const noexcept
{
  std::cout << "Hello, " << this->__name << "!\n";
}

HelloWorld::~HelloWorld()
{
}
