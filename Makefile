build: ./src/*.cpp
	mkdir build
	g++ ./src/*.cpp -o ./build/vmcc
install:
	cp ./build/vmcc /opt
	ln -s /opt/vmcc /usr/bin
clean:
	rm -r build
