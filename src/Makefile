#Makefile

CXXFLAGS = -std=c++11

all: module install
	
module:
	scons

install:
	sudo apxs -i -n cpp_hello mod_cpp_hello.so
	
clean:
	scons -c
	
