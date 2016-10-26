SRC=src/
OBJ=obj/
BIN=bin/
INC=inc/

CC=g++
CFLAGS= -Wall -O2 -I$(INC)
LDFLAGS=

SOURCES= $(wildcard $(SRC)*.cpp) $(wildcard $(SRC)*/*.cpp)
# OBJECTS = $(SOURCES: .cpp=.o)
OBJECTS=$(patsubst $(SRC)%.cpp,$(OBJ)%.o, $(SOURCES))
EXECUTABLE=remember

all: $(SOURCES) $(BIN)$(EXECUTABLE)

$(BIN)$(EXECUTABLE): $(OBJECTS)
	echo $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ)%.o: $(SRC)%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm $(OBJ)* $(BIN)*

test:
	echo $(patsubst %.cpp, %.o, $(SOURCES))
