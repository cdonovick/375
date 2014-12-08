CC=g++
CFLAGS=-c -std=c++11 -Wall -Wextra -ggdb
LDFLAGS=
SOURCES=$(wildcard *.cpp)
OBJECTS=$(patsubst %.cpp, %.o, $(SOURCES))
EXECUTABLE=submission
	
all: $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) -o $@ $^
	
$(OBJECTS): $(SOURCES)
	$(CC) $(CFLAGS) $^

clean:
	rm -rf $(OBJECTS) $(EXECUTABLE) *.*~

