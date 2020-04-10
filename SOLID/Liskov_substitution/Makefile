# Set target to your .cpp file name
TARGET=CREATIONAL_lsp
CPPFLAGS=
CXXFLAGS=-std=c++11
LDFLAGS=

all: $(TARGET)

$(TARGET): $(TARGET).o
	g++ $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(TARGET).o: $(TARGET).cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
