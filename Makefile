# Compiler and flags
CC = clang
CFLAGS = -Wall -Werror -Iinclude

# Directories
SRCDIR = src
INCDIR = include
TESTDIR = tests
BUILDDIR = build

# Source files
SRC = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC))

# Test files
TESTSRC = $(wildcard $(TESTDIR)/*.c)
TESTOBJS = $(patsubst $(TESTDIR)/%.c,$(BUILDDIR)/%.o,$(TESTSRC))
TESTS = $(patsubst $(TESTDIR)/%.c,$(BUILDDIR)/%,$(TESTSRC))

# Targets
all: $(BUILDDIR) $(OBJS) $(TESTS)

$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILDDIR)/%: $(TESTDIR)/%.c $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

clean:
	rm -rf $(BUILDDIR)

.PHONY: all clean
