MKFILE		= Makefile

GCC		= gcc -g -O0 -Wall -Wextra -std=gnu99

CHEADER		= List.h
CSOURCE1	= store.c List.c
CSOURCE2	= List.DR.c List.c
OBJECTS1	= ${CSOURCE1:.c=.o}
OBJECTS2	= ${CSOURCE2:.c=.o}
EXECBIN1	= store
EXECBIN2	= List.DR

all : ${EXECBIN1} ${EXECBIN2}

${EXECBIN1} : ${OBJECTS1}
	${GCC} -o $@ ${OBJECTS1}

${EXECBIN2} : ${OBJECTS2}
	${GCC} -o $@ ${OBJECTS2}

%.o : %.c
	${GCC} -c $<
