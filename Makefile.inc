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
<<<<<<< HEAD
#CFLAGS	= -ggdb -mtune=native -pipe
CFLAGS	= -ggdb -mtune=cortex-a8
=======
CFLAGS = -ggdb
#CFLAGS	= -ggdb -mtune=native -pipe
#CFLAGS	= -ggdb -mtune=cortex-a8
>>>>>>> 21575e2eb18d01d2acc103850bef0f007a87542d

.SILENT :
