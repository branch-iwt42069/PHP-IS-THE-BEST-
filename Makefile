TEST_FLAG =$(CFLAGS) -L /usr/local/lib -l $(GOOGLE_TEST_LIB) -l pthread -o

GOOGLE_TEST_LIB = gtest

GOOGLE_TEST_INCLUDE = /usr/local/include

CPPTEST_FLAGS = -c -Wall -I $(GOOGLE_TEST_INCLUDE)

CFLAGS=-lstdc++ -lncursesw -g -Wall -Werror -Wextra

all: executable
	cd ./bin;./main.exe

executable: design functions main
	g++ obj/functions.o obj/design.o obj/main.o -o bin/main.exe $(CFLAGS)

design: src/design.cpp
	g++ src/design.cpp -c -o obj/design.o $(CFLAGS)

main: src/main.cpp
	g++ src/main.cpp -c -o obj/main.o $(CFLAGS)

functions: src/functions.cpp
	g++ src/functions.cpp -c -o obj/functions.o $(CFLAGS)

clean:
	rm -rf obj/*.o

test: design functions
	g++ $(CPPTEST_FLAGS) test/main.cpp -o test/main.o
	g++ $(CPPTEST_FLAGS) test/test.cpp -o test/test.o
	g++ test/main.o test/test.o obj/functions.o obj/design.o $(TEST_FLAG) bin/test.exe
	
runtest: 
	cd ./bin;./test.exe
	
	
