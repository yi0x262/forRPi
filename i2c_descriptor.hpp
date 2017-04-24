#include"file_descriptor.hpp"

class i2c_descriptor
{
  static int descriptor;
  static int instance_counter;
public:
  i2c_descriptor(const char device[],const int address);
  int read_byte(const char send[],char buf[],size_t buf_size)const;
  ~i2c_descriptor();

  friend i2c_descriptor(const char [],const int);
};
