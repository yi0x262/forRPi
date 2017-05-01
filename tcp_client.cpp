#include"tcp_client.hpp"
namespace ip = boost::asio::ip;

#include<string>

tcp_client::tcp_client(const char server_name[],const u_short port_num):tcp_base()
{
  sock.connect(ip::tcp::endpoint(ip::address::from_string(static_cast<std::string>(server_name)),port_num));
}

int tcp_client::transceive(char msg[])
{
  boost::asio::write(sock,boost::asio::buffer(static_cast<std::string>(msg)));

  boost::asio::streambuf receive_buf;
  boost::system::error_code error;
  boost::asio::read(sock,receive_buf,boost::asio::transfer_at_least(1),error);

  return 0;
}
