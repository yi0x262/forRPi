#include"i2c_descriptor.hpp"

int main(int argc,char* argv[])
{
  i2c_file adc1("/dev/i2c-dev",0x68);
  i2c_file adc2("/dev/i2c-dev",0x69);
  i2c_file gyro("/dev/i2c-dev",0x6b);
  return 0;
}
