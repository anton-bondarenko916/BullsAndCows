#include "functions.h"

int created = 0, createdCopy = 0;

int massiv[20] = {  1234,
                8796,
                8963,
                3024,
                4023,
                7812,
                4697,
                1034,
                7063,
                6378,
                9854,
                4560,
                7632,
                1058,
                2075,
                3096,
                4058,
                7965,
                4568,
                3067,} ;

void randomize() 
{
      srand(time(NULL));
      created = rand() % 19 + 0;
      createdCopy = massiv[created];
}

int create() 
{
    randomize();
    return createdCopy;
}
