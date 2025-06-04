#include <stdio.h> // Standard input/output functions
#include <stdlib.h> // Standard library functions
#include <string.h> // String manipulation functions
#include <ctype.h> // Character type functions
#include <math.h> // Math functions

#define MAX 1000 // Maximum buffer size

// Remove spaces and convert to uppercase
void preprocess(char *s) {
    int j = 0; // Index for the processed string
    for (int i = 0; s[i]; i++) // Loop through each character in the input string
        if (!isspace(s[i])) // If the character is not a space
            s[j++] = toupper(s[i]); // Convert to uppercase and add to processed string
    s[j] = '\0'; // Null-terminate the processed string
}

// Encrypt plaintext using columnar transposition
void encrypt(char *plain, int key, char *cipher) {
    int len = strlen(plain); // Get length of plaintext
    int rows = (int)ceil((double)len / key); // Calculate number of rows
    int padded_len = rows * key; // Calculate padded length

    // Pad with 'X' if needed
    for (int i = len; i < padded_len; i++) // Loop from end of plaintext to padded length
        plain[i] = 'X'; // Pad with 'X'
    plain[padded_len] = '\0'; // Null-terminate the padded plaintext

    int idx = 0; // Index for ciphertext
    for (int col = 0; col < key; col++) // Loop through columns
        for (int row = 0; row < rows; row++) // Loop through rows
            cipher[idx++] = plain[row * key + col]; // Read column-wise and add to ciphertext
    cipher[idx] = '\0'; // Null-terminate the ciphertext
}

// Decrypt ciphertext using reverse columnar transposition
void decrypt(char *cipher, int key, char *plain) {
    int len = strlen(cipher); // Get length of ciphertext
    int rows = (int)ceil((double)len / key); // Calculate number of rows

    int idx = 0; // Index for plaintext
    for (int row = 0; row < rows; row++) // Loop through rows
        for (int col = 0; col < key; col++) { // Loop through columns
            int pos = col * rows + row; // Calculate position in ciphertext
            if (pos < len) // If position is within bounds
                plain[idx++] = cipher[pos]; // Add character to plaintext
        }
    // Remove padding
    while (idx > 0 && plain[idx - 1] == 'X') // Remove trailing 'X' padding
        idx--;
    plain[idx] = '\0'; // Null-terminate the plaintext
}

int main() {
    int choice, key; // Variables for menu choice and key
    char text[MAX], result[MAX]; // Buffers for input and output

    printf("1. Encrypt\n2. Decrypt\n3. Exit\nChoose: "); // Print menu
    scanf("%d", &choice); // Read user choice
    getchar(); // consume newline

    if (choice == 1) { // If user chooses encryption
        printf("Key: "); // Prompt for key
        scanf("%d", &key); // Read key
        getchar(); // Consume newline

        printf("Plaintext: "); // Prompt for plaintext
        fgets(text, sizeof(text), stdin); // Read plaintext
        text[strcspn(text, "\n")] = 0; // Remove newline character

        preprocess(text); // Remove spaces and convert to uppercase
        encrypt(text, key, result); // Encrypt the plaintext
        printf("Encrypted: %s\n", result); // Print encrypted text

    } else if (choice == 2) { // If user chooses decryption
        printf("Key: "); // Prompt for key
        scanf("%d", &key); // Read key
        getchar(); // Consume newline

        printf("Ciphertext: "); // Prompt for ciphertext
        fgets(text, sizeof(text), stdin); // Read ciphertext
        text[strcspn(text, "\n")] = 0; // Remove newline character

        decrypt(text, key, result); // Decrypt the ciphertext
        printf("Decrypted: %s\n", result); // Print decrypted text

    } else { // If user chooses to exit
        printf("Goodbye!\n"); // Print goodbye message
    }

    return 0; // End program
}
