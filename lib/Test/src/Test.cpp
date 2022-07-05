#include "Test.hpp"

Test::Test(std::function<const bool&> &test_code) noexcept
  : __test_code {& test_code}
{

}

Test::~Test()
{
}
