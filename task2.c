#include <stdio.h>
#include <ctype.h>


void count_lines_words_chars(FILE *file, int *lines, int *words, int *charr) {
    char line[100];

    while (fgets(line, sizeof(line), file)) {
        (*lines)++;
        int i = 0;
        int in_word = 0;

        while (line[i] != '\0') {
            (*charr)++;

            if (line[i] == ' ' || line[i] == '\n' ) {
                if (in_word) {
                    (*words)++;
                    in_word = 0;
                }
            } else {
                in_word = 1;
            }
            i++;
        }

        if (in_word) {
            (*words)++;
        }
    }
}

int main(){
	
	FILE *file;
	file=fopen("task2test.txt", "r");
    	if (file == NULL) {
        printf("Error! Could not open file.\n");
        return 1;
   	 }

	//fprintf(file, "Hello World!\nThis is a test file.\nIt contains multiple lines.\n");
    	//`fclose(file); 
    	file = fopen("task2test.txt", "r");
    	if (file == NULL) {
        printf("Error! Could not open file.\n");
        return 1;
    }


	int lines =0 , words=0 , charr=0;

	count_lines_words_chars(file, &lines, &words, &charr);
	printf("Lines: %d\nWords: %d\nCharacters: %d\n", lines, words, charr);

	fclose(file);
    	return 0;}

