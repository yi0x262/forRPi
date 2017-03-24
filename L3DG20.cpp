#include"L3DG20.hpp"

L3DG20::L3DG20() : RPi_i2c("/dev/i2c-1",0x6B){}

#include<initializer_list>
int L3DG20::read_xyz(const int reg)
{
  for(auto i:{0,1})
  {
    char send = static_cast<char>(reg+i);
    _write(&send);
    _read(&buf.buf[!i]);//x_low:0x28,x_high:0x29
  }
  return static_cast<int>(buf.num);
}

int L3DG20::read_x(void)
{
  return read_xyz(0x28);
}

int L3DG20::read_y(void)
{
  return read_xyz(0x2a);
}

int L3DG20::read_z(void)
{
  return read_xyz(0x2c);
}
