#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int randomNumber () {
    int fd = open("/dev/random", O_RDONLY);
    if (fd == 1) 
        printf("error: %s \n", errno, strerror(errno));
    int n; 
    read (fd,&n,4);
    return n;
}

void read_array(char* filename, int arr[10]) {
    int fd = open(filename, O_RDONLY);
    if (fd == 1) 
        printf("error: %s \n", errno, strerror(errno));
    read(fd,arr,4*10);
    cl = close(fd);
    if (cl == 1) 
        printf("error: %s \n", errno, strerror(errno));
    return;
}

void write_array(char*filename, int arr[10]) {
    int fd = open(filename, O_WRONLY|O_CREAT); 
    if (fd == 1) 
        printf("error: %s \n", errno, strerror(errno));
    write(fd,arr,4*10);
    cl = close(fd);
    if (cl == 1) 
        printf("error: %s \n", errno, strerror(errno));
    return;
}

int main() {
    int random[10];
    int n;
    printf("Generating random numbers: \n");
    for (n=0;n<10;n++) {
        random[n] = randomNumber();
        printf("Random %d: %d\n",n,random[n]);
    }
    printf("\n");

    printf("Writing numbers to file... \n\n");
    write_array("createdfile",random);
    
    int testarray[10]; 

    printf("Reading numbers from file... \n\n");
    read_array("createdfile",testarray);
    
    printf("Verification that written values were the same: \n");
    for (n=0;n<10;n++) {
        printf("New Array %d: %d\n",n,testarray[n]);
    }
}