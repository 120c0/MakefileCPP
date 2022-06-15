TARGET = ../libImGui.a

CPPFILES = $(shell find . -type f -name \*.cpp)
OBJECTS = $(CPPFILES:%.cpp=%.o)
CPPFLAGS = -Wall $(shell sdl2-config --cflags) -I. -I/usr/include/freetype2
LIBS = $(shell sdl2-config --libs)
AR = ar
BUILD = debug

ifeq ($(BUILD),debug)
	CPPFLAGS += -O0 -g
else ifeq ($(BUILD),release)
	CPPFLAGS += -O3 -s DNDEBUG
else
	$(error Build type $(END) error.)
	@exit 1
endif

all: $(OBJECTS) $(TARGET)

%.o: %.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS)
$(TARGET): $(OBJECTS)
	$(AR) r $@ $^
clean:
	@rm -rf $(OBJECTS) $(TARGET)
