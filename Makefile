include .config.makefile/Utils.mk
include .config.makefile/Main.mk

TARGET_VERSION = 0.0.1
LIBRARY_LINK +=
HEADER_DIR += 
CFLAGS +=

SOURCE_FILES = $(wildcard $(SOURCE_DIR)/*.$(EXTENSION))
OBJECT_FILES = $(patsubst $(SOURCE_DIR)/%.$(EXTENSION),\
	$(OBJECT_DIR)/%.o,$(SOURCE_FILES))

all: $(call main) $(TARGET)

$(TARGET): $(OBJECT_FILES)
	@$(COMPILER) $^ -o $@ $(LIBRARY_LINK) $(CFLAGS)
ifeq ($(BUILD_TYPE),Release)
	@$(STRIP) $@
endif
	$(info [$(COMPILER)] Generate executable...)

$(OBJECT_DIR)/%.o: $(SOURCE_DIR)/%.$(EXTENSION)
	@mkdir -p $(OBJECT_DIR)
	@$(COMPILER) -c $< -o $@ $(CFLAGS)
ifeq ($(BUILD_TYPE),Release)
	@$(STRIP) $@
endif
	$(info [$(COMPILER)] $< -> $@...)

clean:
	@$(RM) $(OBJECT_FILES) $(TARGET)
	$(info [$(RM)] Removing objects and executable...)
