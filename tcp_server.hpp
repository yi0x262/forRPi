#include"tcp_base.hpp"

class tcp_server:tcp_base
{
  boost::asio::ip::tcp::acceptor acc;
public:
  tpc_server(const char server_name[],const u_short port_num);
  int transceive(char msg[]);
};
