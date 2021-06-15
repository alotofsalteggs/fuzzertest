#include <memory.h>
#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include "fun.h"

void fun()
{
    printf("-----------------orignin\n");
}
void DoSomeThingInterestingWithMyAPI(const uint8_t *Data, size_t Size)
{
    char buf[64] = {0};
    // unsigned char* p = (unsigned char*)malloc(128);
    // memset(p,0,128);
    // free(p);
    // int f = open("./test.txt",O_CREAT);
    // close(f);
    if (Size > 128)
    {
        fun();
    }
    if(Size > 63)
     Size = 63;

    
    // if (strstr((const char*)Data,"HTTP/1.1 200"))
    //     printf("-----------------------find HTTP/1.1 200\n");

    memcpy(buf, Data, Size);
    const char *ptr = NULL;
    if (strcmp(buf+10,"hello ,world") == 0)
    {
        printf("++++++++++++++++++\n");
    }
    // fun();
    // if ((ptr = strstr((const char*)buf,"HTTP/1.1 200")) != NULL)
    //     printf("-----------------------offset:%lu find HTTP/1.1 200\n",(unsigned long) ptr- (unsigned long)buf);
    
    // (void*)Data;
}