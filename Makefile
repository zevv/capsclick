
BIN   	= ctrlclick
SRC 	= ctrlclick.c

PKG	+=
CFLAGS  += -Wall -O3 -g 
LDFLAGS += -g -lX11 -lxdo

CFLAGS	+= $(shell pkg-config --cflags $(PKG))
LDFLAGS	+= $(shell pkg-config --libs $(PKG))

CROSS	=
OBJS    = $(subst .c,.o, $(SRC))
CC 	= $(CROSS)gcc
LD 	= $(CROSS)gcc

.c.o:
	$(CC) $(CFLAGS) -c $<

$(BIN):	$(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

clean:	
	rm -f $(OBJS) $(BIN) core
	
