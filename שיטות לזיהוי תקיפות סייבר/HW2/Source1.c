#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include<stdlib.h>
main()
{
	int i, j, k, numstr[100], numkey[100], numcipher[100];
	char str1[100], key[100];
	printf("Enter a string:");
	gets(str1);
	for (i = 0, j = 0; i < strlen(str1); i++)
	{
		if (str1[i] != ' ')
		{
			str1[j] = toupper(str1[i]);
			j++;
		}
	}
	str1[j] = '\0';
	for (i = 0; i < strlen(str1); i++)
	{
		numstr[i] = str1[i] - 'A';
	}
	printf("Enter a key : ");
	gets(key);
	for (i = 0, j = 0; i < strlen(key); i++)
	{
		if (key[i] != ' ')
		{
			key[j] = toupper(key[i]);
			j++;
		}
	}
	key[j] = '\0';
	for (i = 0; i < strlen(str1);)
	{
		for (j = 0; (j < strlen(key)) && (i < strlen(str1)); j++)
		{
			numkey[i] = key[j] - 'A';
			i++;
		}

	}

	for (i = 0; i < strlen(str1); i++)
	{
		numcipher[i] = numstr[i] + numkey[i];
	}
	for (i = 0; i < strlen(str1); i++)
	{
		if (numcipher[i] > 25)
		{
			numcipher[i] = numcipher[i] - 26;
		}
	}
	printf("Cipher text is : ");
	for (i = 0; i < strlen(str1); i++)
	{
		printf("%c", (numcipher[i] + 'A'));
	}
	getchar();
	printf("\n");
}