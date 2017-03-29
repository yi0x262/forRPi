#include"L3DG20.hpp"

#include<iostream>
#include<bitset>

#include<stdexcept>

#include<unistd.h>

static char setup[2] = {(char)0x20,(char)0x0f};
L3DG20::L3DG20() : RPi_i2c("/dev/i2c-1",0x6A)
{
  //who am i
  char whoami = static_cast<char>(0x0f);
  _write(&whoami);
  _read(&whoami);
  std::cout << "who am i\t" << std::bitset<8>(whoami) << std::endl;
  if(whoami != (char)0xd4)throw std::runtime_error("who am i error");

  //setup
  _write(setup);
  //confirm setup
  char setup_reg[1] = {(char)0x20};
  _write(setup_reg);
  _read(setup_reg);
  std::cout << "setup\t" << std::bitset<8>(setup_reg[0]) << std::endl;
}

#include<initializer_list>
int L3DG20::read_xyz(const int reg)
{
  char send[1];
  char receive[2] = {(char)0x00,(char)0x00};
  for(auto i:{0,1})
  {
    send[0] = static_cast<char>(reg+i);
    std::cout <<std::bitset<8>(send[0]) << " ";// << std::bitset<8>(receive[0])<<std::bitset<8>(receive[1]) << " ";
    _write(send);
    _read(send);//x_low:0x28,x_high:0x29
    std::cout <<std::bitset<8>(send[0]) << " ";// << std::bitset<8>(receive[0])<<std::bitset<8>(receive[1]) << " ";
    receive[i] = send[0];
    usleep(10000);
  }
  //std::cout <<std::bitset<8>(send[0]) << " " << std::bitset<8>(receive[0])<<std::bitset<8>(receive[1]) << " ";
  return static_cast<int>(buf.num);
}


static const double gain = 8.75e-3;
double L3DG20::read_x(void)
{
  return gain*read_xyz(0x28);
}

double L3DG20::read_y(void)
{
  return gain*read_xyz(0x2a);
}

double L3DG20::read_z(void)
{
  return gain*read_xyz(0x2c);
}
