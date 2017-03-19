#include"RPi_io.hpp"
#include<fcntl.h>//open,close
#include<stdexcept>//runtime_error

RPi_io::RPi_io(const char* device)
{
  if((fd = open(device,O_RDWR)) < 0){
    throw std::runtime_error("device open error");
  }
}

RPi_io::~RPi_io()
{
  close(fd);
}
