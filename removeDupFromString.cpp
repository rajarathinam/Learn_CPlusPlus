#include "stub.h"
char* removeDupFromString(char input[], int len)
{
        char output[12];
        int ASCII[256] = {0};
        int i, j;
        for(i=0, j=0; i<len; i++)
        {
                if(ASCII[input[i]] == 0)
                {
                        output[j++] = input[i];
                        ASCII[input[i]] += 1;
                }
                else
                        ASCII[input[i]] += 1;
        }
        output[j] = '\0';
        return output;
}

char* removechar(char input[], char to_remove)
{
	char *output = new char[strlen(input) + 1];
	int i,j=0;

	for( i = 0; i < strlen(input);i++)
	{
		if(! (input[i] == to_remove))
		{
			output[j] = input[i];
			j++;
		}

	}
	output[j] = '\0';
	return output;
}

void removeDups(char *s)
{
	int hash[256] = {0};
	char temp;
	int ip_ind = 0;
	int res_ind =0;
	while( *(s + ip_ind))
	{
		temp = *(s + ip_ind);
		if( hash[temp] == 0 )
		{
			hash[temp] = 1;
			*(s + res_ind) = *(s + ip_ind);
			res_ind++;
		}
		ip_ind++;
	}
	*(s + res_ind) = '\0';
}
int dnjknf()
{
	char input[] = "rajarathinam";
	removeDups(input);
	cout<<input;
	//cout<<removeDupFromString(input,12);
	//cout<<removechar(input,'a');
	return 0;
}
