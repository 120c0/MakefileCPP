include config/utils.mk
include config/main.mk

INCLUDES += 
LIBS += 
BUILD_FLAGS += 
TARGET = App

	
all: $(call main) $(OBJECTS) $(TARGET) 

$(TARGET): $(OBJECTS)
	@$(COMPILER) -o $@ $^ $(LIBS)
	$(info [+] Linking executable...)

%.o: %.$(EXTENSION_FILE)
	@$(COMPILER) -c -o $@ $< $(BUILD_FLAGS)
	$(info [$(COMPILER)] $< ==> $@...)
	
clean:
	$(info Cleaning...)
	@$(RM) $(OBJECTS) $(TARGET)
	$(info Done!)

