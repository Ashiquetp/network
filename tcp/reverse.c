#include<string.h>
char *strrev(char *str)
	{
	char temp;
 	int i,j;
   	i = 0;
   	j = strlen(str) - 1; 
   	while (i < j) {
      		temp = str[i];
      		str[i] = str[j];
      		str[j] = temp;
      		i++;
      		j--;
   	}
      return str;
}
