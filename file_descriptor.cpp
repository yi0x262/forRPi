#include"file_descriptor.hpp"

#include<fcntl.h>//open,read,write
#include<unistd.h>//close
#include<string.h>//strlen
#include<cerrno>
#include<system_error>

#include<iostream>
#define print(var) std::cout << #var << ":" << var << std::endl;

file_descriptor::file_descriptor(const char* device)
{
  if((fd = open(device,O_RDWR)) < 0){
    throw std::system_error(errno,std::system_category());
  }

  #ifdef _debug
  print(fd);
  #endif
}
int file_descriptor::_read(char buf[],int size) const
{
  #ifdef _debug
  print(sizeof(buf))
  #endif

  return read(fd,buf,size);
}

int file_descriptor::_write(const char buf[]) const
{
  #ifdef _debug
  std::cout << strlen(buf) << strlen(buf) << std::endl;
  #endif

  return write(fd,buf,strlen(buf));
}

file_descriptor::~file_descriptor()
{
  close(fd);
}
