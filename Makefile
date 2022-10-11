##
# rubiks cube old pochman
#
# @file
# @version 0.1

all: compile test checkstyle

compile:
	# g++ rubiks-cube-test.cc -o rubiks-cube-test.o -lgtest -lpthread
	g++ rubiks-cube.cc -o rubiks-cube.o

test: compile
	# ./rubiks-cube-test.o

checkstyle:
	python3 cpplint.py  --repository=. *.cc *.hh

run:
	./rubiks-cube.o

clean:
	rm -f *.o

# end
