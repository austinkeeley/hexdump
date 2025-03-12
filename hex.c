#include <stdio.h>
#include "hex.h"

/**
 * Hexdump like function
 *   mem - Memory to dump
 *   len - Number of bytes to dump
 */
int dump(void *mem, unsigned int len) {

    unsigned char *m = mem;

    // Total bytes printed
    unsigned int total_printed = 0;

    // Bytes printed in this line
    unsigned int num_printed = 0;

    // 32-bit word printed in this line
    unsigned int words_printed = 0;

    unsigned int i = 0;
    while (1) {

        if (total_printed % 16 == 0) {
            printf("%08x: ", i);
        }

        printf("%02x", m[i]);
        total_printed += 1;
        num_printed += 1;

        if (total_printed % 4 == 0) {
            printf(" ");
            words_printed += 1;
        }
        if (total_printed % 16 == 0) {

            int j = i - 15;

            printf("|");
            while (j != i+1) {
                if (m[j] >= 32 && m[j] <= 126) {
                    printf("%c", m[j] & 0xff);
                } else {
                    printf(".");
                }
                j++;
            }

            printf("|\n");
            words_printed = 0;
            num_printed = 0;
        }

        i++;

        if (i == len) {

            if (total_printed % 16 != 0) {
                int diff = total_printed % 16;
                int j = i - diff;

                int k = 0;
                while (k < (16 - num_printed)) {
                    printf("  ");
                    k++;
                }

                k = 0;
                while (k < (4 - words_printed)) {
                    printf(" ");
                    k++;
                }

                printf("|");
                while (j != i) {
                    if (m[j] >= 32 && m[j] <= 126) {
                        printf("%c", m[j] & 0xff);
                    } else {
                        printf(".");
                    }
                    j++;
                }

                k = 0;
                while (k < (16 - num_printed)) {
                    printf(" ");
                    k++;
                }
                printf("|\n");
                words_printed = 0;
            }

            break;
        }
    }
    return i;
}

#ifdef HEX_MAIN


#include <stdlib.h>

int main(int argc, char *argv[]) {

    unsigned char *m = malloc(256);
    int i = 0;
    for (i =0; i<256; i++) {
        m[i] = i;
    }
    dump(m, 129);
}

#endif
