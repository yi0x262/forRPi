#include"i2c_descriptor.hpp"

int main(int argc,char* argv[])
{
  i2c_descriptor fd(argv[1],0x6a);
  return 0;
}
