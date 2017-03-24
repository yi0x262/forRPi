class file_descriptor
{
  int fd;//file discriptor
  int _read(char buf[],int size)const;
  int _write(const char buf[])const;
public:
  file_descriptor(const char* device);
  virtual ~file_descriptor();
};
