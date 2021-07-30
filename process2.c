#include<stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>        
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>

int *count;

char  str;

int main()
{
    
    int shm;
    int i = 1;


    shm = shm_open("/sharedMemory", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR );


    ftruncate(shm,sizeof(int));


    count = (int *)mmap(NULL,sizeof(int),PROT_READ | PROT_WRITE,MAP_SHARED,shm,0);
    while(1)
    {
        scanf("%s",str);
        *count = str;
        sleep(0.1);
    }
    

    return 0;
}
