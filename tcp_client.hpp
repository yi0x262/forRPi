#include"tcp_base.hpp"

class tcp_client:public tcp_base
{
public:
  tcp_client(const char server_name[],const u_short port_num);
  int transceive(char msg[]);
  ~tcp_client();
};
