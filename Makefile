# the compiler to use.
COMPILER=clang++

# include path
INCLUDE=include/

SOURCES=source/marketzilla/*.cpp

TEST_SOURCES=test/marketzilla/*.cpp

# options I'll pass to the compiler.
FLAGS=-I$(INCLUDE)

# executable name
EXECUTABLE=marketzilla

all: test

test: $(SOURCES) $(TEST_SOURCES)
	$(COMPILER) $(FLAGS) $(SOURCES) $(TEST_SOURCES) -o $(EXECUTABLE)

clean:
	rm -rf *.o $(EXECUTABLE)