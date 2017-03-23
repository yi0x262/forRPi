#include"ADCPiPlus.hpp"

#include<iostream>
#include<cstdlib>
#include<vector>
#include<unistd.h>//usleep

int main(int argc,char* argv[])
{
  int address = atoi(argv[1]);
  int conversion = atoi(argv[2]);
  int bit_rate = atoi(argv[3]);

  ADCPiPlus adc(address,conversion,bit_rate,1);

  //std::cout << address << conversion << bit_rate << std::endl;
  while(1)
  {
    for (int c = 0; c < 4; ++c)
    //for(auto c : {1,2})
    {
      std::cout << adc.read(c) << "\t";
    }
    usleep(1e5);

    std::cout << std::endl;
  }

  return 0;
}
