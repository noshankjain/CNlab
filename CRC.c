#include <stdio.h>
#include <string.h>

int main() {
    char msg[100], key[20], data[120], transmitted_msg[120], received_msg[120];
    char remainder[20];
    int msg_len, key_len, i, j, error = 0;

    // Sender Side
    printf("Sender Side:\n");
    printf("Enter binary message: ");
    scanf("%s", msg);
    printf("Enter generator polynomial (binary): ");
    scanf("%s", key);

    msg_len = strlen(msg);
    key_len = strlen(key);

    // Append (key_len - 1) zeros to the message
    strcpy(data, msg);
    for (i = 0; i < key_len - 1; i++) {
        data[msg_len + i] = '0';
    }
    data[msg_len + key_len - 1] = '\0';

    // Make a copy of data to perform division
    char temp[120];
    strcpy(temp, data);

    // Perform division
    for (i = 0; i <= strlen(msg) - 1; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < key_len; j++) {
                temp[i + j] = (temp[i + j] == key[j]) ? '0' : '1';
            }
        }
    }

    // Extract remainder
    for (i = 0; i < key_len - 1; i++) {
        remainder[i] = temp[msg_len + i];
    }
    remainder[key_len - 1] = '\0';

    // Create transmitted message (original + remainder)
    strcpy(transmitted_msg, msg);
    strcat(transmitted_msg, remainder);

    printf("\nSender CRC Remainder: %s", remainder);
    printf("\nTransmitted Message (Message + CRC): %s\n", transmitted_msg);

    // Receiver Side
    printf("\nReceiver Side:\n");
    printf("Enter received message (with CRC): ");
    scanf("%s", received_msg);

    // Copy received message into temp buffer for division
    strcpy(temp, received_msg);

    // Perform division again
    for (i = 0; i <= strlen(received_msg) - key_len; i++) {
        if (temp[i] == '1') {
            for (j = 0; j < key_len; j++) {
                temp[i + j] = (temp[i + j] == key[j]) ? '0' : '1';
            }
        }
    }

    // Extract receiver-side remainder
    for (i = 0; i < key_len - 1; i++) {
        remainder[i] = temp[strlen(received_msg) - key_len + 1 + i];
    }
    remainder[key_len - 1] = '\0';

    printf("\nReceiver CRC Remainder: %s", remainder);

    // Check if remainder is all zeros
    error = 0;
    for (i = 0; i < key_len - 1; i++) {
        if (remainder[i] != '0') {
            error = 1;
            break;
        }
    }

    if (error) {
        printf("\nError detected in received message.\n");
    } else {
        printf("\nNo error detected. Message received correctly.\n");
    }

    return 0;
}
