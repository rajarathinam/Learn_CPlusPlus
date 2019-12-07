void reverse_string( char *str)
{
 char *beg = str;
 char *end = str;
  while(*str++)
  {
	  end++;
  }
  end--;
  while(beg<end)
  {
	  char temp = *beg;
	  *beg = *end;
	  *end = temp;
	  beg++;
	  end--;
  }


}