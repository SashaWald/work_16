#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
    int input;
    int size = sizeof(input);
    int result = 0;
    while(1){
        int fd, fd2;
        
        fd = open("my_pipe",O_RDONLY);
        read(fd,&input,size);
        close(fd);
        
        printf("Modding %d by 10\n",input);
        result = input%10;
        fd2=open("my_pipe",O_WRONLY);
        write(fd2,&result,sizeof(result));
        close(fd2);
    }
    return(0);
}