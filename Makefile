all:
	g++ func.cpp square.cpp -o square.exe

test:
	g++ func.cpp test.cpp -o test.exe
