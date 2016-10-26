#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int randomNumber () {
    int fd = open("/dev/random", O_RDONLY);
    int n; 
    read (fd,&n,4);
    return n;
}

int main() {
    int random[10];
    int n;
    for (n=0;n<10;n++) {
        random[n] = randomNumber();
        printf("Random %d: %d\n",n,random[n]);
    }
}