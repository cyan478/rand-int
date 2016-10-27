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

void read_array(char* filename, int arr[10]) {
    int fd = open(filename, O_RDONLY);
    read(fd,arr,4*10);
    close(fd);
    return;
}

void write_array(char*filename, int arr[10]) {
    int fd = open(filename, O_WRONLY|O_CREAT); 
    write(fd,arr,4*10);
    close(fd);
    return;
}

int main() {
    int random[10];
    int n;
    for (n=0;n<10;n++) {
        random[n] = randomNumber();
        printf("Random %d: %d\n",n,random[n]);
    }
    
    write_array("test",random);
    
    int testarray[10]; 
    
    read_array("test",testarray);
    
    for (n=0;n<10;n++) {
        printf("New Array %d: %d\n",n,testarray[n]);
    }
}