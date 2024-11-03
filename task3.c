#include <stdio.h>

int main() {
    FILE *file_in = fopen("bitstream1.bit", "r");
    FILE *file_out = fopen("bitstream1.hex", "w");

    if (file_in == NULL || file_out == NULL) return 1;
    
    int bit, count = 0;
    unsigned char byte = 0;

    while ((bit = fgetc(file_in)) != EOF) {
        if (bit == '0' || bit == '1') {
            if (bit == '1') {
                byte += (1 << count);
            }
            count++;

            if (count == 8) {
                fprintf(file_out, "%02X\n", byte);
                count = 0;
                byte = 0;
            }
        }
    }
    fclose(file_in);
    fclose(file_out);
    return 0;
}

