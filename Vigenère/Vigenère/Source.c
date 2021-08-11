# include <stdio.h> //fgets() , printf(0, stdin 
# include <string.h> //strlen()
# include <ctype.h> // isupper() , islower() , tolower(), toupper(), isalpha()

//Declare vigenere cipher
void vigenereCipher(char* plainText, char* k);

int main() {

	char* k = "hello"; //Assign the key
	char plainText[101]; //Declare a string for a users text to encrypt

	//Ask the user for a sentence or word to encrypt
	printf("Please enter a sentence or word you want to encrypt: ");

	//Get the users input (the plain text)
	fgets(plainText, sizeof(plainText), stdin);

	//print the encrypted plain text
	printf("The ciphered text with (Key shift = '%s') is: ", k);

	//Print the actual encryption
	vigenereCipher(plainText, k);


	return 0;
}

//C[i] = (p[i] + k[i mod klength] ) mod N, C = cipher, k = secret key (word), p = sentence or plainText or word, N = number of letters in the alphabet
void vigenereCipher(char* plainText, char* k) {

	int i;
	char cipher;
	int cipherValue;
	int len = strlen(k);

	//Loop through the length of the plain text string
	for (i = 0; i < strlen(plainText); i++) {

		//if the character is lowercase, where range is [97 -122]
		if (islower(plainText[i]))
		{
			cipherValue = ((int)plainText[i] - 97 + (int)tolower(k[i % len]) - 97) % 26 + 97;
			cipher = (char)cipherValue;
		}
		else // Else it's upper case, where letter range is [65 - 90]
		{
			cipherValue = ((int)plainText[i] - 65 + (int)toupper(k[i % len]) - 65) % 26 + 65;
			cipher = (char)cipherValue;
		}

		//Print the ciphered character if it is alphanumeric (a letter)
		if (isalpha(plainText[i]))
		{
			printf("%c", cipher);
		}
		else //if the character is not a letter then print the character (e.g. space)
		{
			printf("%c", plainText[i]);
		}
	}
	getchar();
	getchar();

}