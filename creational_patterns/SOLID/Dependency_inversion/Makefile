# Set target to your .cpp file name
TARGET?=CREATIONAL_dip
CPPFLAGS=
CXXFLAGS=-std=c++17
LDFLAGS=

all: $(TARGET)

$(TARGET): $(TARGET).o
	g++ $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(TARGET).o: $(TARGET).cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
