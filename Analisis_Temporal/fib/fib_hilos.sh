#!/bin/sh
# sudo chmod 777 fib_hilos.sh
rm fib_hilos.txt
gcc fibhilos.c ../tiempo.c -o fibhilos -lpthread -lm
for i in  1000000 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000
do
    echo "Fibonacci search with threads, n = $i"
    ./fibhilos $i < ../../../10millones.txt >> fib_hilos.txt
done