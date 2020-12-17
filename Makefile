# Set directories
SRC=./src
INC=./include
BUILD=./build
LIB=./lib

# Standard tools
CXX=g++
AR=ar

# Flags
CXXFLAGS=-fPIC
ARFLAGS=rv
LDFLAGS=-shared -rdynamic

# Source files
SOURCES = Higgs_CEPC.cpp xLike.cpp

# Object files derived from sources
OBJ = $(patsubst %.cpp,$(BUILD)/%.o,$(SOURCES)) 

all: $(LIB)/xLike.a $(LIB)/xLike.so 

$(BUILD)/%.o: $(SRC)/%.cpp $(INC)/Higgs_CEPC.hpp 
	$(CXX) -I $(INC) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

$(LIB)/xLike.a: $(OBJ)
	$(AR) $(ARFLAGS) $@ $^

$(LIB)/xLike.so: $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(LDFLAGS) $^ 


xLike.x: $(OBJ) $(BUILD)/xLike.o
	$(CXX) $(CXXFLAGS) -o $@ $^ -I $(INC) $(LIB)/xLike.so

.PHONY: clean
clean:
	rm -f $(BUILD)/*.o
	rm -f $(LIB)/*.o
	rm -f $(BUILD)/*.so
	rm -f $(LIB)/*.so
	rm -f $(BUILD)/*.a
	rm -f $(LIB)/*.a
	rm -f xLike.x

$(shell mkdir -p $(BUILD))
$(shell mkdir -p $(LIB))
