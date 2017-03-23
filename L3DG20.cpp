#include"L3DG20.hpp"

L3DG20::L3DG20(void) : RPi_i2c("/dev/i2c-1",0x6A){}

int L3DG20::read_xyz(const int reg)
{
  for(auto i:{0,1})
  {
    _write(static_cast<char>(reg+i));
    _read(&buf.buf[!i]);//x_low:0x28,x_high:0x29
  }
  return static_cast<int>(buf.num);
}

int read_x(void)
{
  return read_xyz(0x28);
}

int read_y(void)
{
  return read_xyz(0x2a);
}

int L3DG20::read_z(void)
{
  return read_xyz(0x2c);
}
