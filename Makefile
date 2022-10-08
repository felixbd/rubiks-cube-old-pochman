##
# rubiks cube old pochman
#
# @file
# @version 0.1

all: compile test checkstyle

compile:
	c++ rubiks-cube.cc -o rubiks-cube.o

test:
	# ./test.o

checkstyle:
	python3 cpplint.py  --repository=. *.cc *.hh

clean:
	rm -f *.o

# end
