cd ../cmathematics
gcc -g -o ../test/a.exe main.c vec.c matrix.c BigInt.c
cd ../test
gdb a.exe