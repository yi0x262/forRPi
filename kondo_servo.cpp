#include"kondo_servo.hpp"

#include<cerrno>
#include<system_error>

kondo_servo::kondo_servo(const int servo_id):
  fd(file("/dev/ttyAMA0")),id(servo_id){}

unsigned short kondo_servo::rotate(unsigned short target_angle)
{
  char wbuf[3] = {(char)(0x80+id),(char)((target_angle>>7)&0x7f),(char)(target_angle&0x7f)};
  fd._write(wbuf);
  char rbuf[6];
  fd._read(rbuf,6);
  return static_cast<unsigned short>(rbuf[4])<<7 + static_cast<unsigned short>(rbuf[5]);
}

#include<iostream>


char kondo_servo::get_state(const int sc)const {
  char wbuf[2] = {static_cast<char>(0xa0+id),static_cast<char>(sc)};
  char rbuf[5];//id,sc,rid,rsc,data
  fd._write(wbuf);
  fd._read(rbuf,5);
  //throw std::system_error(errno,std::system_category());
  return rbuf[4];
}

char kondo_servo::current(void)const
{
  return get_state(0x03);
}

char kondo_servo::temperature(void)const
{
  return get_state(0x04);
}

kondo_servo::~kondo_servo()
{
  fd.~file();
}
