CPP = g++
CPPFLAGS = -g

INCLUDE := src
SOURCE := $(wildcard src/*.cpp)
TEST_SOURCE := $(wildcard test/*.cpp)

OBJ := $(addprefix build/obj/, $(notdir $(SOURCE:.cpp=.o)))
TEST_OBJ := $(addprefix build/test_obj/, $(notdir $(TEST_SOURCE:.cpp=.o)))

EXE := build/run_program
TEST_EXE := build/run_test

all: $(EXE)

run: $(EXE)
	./$(EXE)

test: $(TEST_EXE)
	./$(TEST_EXE)

$(TEST_EXE): build $(OBJ) $(TEST_OBJ)
	$(CPP) $(CPPFLAGS) -o $(TEST_EXE) $(filter-out build/obj/program.o, $(OBJ)) $(TEST_OBJ)

$(EXE): build $(OBJ)
	$(CPP) $(CPPFLAGS) -o $(EXE) $(OBJ)

build/obj/%.o: src/%.cpp
	$(CPP) $(CPPFLAGS) -I$(INCLUDE) -c -o $@ $<

build/test_obj/%.o: test/%.cpp
	$(CPP) $(CPPFLAGS) -I$(INCLUDE) -c -o $@ $<

.PHONY: clean
clean:
	@if [ -d "build" ]; then rm -rf build; fi

.PHONY: build
build:
	@if [ ! -d "build" ]; then mkdir build && mkdir build/obj && mkdir build/test_obj; fi
