#include"file_descriptor.hpp"

class i2c_descriptor
{
  static int descriptor;
  static int instance_counter;
public:
  i2c_descriptor(const char device[],const int address);
  int get_descriptor(void)const;
  int _write(char buf[])const;
  int _read(char readbuf[],int readsize)const;
  ~i2c_descriptor();
};
