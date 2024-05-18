SRC 	:= ./src/alphabetized.cpp ./src/circularShift.cpp ./src/input.cpp ./src/output.cpp main.cpp

.PHONY : test-build clean build
.DEFAULT_GOAL : build

build:
	g++ -I./include -o ./build/main $(SRC)
run: build
	./build/main
test-build:
	g++ -I./include -DMOJOTEST -o ./build/test $(SRC)

clean:
	rm ./build/main ./build/test
