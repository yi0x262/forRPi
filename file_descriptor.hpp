class file
{
protected:
  const int descriptor=-1;
public:
  file(const char* device);
  ~file();
  int _write(const char buf[])const;
  int _read(char buf[],unsigned size)const;
};
