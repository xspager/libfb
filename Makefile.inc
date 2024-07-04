#CC		= diet gcc	
CC		= gcc
PRJCFLAGS	= -g
#LD		= diet gcc
LD		= ld
LDFLAGS	=
AR		= ar
ARFLAGS	=
RANLIB	= ranlib
RM		= rm
ECHO	= echo

SHELL	= /bin/sh

LIBFB	= ../libfb.a
#CFLAGS	= -ggdb -mtune=native -pipe -O3 -I../../include/
CFLAGS	= -mtune=native -Wall -pipe -O0 -I $(INCLUDE_DIR) -ggdb -Wall -Wpedantic

.SILENT :
