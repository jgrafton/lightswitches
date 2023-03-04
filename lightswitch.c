#include <stdio.h>
#include <stdint.h>

#define MAX64 0xFFFFFFFFFFFFFFFF

void output_switches(uint64_t switches)
{
    uint64_t index = 1;

    for(int j = 0; j < 8; j++)
    {
        for(int i = 0; i < 7; i++)
        {

            if ((1ULL << index) & switches) 
                printf("%.03lu", index);
            else 
                printf(" . ");

            index++;
        }
        printf("\n");
    }
}

int main(void)
{
    uint64_t switches;

    printf("56 Light Switches\n");

    switches = 0x0;
    printf("all off\n");
    output_switches(switches);

    switches = MAX64;
    printf("\nall on\n");
    output_switches(switches);

    switches = 0x0;
    printf("\nsquares\n");
    for(int i=1; i < 57; i++)
    {
        for (int j=1; j < 57; j += i)
        {
            // bit flip
            int index = j - 1;
            switches = (1ULL << index) ^ switches;
        }
    }
    output_switches(switches);
}

