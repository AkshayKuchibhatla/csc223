CC=g++
STD=c++11

default:
	@make clean
	@make doubleTest

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	@$(CC) -c -o $@ $< -std=$(STD)

build/%: build/%.o
	$(CC) -o $@ $^ -std=$(STD)

.PHONY: test clean doubleTest

test: build/testLL
	@./build/testLL

doubleTest: build/testDLL
	@./build/testDLL

clean:
	@rm -rf build