#ifndef HELLOWORLD_HPP_
#define HELLOWORLD_HPP_

class HelloWorld final
{
public:
  explicit HelloWorld() noexcept = default;
  void exec() const noexcept;
};

#endif
