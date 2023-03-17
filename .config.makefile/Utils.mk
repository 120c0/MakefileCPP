TARGET = Executable

EXTENSION = cpp
COMPILER = g++
BUILD_TYPE = Debug

SOURCE_DIR = src
HEADER_DIR = -Iinclude
OBJECT_DIR = .bin.obj

CFLAGS = -Wall -Wextra $(HEADER_DIR)

RM = del /Q
MKDIR =
MV = mov
ifeq ($(shell uname),Linux)
	RM = rm -f
	MV = mv
	MKDIR = mkdir -p
endif
