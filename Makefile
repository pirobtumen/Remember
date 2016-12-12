SRC=src/
OBJ=obj/
BIN=bin/
INC=inc/

CC=g++
CFLAGS= -Wall -O2 -I$(INC) -std=c++11
LDFLAGS= `pkg-config gtkmm-3.0 --cflags --libs`

HEADERS= $(wildcard $(INC)*.hpp) $(wildcard $(INC)*/*.hpp)
SOURCES= $(wildcard $(SRC)*.cpp) $(wildcard $(SRC)*/*.cpp)
# OBJECTS = $(SOURCES: .cpp=.o)
OBJECTS=$(patsubst $(SRC)%.cpp,$(OBJ)%.o, $(SOURCES))
EXECUTABLE=remember

all: dir $(SOURCES) $(BIN)$(EXECUTABLE)

dir:
	mkdir -p $(BIN)
	mkdir -p $(OBJ) $(OBJ)cmd $(OBJ)gui

$(BIN)$(EXECUTABLE): $(OBJECTS) $(HEADERS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

$(OBJ)%.o: $(SRC)%.cpp
	$(CC) -c $(CFLAGS) $< -o $@ $(LDFLAGS)

install:
	mkdir -p ~/.local/bin
	cp bin/$(EXECUTABLE) ~/.local/bin/$(EXECUTABLE)

clean:
	rm -f $(OBJ)gui/*.o $(OBJ)cmd/*.o $(OBJ)*.o $(BIN)*
