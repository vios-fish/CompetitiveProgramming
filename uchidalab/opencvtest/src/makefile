COMPILER = g++
TARGET = ../bin/$(shell basename `readlink -f ..`)
LIBS = `pkg-config --libs opencv`
INCLUDE = `pkg-config --cflags opencv`
CFLAGS = -O2 -g -MMD -MP -std=c++11
OBJDIR = ./obj
ifeq "$(strip $(OBJDIR))" ""
  OBJDIR = .
endif
SOURCES = $(wildcard *.cpp)
OBJECTS  = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
DEPENDS  = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS)
	$(COMPILER) -o $@ $< $(LIBS)

$(OBJDIR)/%.o: %.cpp
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(TARGET)
	@rmdir --ignore-fail-on-non-empty `readlink -f $(OBJDIR)`


-include $(DEPENDS)
