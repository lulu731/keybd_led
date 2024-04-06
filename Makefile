default:
	g++ -I. -I/usr/include/ -o build/kbdled main.cpp -L/usr/lib/x86_64-linux-gnu/ -lhidapi-hidraw