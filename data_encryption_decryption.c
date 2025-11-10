#include <stdio.h>
#include <string.h>

int main() {
    char text[100];
    int key, i;
    char ch;

    printf("Enter a message: ");
    fgets(text, sizeof(text), stdin);
    // Remove newline if present
    text[strcspn(text, "\n")] = '\0';

    printf("Enter key value (1-25): ");
    scanf("%d", &key);

    // Encryption
    for (i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch + key;
            if (ch > 'z')
                ch = ch - 26;
            text[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch + key;
            if (ch > 'Z')
                ch = ch - 26;
            text[i] = ch;
        }
    }
    printf("\nEncrypted message: %s\n", text);

    // Decryption
    for (i = 0; text[i] != '\0'; i++) {
        ch = text[i];
        if (ch >= 'a' && ch <= 'z') {
            ch = ch - key;
            if (ch < 'a')
                ch = ch + 26;
            text[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
            ch = ch - key;
            if (ch < 'A')
                ch = ch + 26;
            text[i] = ch;
        }
    }
    printf("Decrypted message: %s\n", text);

    return 0;
}
