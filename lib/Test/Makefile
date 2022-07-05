TARGET_VERSION = 0.0.1
TARGET = libTest.a

BIN_DIR = bin
SRC_DIR = src
SRC_FILES = $(shell find $(SRC_DIR) -type f -iname *.cpp)
OBJECTS = $(SRC_FILES:%.cpp=%.o)
INCLUDES = -Iinclude
LIBS =
BUILD_TYPE = release
CPP_FLAGS = -std=c++17 $(INCLUDES)
RM = @rm
Q = @
ECHO = @echo

ifeq ($(BUILD_TYPE),debug)
	CPP_FLAGS += -O0 -g
else ifeq ($(BUILD_TYPE),release)
	CPP_FLAGS += -O3 -s -DNDEBUG
else
	$(error Build type $(BUILD_TYPE) error.)
	@exit 1
endif

all: $(OBJECTS) $(TARGET)	
.PHONY: all

%.o: %.cpp
	$(ECHO) "\033[32mCompiling\033[0m[\033[33m$(notdir $@)\033[0m] \033[36m$(dir $<)\033[33m$(notdir $<)\033[0m..."
	$(Q)$(CXX) -c -o $@ $< $(CPP_FLAGS)
$(TARGET): $(OBJECTS)
	$(ECHO) "\033[32;1mBuilding lib\033[0m executable \033[33m$(TARGET)\033[0m..."
	$(Q)ar r $@ $^

clean:
	$(RM) $(OBJECTS) $(TARGET)
test:
	$(MAKE) -C $(TEST_DIR)
