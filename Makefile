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

all: dir $(SOURCES) $(BIN)$(EXECUTABLE)

dir:
	mkdir $(BIN)
	mkdir $($OBJ) $($OBJ)cmd

$(BIN)$(EXECUTABLE): $(OBJECTS)

	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ)%.o: $(SRC)%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)cmd/*.o $(OBJ)*.o $(BIN)*
