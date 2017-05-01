#include"tcp_client.hpp"

int main(){
  tcp_client tc("192.168.1.8",12345);
  char msg[] = "hello";

  tc.transceive(msg);

  return 0;
}
