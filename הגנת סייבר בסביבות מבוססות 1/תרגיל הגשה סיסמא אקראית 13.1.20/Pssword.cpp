#include <stdio.h>
#include <stdlib.h>
#include <math.h>      
#include <time.h>

int main(void) 
{
	srand((unsigned int)(time(NULL)));
	int i=0;
	char pass[20];

	printf("Hello , press enter to get a twelve-character password : \n");
	getchar();
	while (i > -1) {


		for (i = 0; i < 5; i++)
		{
			
			pass[3 * i] = '0' + (rand() % 10); 
			char capLetter = 'A' + (rand() % 26); 
			pass[(3 * i) + 1] = capLetter;
			char letter = 'a' + (rand() % 26); 
			pass[(3 * i) + 2] = letter;
			pass[2 * i] = '!' + (rand() % 10);
		}
		pass[3 * i] = '\0'; 
		printf("generated password : %s\n\n", pass);
		getchar();
	}
	printf("\n\n");
}