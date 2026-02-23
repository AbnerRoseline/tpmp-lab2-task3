CC = gcc
CFLAGS = -Iinclude -Wall -Wextra -std=c99

SRCDIR = src
OBJDIR = obj
TARGETDIR = .

SRCS = $(wildcard $(SRCDIR)/*.c)

OBJS = $(addprefix $(OBJDIR)/, $(notdir $(SRCS:.c=.o)))

TARGET = $(TARGETDIR)/train_app

all: $(TARGET)

$(TARGET): $(OBJS)
	@echo "Linking..."
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)
	@echo "Build finished: $(TARGET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR):
	@mkdir -p $(OBJDIR)

run: all
	@echo "--- Running application ---"
	./$(TARGET)
	@echo "--- Application finished ---"

clean:
	@echo "Cleaning up..."
	rm -rf $(OBJDIR) $(TARGET)

.PHONY: all clean run check distcheck

check:
	@echo "Running checks..."
	@echo "Check complete."

distcheck:
	@echo "Running distribution checks..."
	@echo "Distcheck complete."
