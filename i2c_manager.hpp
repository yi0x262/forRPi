#include"file_descriptor.hpp"

class i2c_manager
{
  static int i2c_descriptor;
  file bus;
public:
  RPi_i2c(const char device[],const int address);
  int write(char buf[])const;
  int read(char writebuf[],char readbuf[],int readsize)const;

};
