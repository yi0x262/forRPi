servo_local: main_kondo.o kondo_servo.o file_descriptor.o
	g++ -o servo_local main_kondo.o kondo_servo.o file_descriptor.o -std=c++11

cpp.o:
	g++ -c $< -std=c++11
