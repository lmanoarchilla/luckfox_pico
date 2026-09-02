#C compiler
#
# Full path to the cross-compiler (use this if the toolchain is not in PATH).
# CC := /path/to/toolchain/bin/arm-rockchip830-linux-uclibcgnueabihf-gcc
CROSS_COMPILE ?= arm-rockchip830-linux-uclibcgnueabihf-

CC := $(CROSS_COMPILE)gcc
CFLAGS := -Wall -O2

#Target:dependency
hello: hello.c

# Example of the equivalent cross-compilation command:
# /path/to/toolchain/bin/arm-rockchip830-linux-uclibcgnueabihf-gcc hello.c -o hello
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f hello

.PHONY: clean