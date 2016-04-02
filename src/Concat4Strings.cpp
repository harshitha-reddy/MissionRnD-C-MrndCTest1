/*
Given 4 strings, write a fucntion to get smallest string that consists all four strings. 
In Case of Multiple strings with smallest length,
Return the string which occurs alphabetically first .

Ex : (acat, tiger, silica, licaria) O/P: "silicariacatiger"
Ex : (def,abc,ghi,jkl)   O/P : “abcdefghijkl” (Alphabetically first )
Ex : (apple,pp,pineapple,nea) O/P: "pineapple";
Ex : (zzzabc,abcdef,yyyzzz,cabyyy) O/P: "cabyyyzzzabcdef" (Order Swapped )

Note : Each string given as input ,should be in the same format in the output string. 
Ie if input string is abcd ,it cannot be modified as bdca in the final string .

The Order of Strings in the Final string ,maynot be in the same order 
given in which they are given
Function Signatue : char * smallestword(char *s1,char *s2,char *s3,char *s4);

Note : You can use String.h functions .

Constraints : 
Length of each String will be less than 100 .

Difficulty : Hard
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

char * concat_4strings(char *s1, char *s2, char *s3, char *s4){
	//Return the new string created.
	if (s1 == '\0' || s2 == '\0' || s3 == '\0' || s4 == '\0')
		return NULL;
}
/*	int i, j, len1, len2, len3, len4, finallen;
	len1 = strlen(s1);
	len2 = strlen(s2);
	len3 = strlen(s3);
	len4 = strlen(s4);
	finallen = len1 + len2 + len3 + len4;
	char *result, *temp, *temp1, *flag;
	result = (char *)malloc(finallen * sizeof(char));
	temp = (char *)malloc(finallen * sizeof(char));
	temp1 = (char *)malloc(finallen * sizeof(char));
	flag = (char *)malloc(finallen * sizeof(char));
	temp = strcat(s1, s2);
	temp1 = strcat(s3, s4);
	flag = strcat(temp, temp1);
	result = removeDuplicate(flag);
	return result;

}
char* removeDuplicate(char *str)
{
	int i = 0, j;
	char ch;
	//printf("\nstr is %s", str);
	while ((ch = str[i++]) != '\0')
	{
		j = i;
		//printf("\n----ch = %c----", ch);
		while (str[j] != '\0')
		{
			//printf("\n--------Checking whether %c =  %c \n", str[j], ch);
			if (ch == str[j])
			{
				//printf("\n------------Yes");
				while (str[j] != '\0')
				{
					//printf("\nRemoving %c %d -- \n", str[j]);
					str[j] = str[++j];
					--i;

				}

				break;
			}
			//printf("\n------------No");

			//printf("\njj");
			j++;
		}
	}

	return str;
} */