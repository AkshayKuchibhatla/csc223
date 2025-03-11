CC=g++
STD=c++11

default:
	clear
	@make clean
	@make test

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	@$(CC) -c -o $@ $< -std=$(STD)

build/%: build/%.o
	$(CC) -o $@ $^ -std=$(STD)

.PHONY: test clean doubleTest orderedTest

test: build/testLL
	@./build/testLL

doubleTest: build/testDLL
	@./build/testDLL

orderedTest: build/testOLL
	@./build/testOLL

clean:
	@rm -rf build

# When doctest not found (for macs): export CPLUS_INCLUDE_PATH=/opt/homebrew/include/doctest