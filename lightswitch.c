#include <stdio.h>
#include <stdint.h>

#define MAX64 0xFFFFFFFFFFFFFFFF

void output_switches(uint64_t top, uint64_t bottom)
{
    uint64_t tmp;
    uint64_t index = 1;

    for(int j = 0; j < 10; j++)
    {
        for(int i = 0; i < 10; i++)
        {
            if (index < 64)
                tmp = bottom;
            else
                tmp = top;

            if ((1ULL << index) & tmp)
                printf("*");
            else 
                printf(".");

            //printf("%i", (1 <<index));

            index++;
        }
        printf("\n");
    }
}

int main(void)
{
    uint64_t top;
    uint64_t bottom;

    printf("100 Light Switches\n");

    bottom = 0x0; top = 0x0;
    printf("all off\n");
    output_switches(top, bottom);

    bottom = MAX64; top = MAX64;
    printf("\nall on\n");
    output_switches(top, bottom);

    bottom = 0x0; top = 0x0; 
    printf("\nalgo\n");
    for(int i=1; i < 64; i++)
    {
        for (int j=1; j < 64; j += i)
        {
            // bit flip
            bottom = (1ULL << j) ^ bottom;
        }
    }
    output_switches(top, bottom);
}

