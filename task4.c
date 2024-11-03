#include <stdio.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {

            text[i] = ((text[i] - 'A' - shift + 26) % 26) + 'A';

        } else if (text[i] >= 'a' && text[i] <= 'z') {

            text[i] = ((text[i] - 'a' - shift + 26) % 26) + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, -shift); 
}

int main() {
    char text[100];
    printf("Enter text to encrypt or decrypt: ");
    fgets(text, sizeof(text), stdin);
    
    char c;
    printf("Encrypt(E) or Decrypt(D): ");
    scanf(" %c", &c);

	if (c == 'E') {
        	encrypt(text, 3);
		printf("Encrypted text: %s\n", text);
	} else if (c == 'D') {
        	decrypt(text, 3);
        	printf("Decrypted text: %s\n", text);
	} else {
     			   printf("XXXXXX.\n");}
    return 0;
}

