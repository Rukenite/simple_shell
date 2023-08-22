#include "main.h"

/**
 * _free - frees all memory in the heap
 *
 * @buff: pointer to memory still in use
 */
void _free(char **buff)
{
        int i = 0;

        while(buff[i])
                free(buff[i++]);
}
