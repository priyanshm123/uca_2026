#include <stdio.h>
#include <string.h>

const char base64_table[] =
    "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
    "abcdefghijklmnopqrstuvwxyz"
    "0123456789+/";

void base64_encode(const char *input, char *output) {
    int len = strlen(input);
    int i = 0;
    int j = 0;

    while (i < len) {
        unsigned char a = input[i++];
        unsigned char b = (i < len) ? input[i++] : 0;
        unsigned char c = (i < len) ? input[i++] : 0;

        output[j++] = base64_table[a >> 2];

        output[j++] = base64_table[
            ((a & 0x03) << 4) | (b >> 4)
        ];

        if (i - 1 < len) {
            output[j++] = base64_table[
                ((b & 0x0F) << 2) | (c >> 6)
            ];
        } else {
            output[j++] = '=';
        }

        if (i < len) {
            output[j++] = base64_table[c & 0x3F];
        } else {
            output[j++] = '=';
        }
    }

    output[j] = '\0';
}

int main() {
    char input[1000];
    char output[1400];

    printf("Enter a string: ");
    fgets(input, sizeof(input), stdin);

    input[strcspn(input, "\n")] = '\0';

    base64_encode(input, output);

    printf("Base64: %s\n", output);

    return 0;
}

