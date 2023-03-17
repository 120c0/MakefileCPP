define main =
$(info > Makefile: 1.5.0 - Author: https://github.com/Xnork/MakefileCPP)
	$(info > Build type: $(BUILD_TYPE))
	$(info > Target version: $(TARGET_VERSION))
endef

STRIP = strip -g -S -d --strip-debug
ifeq ($(BUILD_TYPE),Release)
	CFLAGS += -O3 -s -DNDEBUG
else
	CFLAGS += -g -ggdb -O0
endif
