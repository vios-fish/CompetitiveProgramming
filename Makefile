CC	= g++
CFLAGS	= -Wall
INCLUDES = .
# SRC	= $(shell find . -type f -mmin -30 -regex ".*.cpp")

check-syntax:
	$(CC) -o nul $(CFLAGS) $(INCLUDES) -S ${CHK_SOURCES}
