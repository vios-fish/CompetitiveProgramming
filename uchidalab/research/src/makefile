COMPILER = g++
TARGET = ../bin/$(shell basename `readlink -f ..`)
LIBS = `pkg-config --libs opencv` \
	/usr/local/Cellar/glpk/4.52/lib/libglpk.dylib \
	/usr/local/Cellar/glpk/4.52/lib/libglpk.a
INCLUDE = `pkg-config --cflags opencv` -I/usr/local/Cellar/glpk/4.52/include
CFLAGS = -O2 -g -MMD -MP -std=c++11
OBJDIR = ./obj
ifeq "$(strip $(OBJDIR))" ""
  OBJDIR = .
endif
SOURCES = $(wildcard *.cpp)
OBJECTS  = $(addprefix $(OBJDIR)/, $(SOURCES:.cpp=.o))
DEPENDS  = $(OBJECTS:.o=.d)

$(TARGET): $(OBJECTS)
	$(COMPILER) -o $@ $(OBJECTS) $(LIBS)

echo: $(OBJECTS)
	echo $(OBJECTS)

$(OBJDIR)/%.o: %.cpp
	@[ -d $(OBJDIR) ] || mkdir -p $(OBJDIR)
	$(COMPILER) $(CFLAGS) $(INCLUDE) -o $@ -c $<

all: clean $(TARGET)

clean:
	rm -f $(OBJECTS) $(DEPENDS) $(TARGET)
	@rmdir --ignore-fail-on-non-empty `readlink -f $(OBJDIR)`


-include $(DEPENDS)
