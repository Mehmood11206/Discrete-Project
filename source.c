#include <stdio.h> 
#include <string.h> 

// Encrypt function (columnar transposition)
void encrypt(char plain[], int key, char encrypted[]) {
    int len = strlen(plain);            // Get length of the plaintext
    int rows = (len + key - 1) / key;   // Calculate number of rows needed
    int idx = 0;                         // Initialize index for encrypted text
    for (int c = 0; c < key; c++) {     // Loop through each column
        for (int r = 0; r < rows; r++) { // Loop through each row
            int pos = r * key + c;       // Calculate position in plaintext
            encrypted[idx++] = (pos < len) ? plain[pos] : 'X'; // Add character or pad with 'X'
        }
    encrypted[idx] = '\0'; // Null-terminate the encrypted string
}

// Decrypt function (reverse columnar transposition)
void decrypt(char cipher[], int key, char decrypted[]) {
    int len = strlen(cipher);                       // Get length of the ciphertext
    int rows = (len + key - 1) / key;           // Calculate number of rows
    int idx = 0;                    // Initialize index for decrypted text
    for (int r = 0; r < rows; r++)           // Loop through each row
        for (int c = 0; c < key; c++) {          // Loop through each column
            int pos = c * rows + r;             // Calculate position in ciphertext
            if (pos < len)               // Check if position is within bounds
                decrypted[idx++] = cipher[pos]; // Add character to decrypted text
        }
    // Remove trailing 'X'
    while (idx > 0 && decrypted[idx - 1] == 'X') idx--; // Remove padding 'X' at the end
    decrypted[idx] = '\0'; // Null-terminate the decrypted string
}

// Main function
int main() {
    int choice, key; // Variables for menu choice and key
    char input[1000], output[1000]; // Buffers for input and output text

    printf("1. Encrypt\n2. Decrypt\n3. Exit\nChoose: "); // Print menu
    scanf("%d", &choice); // Read user choice
    getchar(); // Remove newline from buffer

    if (choice == 1) { // If user chooses encryption
        printf("Enter key (number): "); // Prompt for key
        scanf("%d", &key); // Read key
        getchar(); // Remove newline
        printf("Enter text to encrypt: "); // Prompt for plaintext
        fgets(input, sizeof(input), stdin); // Read plaintext
        input[strcspn(input, "\n")] = '\0'; // Remove newline from input

        encrypt(input, key, output); // Encrypt the plaintext
        printf("Encrypted text: %s\n", output); // Print encrypted text

    } else if (choice == 2) { // If user chooses decryption
        printf("Enter key (number): "); // Prompt for key
        scanf("%d", &key); // Read key
        getchar(); // Remove newline
        printf("Enter text to decrypt: "); // Prompt for ciphertext
        fgets(input, sizeof(input), stdin); // Read ciphertext
        input[strcspn(input, "\n")] = '\0'; // Remove newline from input

        decrypt(input, key, output); // Decrypt the ciphertext
        printf("Decrypted text: %s\n", output); // Print decrypted text

    } else { // If user chooses to exit
        printf("Goodbye!\n"); // Print goodbye message
    }

    return 0; // End program
}
