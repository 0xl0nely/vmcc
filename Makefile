build: ./src/*.cpp
	mkdir build
	g++ ./src/*.cpp -o ./build/vmcc -O2 -D_FORTIFY_SOURCE=2  -Wall
	strip -s build/vmcc
install:
	cp ./build/vmcc /opt
	ln -s /opt/vmcc /usr/bin
clean:
	rm -r build
