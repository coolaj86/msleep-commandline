CFLAGS = -Wall -Werror -O2
LDFLAGS = 
CC=gcc ${CFLAGS} ${LDFLAGS}

all: usleep msleep

usleep:
	${CC} -o usleep usleep.c

msleep: usleep
	ln -s usleep msleep

install:
	@mkdir -p /usr/local/bin
	cp -a usleep msleep /usr/local/bin

.PHONY: all install
