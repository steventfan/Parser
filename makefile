$(shell mkdir -p bin)

CC = g++
CCFLAGS = -Wall -Werror -Wextra -pedantic
EXEC = bin/test
SOURCES = $(wildcard src/*.cpp)
OBJECTS = $(SOURCES:.cpp=.o)

$(EXEC):$(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

%.o:%.cpp
	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -rfv bin
	rm -rfv $(EXEC) $(OBJECTS)