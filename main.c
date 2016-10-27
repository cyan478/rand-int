#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

//============================================================== errno msg
void checkErr(int err){
    if (err < 0)
        printf("error: %d - %s \n", errno, strerror(errno));
    return;
}
//============================================================== gen a rand #
int randomNumber () {
    int fd = open("/dev/random", O_RDONLY);
    checkErr(fd);
    int n; 
    read (fd,&n,4);
    return n;
}
//============================================================== read 
void read_array(char* filename, int arr[10]) {
    int fd = open(filename, O_RDONLY);
    checkErr(fd);
    read(fd,arr,4*10);
    int cl = close(fd);
    checkErr(cl);
    return;
}
//============================================================== write
void write_array(char*filename, int arr[10]) {
    int fd = open(filename, O_WRONLY|O_CREAT); 
    checkErr(fd);
    write(fd,arr,4*10);
    int cl = close(fd);
    checkErr(cl);
    return;
}
//============================================================== main
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