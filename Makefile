# === Configuration ===

# Final executable name
TARGET = bin/wine_catalog

# Compiler and flag
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -std=c99

# Sources
SRCDIR = src
INCDIR = include
BUILDDIR = build
BINDIR = bin

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC))

# === Rules ===

# Principal rule
all: $(TARGET)

# Objects link -> executable
$(TARGET): $(OBJ)
	@mkdir -p $(BINDIR)
	$(CC) $(OBJ) -o $@
	@echo "✅ Compilato con successo: $(TARGET)"

# Compiling of .c -> .o
$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	rm -rf $(BUILDDIR) $(BINDIR)

# Deep cleaning (also temp files)
distclean: clean

# Debug (printing used files)
print:
	@echo "SRC: $(SRC)"
	@echo "OBJ: $(OBJ)"
