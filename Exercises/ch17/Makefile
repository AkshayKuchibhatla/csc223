CC=g++
STD=c++11

build/%.o: src/%.cpp
	@mkdir -p build
	@$(CC) -MM -MT $@ $< > build/$*.d
	@$(CC) -c -o $@ $< -std=$(STD)

build/testLL: build/testLL.o
	$(CC) -o $@ $^ -std=$(STD)

.PHONY: test clean

test: build/testLL
	@./build/testLL

clean:
	@rm -rf build