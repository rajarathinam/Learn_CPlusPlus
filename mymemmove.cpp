#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void *mymemmove(void *dest, const void *src, size_t count);
int csvyv(int argc, char* argv[])
{
char *p1, *p2;
char *p3, *p4;
int size;
printf("\n--------------------------------\n");
/* ----------------------------------------
*
* CASE 1 : From (SRC) < To (DEST)
*
*
+--+---------------------+--+
*
| |
| |
*
+--+---------------------+--+
*
^ ^
*
| |
*
From To
*
* --------------------------------------- */
p1 = (char *) malloc(12);
memset(p1,12,'\0');
size=10;
strcpy(p1,"ABCDEFGHI");
p2 = p1 + 2;
printf("\n--------------------------------\n");
printf("\nFrom (before) = [%s]",p1);
printf("\nTo (before)= [%s]",p2);
//mymemmove(p2,p1,size);
memcpy(p2,p1,size);
printf("\n\nFrom (after) = [%s]",p1);
printf("\nTo (after)= [%s]",p2);
printf("\n--------------------------------\n");


/* ----------------------------------------
*
* CASE 2 : From (SRC) > To (DEST)
*
*
+--+---------------------+--+
*
| |
| |
*
+--+---------------------+--+
*
^ ^
*
| |
*
To From
*
* --------------------------------------- */
p3 = (char *) malloc(12);
memset(p3,12,'\0');
p4 = p3 + 2;
strcpy(p4, "ABCDEFGHI");
printf("\nFrom (before) = [%s]",p4);
printf("\nTo (before)= [%s]",p3);
mymemmove(p3, p4, size);
printf("\n\nFrom (after) = [%s]",p4);
printf("\nTo (after)= [%s]",p3);
printf("\n--------------------------------\n");
/* ----------------------------------------
*
* CASE 3 : No overlap
*
* --------------------------------------- */
p1 = (char *) malloc(30);
memset(p1,30,'\0');
size=10;
strcpy(p1,"ABCDEFGHI");
p2 = p1 + 15;
printf("\n--------------------------------\n");
printf("\nFrom (before) = [%s]",p1);
printf("\nTo (before)= [%s]",p2);
mymemmove(p2,p1,size);
printf("\n\nFrom (after) = [%s]",p1);
printf("\nTo (after)= [%s]",p2);
printf("\n--------------------------------\n");
printf("\n\n");
return 0;
}
void *mymemmove(void *to, const void *from, size_t size)
{
unsigned char *p1;
const unsigned char *p2;
p1 = (unsigned char *) to;
p2 = (const unsigned char *) from;
p2 = p2 + size;
// Check if there is an overlap or not.
while (p2 != from && --p2 != to);
if (p2 != from)
{
// Overlap detected!
p2= (const unsigned char *) from;
p2= p2 + size;
p1= p1 + size;


while (size-- != 0)
{
*--p1 = *--p2;
}
}
else
{
// No overlap OR they overlap as CASE 2 above.
// memcopy() would have done this directly.
while (size-- != 0)
{
*p1++ = *p2++;
}
}
return(to);
}
