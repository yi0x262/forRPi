#include"i2c_descriptor.hpp"

int main(int argc,char* argv[])
{
  i2c_descriptor adc1(argv[1],0x68);
  i2c_descriptor adc2(argv[1],0x69);
  i2c_descriptor gyro(argv[1],0x6b);
  return 0;
}
