#include"tcp_client.hpp"
#include"kondo_servo.hpp"

#include<vector>
using std::vector;

int main(int argc,const char* argv[]){
  tcp_client tc(argv[1],12345);

  vector<kondo_servo> ks;
  for(int i : {0,1,6,7})ks.push_back(kondo_servo(i));

  return 0;

}
