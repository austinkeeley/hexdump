#include <stdio.h>
#include "hex.h"

/**
 * Dumps to a file output using a starting label
 * Args:
 *   f - File output stream to write to, e.g. stdout
 *   mem - Memory buffer to write
 *   len - Size of the buffer
 *   start - Starting label
 *
 *  Returns the number of bytes written
 */
size_t fdump(FILE *f, void *mem, size_t len, size_t start) {
    unsigned char *m = mem;

    // Total bytes printed
    size_t total_printed = 0;

    // Bytes printed in this line
    unsigned int num_printed = 0;

    // 32-bit word printed in this line
    unsigned int words_printed = 0;

    unsigned int i = 0;
    while (1) {

        if (total_printed % 16 == 0) {
            printf("%08lx: ", i + start);
        }

        fprintf(f, "%02x", m[i]);
        total_printed += 1;
        num_printed += 1;

        if (total_printed % 4 == 0) {
            fprintf(f, " ");
            words_printed += 1;
        }
        if (total_printed % 16 == 0) {

            int j = i - 15;

            fprintf(f, "|");
            while (j != i+1) {
                if (m[j] >= 32 && m[j] <= 126) {
                    fprintf(f, "%c", m[j] & 0xff);
                } else {
                    fprintf(f, ".");
                }
                j++;
            }

            fprintf(f, "|\n");
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
                    fprintf(f, "  ");
                    k++;
                }

                k = 0;
                while (k < (4 - words_printed)) {
                    fprintf(f, " ");
                    k++;
                }

                fprintf(f, "|");
                while (j != i) {
                    if (m[j] >= 32 && m[j] <= 126) {
                        fprintf(f, "%c", m[j] & 0xff);
                    } else {
                        fprintf(f, ".");
                    }
                    j++;
                }

                k = 0;
                while (k < (16 - num_printed)) {
                    fprintf(f, " ");
                    k++;
                }
                fprintf(f, "|\n");
                words_printed = 0;
            }

            break;
        }
    }
    return i;
}

/**
 * Hexdump like function
 * Args:
 *   mem - Memory to dump
 *   len - Number of bytes to dump
 */
size_t dump(void *mem, size_t len) {
    return fdump(stdout, mem, len, 0x0);
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
    free(m);
}

#endif
