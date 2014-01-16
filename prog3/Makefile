all: bookListDriver hashDriver List.DR bookrec

bookListDriver: bookListDriver.c booklist.c booklist.h List.c List.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o bookListDriver bookListDriver.c booklist.c booklist.h List.c List.h

hashDriver: hashDriver.c booklist.c booklist.h List.c List.h hash.c hash.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o hashDriver hashDriver.c booklist.c booklist.h List.c List.h hash.c hash.h

List.DR: List.DR.c List.c List.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o List.DR List.DR.c List.c List.h

bookrec: bookrec.c List.c List.h booklist.c booklist.h hash.c hash.h
	gcc -g -O0 -Wall -Wextra -std=gnu99 -o bookrec bookrec.c List.c List.h booklist.c booklist.h hash.c hash.h

