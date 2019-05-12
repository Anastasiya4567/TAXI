CC := g++ 
SRCDIR := src
BUILDDIR := build
TARGET := bin/Taxi
VAR := bin
SRCEXT := cpp
SOURCES := $(shell find $(SRCDIR) -type f -name *.$(SRCEXT))
OBJECTS := $(patsubst $(SRCDIR)/%,$(BUILDDIR)/%,$(SOURCES:.$(SRCEXT)=.o))
CFLAGS := -g -Wall -pedantic
INC := -I include

$(TARGET): $(OBJECTS)
	@mkdir -p $(VAR)
	$(CC) $^ -o $(TARGET)

$(BUILDDIR)/%.o: $(SRCDIR)/%.$(SRCEXT)
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(INC) -c -o $@ $<

clean:
	$(RM) -r -f $(BUILDDIR) $(VAR)

.PHONY: clean
