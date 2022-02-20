// This contains the implementation files for the dummy header. It is merely
// used to set up the build system.
#include <iostream>

#include <scp/dummy.hpp>

namespace dummy_n = scp::dummy_n;

void dummy_n::say_hello()
{
    std::cout << "Hello!" << std::endl;
}