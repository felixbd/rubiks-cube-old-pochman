##
# rubiks cube old pochman
#
# @file
# @version 0.1

all: compile test checkstyle

compile:
	# compile all files
	g++ -c rubiks-cube.cc
	g++ -c rubiks-cube-test.cc
	g++ -c main.cc

	# link compiled files
	g++ rubiks-cube.o main.o -o a.o
	g++ rubiks-cube.o rubiks-cube-test.o -l gtest -l pthread -o test.o

test: compile
	./test.o

checkstyle:
	python3 cpplint.py  --repository=. *.cc *.hh

run:
	./a.o

clean:
	rm -f *.o
	rm -f *.out

# end
