#include"file_descriptor.hpp"

class i2c_file:file
{
public:
  i2c_file(const char device[],const int address);
  int read_bytes(const char send[],char buf[],unsigned buf_size);
};
