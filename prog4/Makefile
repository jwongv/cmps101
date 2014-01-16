all: listDriver direc graphDriver

listDriver: listDriver.c list.c list.h 
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o listDriver listDriver.c list.c list.h 

direc: direc.c list.c list.h graph.c graph.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o direc direc.c list.c list.h graph.c graph.h

graphDriver: graphDriver.c graph.c graph.h list.c list.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o graphDriver graphDriver.c graph.c graph.h list.c list.h





