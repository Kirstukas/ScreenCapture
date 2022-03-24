BIN := scrcap

CC ?= gcc
AR ?= ar
CFLAGS := -lgdi32 -O2

build: $(BIN)
	@echo Target build!

$(BIN): $(patsubst %.c, %.o, $(shell find src/ -name "*.c"))
	$(AR) rc lib$@.a $^
	$(CC) $^ -o lib$@.dll -shared $(CFLAGS)

clean: $(addsuffix .DELETE, $(shell find src/ -name "*.o"))
	rm lib$(BIN).a
	rm lib$(BIN).dll
	@echo Cleaned!

%.o: %.c
	$(CC) -c $< -o $@ $(CFLAGS)

%.DELETE:
	rm $(patsubst %.DELETE, %, $@)
