bool isanagram(char *str1, char *str2)
{
	int xorValue=0;
int i;
while(*str1)
{
xorValue=xorValue ^((int)(*str1));
str1++;
}
while(*str2)
{
xorValue=xorValue ^(int)(*str2);
str2++;
}
if(xorValue==0)
return true;
else
return false;
}
  