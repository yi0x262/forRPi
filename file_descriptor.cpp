#include"file_descriptor.hpp"

#include<fcntl.h>//open,read,write
#include<unistd.h>//close
#include<string.h>//strlen
#include<cerrno>
#include<system_error>

#ifdef _debug
#include<iostream>
#define print(var) std::cout << #var << ":" << var << std::endl;
#endif

file::file(const char* device) : descriptor(open(device,O_RDWR))
{
  if(descriptor < 0){
    throw std::system_error(errno,std::system_category());
  }

  #ifdef _debug
  print(descriptor);
  #endif
}

int file::_read(char buf[],unsigned size) const
{
  #ifdef _debug
  print(sizeof(buf))
  #endif

  return read(descriptor,buf,size);
}

int file::_write(const char buf[]) const
{
  #ifdef _debug
  print(strlen(buf))
  #endif

  return write(descriptor,buf,strlen(buf));
}

file::~file()
{
  #ifdef _debug
  std::cout << "fd " << descriptor << " closed" << std::endl;
  #endif

  close(descriptor);
}
