TARGET=CREATIONAL_srp
CPPFLAGS=
CXXFLAGS=-std=c++11 -I$(BOOST_ROOT)/boost
LDFLAGS=

all: $(TARGET)

$(TARGET): $(TARGET).o
	g++ $(CXXFLAGS) $< -o $@ $(LDFLAGS)

$(TARGET).o: $(TARGET).cpp
	g++ $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf *.o $(TARGET)
