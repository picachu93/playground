#!/bin/bash

ulimit -S -t 10
ulimit -S -m 64000
ulimit -S -v 64000

make
cp playground testcases/
cd testcases/

mkdir -p auto_tests

for i in {1..15}
do
	echo "Testing input "$i"..."
	#time ./playground < input$i.txt > auto_tests/output$i.txt
	/usr/bin/time -f "%E elapsed, %U user, %S system, %Mk memory, %x status" ./playfround < input$i.txt > auto_tests/output$i.txt
	if (diff auto_tests/output$i.txt output$i.txt)
	   then
	    printf "\e[1;92mSame :)\e[0m\n"
           else
            printf "\e[1;91mDifferent :(\e[0m\n"
	fi
done

rm -rf auto_tests
rm playground

cd ..
make clean	 
