#include"ADCPiPlus.hpp"

#include<iostream>

int main()
{
  ADCPiPlus adc = ADCPiPlus(0x68);
  adc.read(1,1);

  return 0;
}
