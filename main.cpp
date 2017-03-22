#include"ADCPiPlus.hpp"

#include<iostream>
#include<cstdlib>
#include<vector>

int main(int argc,char* argv[])
{
  int address = atoi(argv[1]);
  int conversion = atoi(argv[2]);
  int bit_rate = atoi(argv[3]);

  ADCPiPlus adc(address,conversion,bit_rate,1);

  //std::cout << address << conversion << bit_rate << std::endl;
  while(1)
  {
    std::cout << adc.read(1);
    //for(auto c : {1,2,3,4})std::cout << adc.read(c) << "\t";
    std::cout << std::endl;
  }

  return 0;
}
