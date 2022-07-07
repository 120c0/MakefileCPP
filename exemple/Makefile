include config/utils.mk
include config/lib/lib.mk
include config/main.mk

SRC_FILES = $(wildcard $(SRC_DIR)/*.$(EXTENSION_FILE)) $(wildcard $(SRC_DIR)/*/*.$(EXTENSION_FILE))
OBJECTS = $(SRC_FILES:%.$(EXTENSION_FILE)=%.o)
INCLUDES = -I$(INCLUDE_DIR) $(shell pkg-config sdl2 --cflags) -I/opt/SDL/2.0.22/include
LIBS = -Llib $(shell pkg-config sdl2 --libs) -lSDL2_image
BUILD_TYPE = debug
TARGET_VERSION = 0.0.1
BUILD_FLAGS = -Wall -Werror -Wextra $(INCLUDES)

all: $(call main) $(OBJECTS) $(TARGET)
	
%.o: %.$(EXTENSION_FILE)
	@$(COMPILER) -c -o $@ $< $(BUILD_FLAGS)
	$(info [+] Compiling[$(notdir $@)] $(notdir $<)...)
$(TARGET): $(OBJECTS)
	@$(COMPILER) -o $@ $^ $(LIBS)
	$(info [+] Linking executable...)

clean:
	@$(RM) $(OBJECTS) $(TARGET)
	$(info Done!)
