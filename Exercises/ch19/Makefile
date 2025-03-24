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

build/testEval: build/testEval.o build/Evaluator.o
	@$(CC) -o $@ $^ -std=$(STD)

.PHONY: test clean includeDoctest

test: build/test_RGTPQ
	@./build/test_RGTPQ

clean:
	@rm -rf build

# To include doctest on mac: export CPLUS_INCLUDE_PATH=/opt/homebrew/include/doctest