SRC 	:= ./src/alphabetizer.cpp ./src/line.cpp ./src/lineStorage.cpp ./src/circularShifter.cpp main.cpp

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
