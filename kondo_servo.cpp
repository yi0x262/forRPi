#include"kondo_servo.hpp"

kondo_servo::kondo_servo(const int servo_id):
  fd(file("/dev/ttyAMA0")),id(servo_id){}

unsigned short kondo_servo::rotate(unsigned short target_angle)
{
  char buf[6];
  fd._write({(char)0x80+id,(char)(target_angle>>7)&0x7f,(char)target_angle&0x7f});
  fd._read(buf,6);
  return static_cast<unsigned short>(buf[4])<<7 + static_cast<unsigned short>(buf[5]);
}

char kondo_servo::current(void){
  char buf[5];
  fd._write({(char)0xa0+id,(char)0x03});
  fd._read(buf,5);
  return buf[4];
}

char kondo_servo::temperature(void){
  char buf[5];
  fd._write({(char)0xa0+id,(char)0x04});
  fd._read(buf,5);
  return buf[4];
}

kondo_servo::~kondo_servo()
{
  fd.~file();
}
