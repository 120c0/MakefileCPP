TARGET_VERSION = 0.0.1
TARGET = App
BIN = .obj
SOURCE_DIR = src

CPPFILES = $(shell find $(SOURCE_DIR) -type f -iname *.cpp)
OBJECTS = $(patsubst %,$(BIN)/%, $(notdir $(CPPFILES:%.cpp=%.o)))
INCLUDES = -Iinclude
CPPFLAGS = -Wall -Werror -Wextra $(INCLUDES)
LIBS =
BUILD = debug

ifeq ($(BUILD),debug)
	CPPFLAGS += -O0 -g
else ifeq ($(BUILD),release)
	CPPFLAGS += -O3 -s DNDEBUG
else
	$(error Build type $(END) error.)
	@exit 1
endif

$(info ---- Makefile++ 1.0.0 ----)
$(info Build Type: $(BUILD))
$(info Target version: $(TARGET_VERSION))

all: $(OBJECTS) $(TARGET)
.PHONY: all
$(OBJECTS): $(BIN)/%.o: $(SOURCE_DIR)/%.cpp
	$(CXX) -c -o $@ $< $(CPPFLAGS)
$(TARGET): $(OBJECTS)
	$(CXX) -o $@ $^ $(LIBS)
clean:
	@rm $(OBJECTS) $(TARGET)
deps:
	$(MAKE) -C lib/ImGui
clean_deps:
	$(MAKE) -C lib/ImGui clean
setup:
	@mkdir -p .obj data tests lib
