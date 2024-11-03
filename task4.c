#include <stdio.h>
#include <string.h>

void encrypt(char *text, int shift) {
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A' + shift + 26) % 26) + 'A';
        } else if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a' + shift + 26) % 26) + 'a';
        }
    }
}

void decrypt(char *text, int shift) {
    encrypt(text, -shift); 
}

void encrypt_file(const char *input_filename, const char *output_filename, int shift) {
    FILE *input = fopen(input_filename, "r");
    FILE *output = fopen(output_filename, "w");

    if (input == NULL || output == NULL) {
        printf("Error opening file.\n");
        return;
    }

    char ch;
    while ((ch = fgetc(input)) != EOF) {
        if (ch >= 'A' && ch <= 'Z') {
            ch = ((ch - 'A' + shift + 26) % 26) + 'A';
        } else if (ch >= 'a' && ch <= 'z') {
            ch = ((ch - 'a' + shift + 26) % 26) + 'a';
        }
        fputc(ch, output);
    }

    printf("File has been processed and saved to %s\n", output_filename);

    fclose(input);
    fclose(output);
}

void decrypt_file(const char *input_filename, const char *output_filename, int shift) {
    encrypt_file(input_filename, output_filename, -shift);
}

int main() {
    char text[100];
    char mode ,method;
    char input_filename[100], output_filename[100];

    printf("Encrypt (E) or Decrypt (D): ");
    scanf(" %c", &mode);

    printf("Process a (F)ile or a (S)tring? ");
    scanf(" %c", &method);
    getchar(); 

    if(method == 'S'){
        printf("Enter text to encrypt or decrypt: ");
        fgets(text, sizeof(text), stdin);

        if (mode == 'E') {
            encrypt(text, 3);
            printf("Encrypted text: %s\n", text);
        } else if (mode == 'D') {
            decrypt(text, 3);
            printf("Decrypted text: %s\n", text);
        } else {
            printf("Invalid option.\n");
        }
    } else if(method == 'F'){
        printf("Enter the input filename: ");
        scanf("%s", input_filename);
        printf("Enter the output filename: ");
        scanf("%s", output_filename);

        if (mode == 'E') {
            encrypt_file(input_filename, output_filename, 3);
        } else if (mode == 'D') {
            decrypt_file(input_filename, output_filename, 3);
        } else {
            printf("Invalid option.\n");
        }
    } else {
        printf("Invalid choice.\n");
    }
    return 0;
}

