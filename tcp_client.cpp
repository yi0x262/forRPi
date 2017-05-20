#include"tcp_client.hpp"
namespace ip = boost::asio::ip;

#include<string>
using std::string;

tcp_client::tcp_client(const char server_name[],const u_short port_num):tcp_base()
{
  sock.connect(ip::tcp::endpoint(ip::address::from_string(static_cast<std::string>(server_name)),port_num));
}

int tcp_client::write(const char msg[])const
{
  return boost::asio::write(sock,boost::asio::buffer(static_cast<std::string>(msg)));
}

string tcp_client::receive()
{
  boost::asio::streambuf receive_buf;
  boost::system::error_code error;
  boost::asio::read(sock,receive_buf,boost::asio::transfer_at_least(1),error);
  return boost::asio::buffer_cast<const char*>(receive_buf.data());
}

string tcp_client::transceive(const char msg[])
{
  write(msg);
  return receive();
}

tcp_client::~tcp_client()
{
  sock.close();
}
