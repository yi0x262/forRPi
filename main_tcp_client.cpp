#include"tcp_client.hpp"
#include"kondo_servo.hpp"

#include<vector>
using std::vector;

int main(){
  tcp_client tc("192.168.1.8",12345);

  vector<kondo_servo> ks;
  for(int i : {0,1,6,7})ks.push_back(kondo_servo(i));

  return 0;
}
