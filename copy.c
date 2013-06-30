#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

char buffer[2048];
int version = 1;

void copy(int fold, int fnew);

int main(int argc, char *argv[]) {
    int fold,fnew;

    if(argc !=3 ) {
        printf("Need 2 arguments for copy program\n");
        exit(1);
    }

    fold = open(argv[1], O_RDONLY); // open source file read only
    if(fold == -1) {
        printf("cannot open file %s\n", argv[1]);
        exit(1);
    }

    fnew = creat(argv[2], 0666); // create target file rw for all
    if(fnew == -1) {
        printf("cannot create file %s\n", argv[2]);
        exit(1);
    }
    copy(fold, fnew);
    return 0;
}

void copy(int fold, int fnew) {
    int count;
    while((count = read(fold, buffer, sizeof(buffer))) > 0)
        write(fnew, buffer, count);
}
