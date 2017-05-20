
#include"kondo_servo.hpp"

#include<cstdlib>
#include<vector>
using std::vector;

#include<iostream>

int main(int argc, char* argv[])
{
  kondo_servo k(22);

  std::cout << static_cast<int>(k.current()) << std::endl;
  std::cout << static_cast<int>(k.temperature()) << std::endl;

  return 0;
}
