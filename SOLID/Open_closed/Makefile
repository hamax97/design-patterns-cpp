CXX=clang++

TARGET=CREATIONAL_ocp_with_specification_pattern
CPPFLAGS=
CXXFLAGS=-std=c++11
LDFLAGS=

all: $(TARGET)

$(TARGET): $(TARGET).o
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(TARGET).o: $(TARGET).cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
