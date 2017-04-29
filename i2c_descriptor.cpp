#include"i2c_descriptor.hpp"

#include<fcntl.h>//open,write,read
#include<unistd.h>//close
#include<sys/ioctl.h>//ioctl
#include<linux/i2c-dev.h>//I2C_SLAVE
#include<cstring>//strlen

#include<cerrno>//errno
#include<system_error>//system_error,


i2c_descriptor::i2c_descriptor(const char device[], const int address):file_descriptor(device)
{
  if(ioctl(descriptor,I2C_SLAVE,address) < 0){
    throw std::system_error(errno,std::system_category());
  }
}

bool read_byte(const char send[], char buf[], unsigned buf_size) const
{
  return (_write(&buf)==strlen(buf))&&(_read(buf,buf_size)==buf_size)
}
