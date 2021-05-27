#include <memory.h>
#include <stdio.h>
#include "fun.h"

static void print_memory(const void *addr, const size_t len)
{
    if (len <= 0)
        return;
    unsigned char buf[17];
    buf[16] = 0;
    int pos = 0;
    // void * addr_tmp = addr;
    for (size_t i = 0; i <= len / 16; i++)
    {
        printf("%08lx: ", (unsigned long)addr + pos);

        for (int j = 0; j < 16; j++)
        {
            unsigned char c;
            if (pos < len)
            {
                c = *((unsigned char *)addr + pos);

                printf("%02x ", c);
                // if ((c>='a' && c <= 'z') || (c>='A'&&c<='Z'))
                if (c > 0x20 && c < 0x7f)
                    buf[j] = c;
                else
                    buf[j] = '.';
            }
            else
            {
                printf("   ");
                buf[j] = ' ';
            }

            pos += 1;
        }
        printf("    %s\n", buf);
        if (pos >= len)
            break;
    }
}
//mock fun()
void fun()
{
    printf("+++++++++++++++mock\n");
    printf("+++++++++++++++branch1 add\n");
    printf("+++++++++++++++branch2 add\n");

}
// extern "C" int LLVMFuzzerInitialize(int *argc, char ***argv)
// {
//     printf("LLVMFuzzerInitialize argc:%d\n", *argc);
//     // for (int i =0;i<*argc;i++)
//     // {
//     //     printf("%s ",(*argv)[i]);
//     // }
//     printf("\n\n\n");
//     return 0;
// }
extern "C" int LLVMFuzzerTestOneInput(const uint8_t *Data, size_t Size)
{
    printf("## LLVMFuzzerTestOneInput start\n");
    print_memory(Data,Size);
       
    // printf("\nSize: %d\n\n",Size);
    // printf("");
    DoSomeThingInterestingWithMyAPI(Data, Size);
    printf("##LLVMFuzzerTestOneInput complete\n\n");
    return 0;
}