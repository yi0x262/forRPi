#include<iostream>
using std::cout;
using std::endl;
#include<bitset>

#include<fcntl.h>
#include<sys/ioctl.h>
#include<unistd.h>
#include<linux/i2c-dev.h>//read,write

int main(){
  int fd;
  fd = open("/dev/i2c-1",O_RDWR);
  ioctl(fd,I2C_SLAVE,0x6a);

  //device setup
  unsigned char setup[2] = {(unsigned char)0x20,(unsigned char)0x0f};
  write(fd,setup,2);

  //routine
  unsigned char buf[1];
  unsigned char data[6];
  while(1){
    for(auto i : {0,1,2,3,4,5}){
      buf[0] = static_cast<unsigned char>(0x28+i);
      write(fd,buf,1);
      read(fd,buf,1);
      data[i] = buf[0];
      cout << std::bitset<8>(buf[0]) << " ";
      usleep(100000);
    }
    cout << endl;
  }
}
