#include"file_descriptor.hpp"

class i2c_descriptor
{
  static int i2c_descriptor;
  static int instance_counter;
public:
  i2c_descriptor(const char device[],const int address);
  int get_descripotr(void)const;
  int _write(char buf[])const;
  int _read(char writebuf[],char readbuf[],int readsize)const;
  ~i2c_descriptor();
};
