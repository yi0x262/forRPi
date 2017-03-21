#include"ADCPiPlus.hpp"

#include<iostream>

int main()
{
  ADCPiPlus adc(0x68);
  adc.read(1,1);

  return 0;
}
