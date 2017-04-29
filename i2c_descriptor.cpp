#include"i2c_descriptor.hpp"

#include<fcntl.h>//open,write,read
#include<unistd.h>//close
#include<sys/ioctl.h>//ioctl
#include<linux/i2c-dev.h>//I2C_SLAVE
#include<cstring>//strlen

#include<cerrno>//errno
#include<system_error>//system_error,


i2c_file::i2c_file(const char device[], const int address):file(device)
{
  if(ioctl(descriptor,I2C_SLAVE,address) < 0){
    throw std::system_error(errno,std::system_category());
  }
}

bool i2c_file::read_bytes(const char send[], char buf[], unsigned buf_size)
{
  return (_write(buf)==static_cast<int>(strlen(buf)))&&(_read(buf,buf_size)==static_cast<int>(buf_size));
}
