CXXFLAGS += -MMD -std=c++11 -g

SRC = $(wildcard *.cpp)
OBJ = $(SRC:.cpp=.o)
EXEC = tree

.PHONY:clean

all:test

$(EXEC):$(OBJ)
	$(CXX) $(LDFLAGS) -o $@ $(OBJ)

test:$(EXEC)
	./$(EXEC)

-include *.d

.cpp.o:
	$(CXX) $(CXXFLAGS) -c $<

clean:
	rm  -f *.o $(EXEC) *.d
