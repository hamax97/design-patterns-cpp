# Set target to your .cpp file name
TARGET?=
CPPFLAGS=
CXXFLAGS=-std=c++17 #-I$(BOOST_ROOT)/boost
LDFLAGS=
CXX=clang++

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(TARGET).o: $(TARGET).cpp
	$(CXX) $(OTHER_FLAGS) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
