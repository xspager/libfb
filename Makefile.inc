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

LIBFB	= ../lib/libfb.o
CFLAGS	= -ggdb
#CFLAGS	= -ggdb -mtune=cortex-a8

.SILENT :
