# the compiler to use.
COMPILER = g++

# include path
INCLUDE = include/

# program souce files
SOURCES = source/marketzilla/*.cpp

# test source files
TEST_SOURCES = test/marketzilla/*.cpp

# depencences
LIBS = lgtest

# options I'll pass to the compiler.
FLAGS = $(INCLUDE) $(LIBS)

# executable name
EXECUTABLE = marketzilla

all: test

test: $(SOURCES) $(TEST_SOURCES)
	$(COMPILER) -o $(EXECUTABLE) $(SOURCES) $(TEST_SOURCES) -I$(INCLUDE) -$(LIBS)
	./$(EXECUTABLE)

clean:
	rm -rf *.o $(EXECUTABLE)