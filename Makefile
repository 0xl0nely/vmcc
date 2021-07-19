all: src/*.cpp
	g++ -o main src/*.cpp -O2
	strip -s main
	upx -9 main
