
CC=gcc
OPTIMIZER=-g -m32
WARNINGS= -Wall -pedantic -Wno-implicit-function-declaration 
#WARNINGS= -Wall -pedantic -Wextra

CPPFLAGS= $(WARNINGS) $(OPTIMIZER)

INCLUDES=
#INCLUDES= -I/usr/include/linux/
LIBRARIES=

CC_SRC = dropcaches.c

#TARGET = ${CC_SRC:.c=}
TARGET = purge
OUTPUT = bin
BUILDDIR = build

deps depend:
	mkdir -p $(OUTPUT)
	mkdir -p $(BUILDDIR)
	$(CC) $(INCLUDES) $(LIBRARIES) $(CPPFLAGS) -o $(BUILDDIR)/$(TARGET) $(CC_SRC)

make: deps

install: make
	cp $(BUILDDIR)/$(TARGET) $(OUTPUT)
	sudo chown root:root  $(OUTPUT)/$(TARGET)
	sudo chmod 4755 $(OUTPUT)/$(TARGET)

clean:
	rm -rf $(BUILDDIR)
	rm -rf $(OUTPUT)
	#find $(BUILDDIR) -type f -exec unlink '{}' \;

