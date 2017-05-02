#include"kondo_servo.hpp"

kondo_servo::kondo_servo(const int servo_id):
  fd(file("/dev/ttyAMA0")),id(servo_id){}

unsigned short kondo_servo::rotate(unsigned short target_angle)
{
  char wbuf[3] = {(char)0x80+id,(char)(target_angle>>7)&0x7f,(char)target_angle&0x7f};
  fd._write(wbuf);
  char rbuf[6];
  fd._read(rbuf,6);
  return static_cast<unsigned short>(rbuf[4])<<7 + static_cast<unsigned short>(rbuf[5]);
}

char kondo_servo::current(void){
  char wbuf = {(char)0xa0+id,(char)0x03};
  fd._write(wbuf);
  char buf[5];
  fd._read(buf,5);
  return buf[4];
}

char kondo_servo::temperature(void){
  char wbuf = {(char)0xa0+id,(char)0x04};
  fd._write(wbuf);
  fd._read(buf,5);
  return buf[4];
}

kondo_servo::~kondo_servo()
{
  fd.~file();
}
