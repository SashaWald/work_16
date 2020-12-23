#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

int main(){
    printf("Mod by 10: ");
    mkfifo("my_pipe",0666);
    int input;
    int result;
    int size = sizeof(input);
    while(1){
        int fd, fd2;
        
        fd = open("my_pipe",O_WRONLY);
        scanf("%d",&input);
        write(fd,&input,size);
        close(fd);
        
        fd2 = open("my_pipe",O_RDONLY);
        read(fd,&result,sizeof(result));
        printf("Result: %d\n",result);
    }
    return(0);
}