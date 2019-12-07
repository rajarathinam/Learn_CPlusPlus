#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include <unistd.h>


char *findSubstring(const char *str1, const char*str2) 
{
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    
    // find maximum length of common substring
    int n = 1; 
    int max = 0;
    while (n <= len1 && n <= len2)
	{
        if (!strncmp(str1, str2 + len2 - n, n)) 
			max = n;
        n++;
    }

    // create substring
    char *output = (char*)malloc(max+1);
    strncpy(output, str1, max);
    output[max] = '\0';

    return output;
}

int edhjrwhn()
{
    const char *str1 = "rajxxx";
    const char *str2 = "yyyraj";

    char *output = findSubstring(str1, str2);

    printf("[%s]\n", output);
    free(output);

    return 0;
}