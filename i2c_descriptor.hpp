#include"file_descriptor.hpp"

class i2c_descriptor:file_descriptor
{
public:
  i2c_descriptor(const char device[],const int address);
  int read_bytes(const char send[],char buf[],size_t buf_size)const;
};
