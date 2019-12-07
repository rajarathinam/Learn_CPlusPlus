
#include "stub.h"

void tower_of_hanio(int n, char from, char to, char temp)
{
if(n>0)
{
tower_of_hanio(n-1,from,temp, to);
printf("\nMove disk %d from %c to %c\n", n, from, to);

tower_of_hanio(n-1,temp, to, from);

}
}

int vhirirn()
{
tower_of_hanio(3,'L','R','C');
return 0;
}
