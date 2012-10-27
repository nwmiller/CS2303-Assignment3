ctest: ctest.o mystring.o user.o rand_funcs.o
	gcc ctest.o mystring.o user.o rand_funcs.o -o ctest

ctest.o: ctest.c mystring.h user.h rand_funcs.h
	gcc -g -c ctest.c

mystring.o: mystring.c mystring.h
	gcc -g -c mystring.c

user.o: user.c user.h
	gcc -g -c user.c

rand_funcs.o: rand_funcs.c rand_funcs.h
	gcc -g -c rand_funcs.c

docs: 
	doxygen
	chmod go+r html/*
	cp -p html/* ~/public_html/assig3

clean:
	rm -f *~
	rm -f *.o
	rm -r ctest

