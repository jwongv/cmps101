all: heapDriver sortPrint sortComp

heapDriver: heapDriver.c heap.c heap.h heapSort.c heapSort.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o heapDriver heapDriver.c heap.c heap.h heapSort.c heapSort.h

sortPrint: sortPrint.c insertionSort.c insertionSort.h heap.c heap.h heapSort.c heapSort.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o sortPrint sortPrint.c heap.c heap.h insertionSort.c insertionSort.h heapSort.c heapSort.h

sortComp: sortComp.c insertionSort.c insertionSort.h heap.c heap.h heapSort.c heapSort.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o sortComp sortComp.c heap.c heap.h insertionSort.c insertionSort.h heapSort.c heapSort.h
