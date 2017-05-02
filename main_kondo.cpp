#include"kondo_servo.hpp"
#include"tcp_client.hpp"

union us_c
{
  unsigned short i;
  char c[2];
};

#include<vector>
using std::vector;
#include<algorithm>

int main(int argc, char* argv[])
{
  tcp_client tc(argv[1],12345);

  kondo_servo ks[5]{0,1,2,3,4};

  vector<char> buf;
  char *cbuf = new char[buf.size()];

  while(true)
  {
    for(auto k : ks)
    {
      us_c angle.i = k.rotate(7500);
      buf.push_back(angle.c[0]);
      buf.push_back(angle.c[1]);
      buf.push_back(k.current());
      buf.push_back(k.temperature());
    }
    std::copy(buf.begin(),buf.end(),cbuf);
    tc.transceive(cbuf);
  }
}
