#include <stdio.h>
#include <string.h>
#include <math.h>

// Encrypt plaintext using transposition cipher
void encrypt(const char *plain, int key, char *encrypted) {
    int len = strlen(plain);
    int rows = (int)ceil((double)len / key);
    int padded_len = rows * key;
    char grid[1000] = {0};

    // Copy plain text and pad with 'X' if needed
    strncpy(grid, plain, len);
    for (int i = len; i < padded_len; i++)
        grid[i] = 'X';

    // Read characters column-wise
    int idx = 0;
    for (int col = 0; col < key; col++)
        for (int row = 0; row < rows; row++)
            encrypted[idx++] = grid[row * key + col];

    encrypted[idx] = '\0'; // End of string
}

// Decrypt cipher text using transposition cipher
void decrypt(const char *cipher, int key, char *decrypted) {
    int len = strlen(cipher);
    int rows = (int)ceil((double)len / key);
    char grid[1000] = {0};
    int idx = 0;

    // Fill grid column-wise with cipher characters
    for (int col = 0; col < key; col++)
        for (int row = 0; row < rows; row++)
            if (idx < len)
                grid[row * key + col] = cipher[idx++];

    // Remove trailing 'X' padding
    int i;
    for (i = rows * key - 1; i >= 0 && grid[i] == 'X'; i--)
        grid[i] = '\0';

    strcpy(decrypted, grid);
}

int main() {
    int choice, key;
    char input[1000], output[1000];

    printf("1. Encryption\n2. Decryption\n3. Exit\nChoose: ");
    scanf("%d", &choice);
    getchar(); // Clear newline

    if (choice == 1) {
        printf("Enter key: ");
        scanf("%d", &key);
        getchar();

        printf("Enter plaintext: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        encrypt(input, key, output);
        printf("Encrypted: %s\n", output);

    } else if (choice == 2) {
        printf("Enter key: ");
        scanf("%d", &key);
        getchar();

        printf("Enter ciphertext: ");
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        decrypt(input, key, output);
        printf("Decrypted: %s\n", output);

    } else {
        printf("Goodbye!\n");
    }

    return 0;
}
