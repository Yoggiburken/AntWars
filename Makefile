## Variables ##
CC=g++
CPPLIBS=-lsfml-graphics -lsfml-audio -lsfml-network -lsfml-window -lsfml-system

CPP_FILES := $(wildcard src/*.cpp)
OBJ_FILES := $(addprefix obj/,$(notdir $(CPP_FILES:.cpp=.o)))

src/AntWars: $(OBJ_FILES)
	g++ $(LD_FLAGS) -o $@ $^ $(CPPLIBS)
 
obj/%.o: src/%.cpp
	g++ -c -o $@ $<

clean:
	rm $(OBJ_FILES) src/AntWars
