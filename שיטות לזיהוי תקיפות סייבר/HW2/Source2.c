#include <stdio.h>
#include <string.h>
int main()
{
	char string[100000];
	int c1 = 0,c2=0, count[26] = { 0 }, x,b;

	printf("Enter a string\n");
	gets(string);

	while (string[c1] != '\0') {
		/** Considering characters from 'a' to 'z' only and ignoring others. */

		if (string[c1] >= 'a' && string[c1] <= 'z') {
			x = string[c1] - 'a';
			count[x]++;
		}

		c1++;

	}
	while (string[c2] != '\0') {
		/** Considering characters from 'a' to 'z' only and ignoring others. */

		if (string[c2] >= 'A' && string[c2] <= 'Z') {
			b = string[c2] - 'A';
			count[b]++;
		}

		c2++;

	}

	for (c1 = 0; c1 < 26; c1++)
		printf("%c occurs %d times in the string.\n", c1 + 'a', count[c1]);
	
	getchar();
	getchar();
	return 0;
	
}