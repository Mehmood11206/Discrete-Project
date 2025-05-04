import math



# This is the function to encrypt the plaintext.
def encrypt(plaintxt, key):
    number_of_rows = math.ceil(len(plaintxt)/key)
    # If the plaintext length is not a multiple of the key, pad it with 'X' characters.
    if len(plaintxt) % key != 0:
        plaintxt += 'X' * (key - len(plaintxt) % key)
    encrypted_txt = ''
    # Rearranging the plaintext into a grid of characters.
    for i in range(key):
        for j in range(number_of_rows):
            if j * key + i < len(plaintxt):
                encrypted_txt += plaintxt[j * key + i]
    return encrypted_txt
# This is the function to decrypt the ciphertext.
def decrypt(ciphertxt, key):
    number_of_rows = math.ceil(len(ciphertxt)/key)
    decrypted_txt = ''
    # Rearranging the ciphertext into a grid of characters.
    for i in range(number_of_rows):
        for j in range(key):
            if i + j * number_of_rows < len(ciphertxt):
                decrypted_txt += ciphertxt[i + j * number_of_rows]
    return decrypted_txt.rstrip('X')

def main():
    user_input = input("1.Encryption\n2.Decryption\n3.Exit\n")
    if user_input == '1':
        key = input("write the Key :")
        plaintxt = input("write the plaintxt :").upper().strip().replace(" ","")
        #calling the encrypt function to encrypt the plaintext.
        encrypted_txt = encrypt(plaintxt, int(key))
        print("Encrypted text:", encrypted_txt)
    elif user_input == '2':
        key = input("write the Key :")
        ciphertxt = input("write the ciphertxt :")
        #calling the decrypt function to decrypt the ciphertext.
        decrypted_txt = decrypt(ciphertxt, int(key))
        print("Decrypted text:", decrypted_txt)
    elif user_input == '3':
        exit()
    else:
        print("Invalid option. Please try again.")
        main()

if __name__ == "__main__":
    main()



