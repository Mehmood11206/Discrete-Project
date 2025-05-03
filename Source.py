import math

user_input = input("1.Encryption\n2.Decryption\n3.Exit\n").upper().strip().replace(" ","")
key = input("write the Key :")

def encrypt(plaintxt, key):
    number_of_rows = math.ceil(len(plaintxt)/key)
    if len(plaintxt) % key != 0:
        plaintxt += 'X' * (key - len(plaintxt) % key)
    encrypted_txt = ''
    for i in range(key):
        for j in range(number_of_rows):
            if j * key + i < len(plaintxt):
                encrypted_txt += plaintxt[j * key + i]
    return encrypted_txt
def decrypt(ciphertxt, key):
    number_of_rows = math.ceil(len(ciphertxt)/key)
    decrypted_txt = ''
    for i in range(number_of_rows):
        for j in range(key):
            if i + j * number_of_rows < len(ciphertxt):
                decrypted_txt += ciphertxt[i + j * number_of_rows]
    return decrypted_txt.rstrip('X')

def main():
    if user_input == '1':
        plaintxt = input("write the plaintxt :")
        encrypted_txt = encrypt(plaintxt, int(key))
        print("Encrypted text:", encrypted_txt)
    elif user_input == '2':
        ciphertxt = input("write the ciphertxt :")
        decrypted_txt = decrypt(ciphertxt, int(key))
        print("Decrypted text:", decrypted_txt)
    elif user_input == '3':
        exit()
    else:
        print("Invalid option. Please try again.")
        main()

if __name__ == "__main__":
    main()



