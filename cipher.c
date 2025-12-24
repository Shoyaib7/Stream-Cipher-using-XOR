#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//---Helper Functions---

// Generates a deterministic interger seed from a string password

unsigned int create_seed(char *password) {
    unsigned int seed = 0;
    for (int i = 0; password[i] != '\0'; i++){
        seed = seed*31 + password[i];
    }
    return seed;
}

// The core logic for both encrypting and decrypting

void process_file(char *inputName, char *outputName, char *password) {
    FILE *inFile = fopen(inputName, "rb");
    FILE *outFile = fopen(outputName, "wb");

    if (inFile == NULL) {
        printf("Error: Could not open input file '%s'.\n", inputName);
        return;
    }
    if (outFile == NULL) {
        printf("Error: Could not create output file '%s'.\n", outputName);
        fclose(inFile);
        return;
    }

    //Intialize the random number generator with password hash
    unsigned int seed = create_seed(password);
    srand(seed);
    
    int byte;
    //Process byte by byte
    while ((byte = fgetc(inFile)) != EOF) {
        //Get the next byte from the pseudo-random stream
        int randomKeyByte = rand() % 256;
        
        //XOR operation
        int cipherByte = byte^randomKeyByte;
        
        fputc(cipherByte, outFile);
    }
    
    fclose(inFile);
    fclose(outFile);
}

//---Main Driver---

void remove_newline(char *str) {
    str[strcspn(str, "\n")] = 0; 
}

int main() {
    char inputFile[100];
    char outputFile[100];
    char password[100];

    printf("==============================================\n");
    printf("     C Stream Cipher (XOR Encryption)         \n");
    printf("==============================================\n");
    printf("Note: This program Encrypts and Decryptes.\n");
    printf("Just run it on the encrypted file with the same password.\n\n");

    printf("Enter FULL PATH of file to encrypt or decrypt: \n> ");
    fgets(inputFile, sizeof(inputFile), stdin);
    remove_newline(inputFile);
    
    printf("Enter FULL PATH for the result file:\n> ");
    fgets(outputFile, sizeof(outputFile), stdin);
    remove_newline(outputFile);

    printf("Enter password: ");
    fgets(password, sizeof(password), stdin);
    remove_newline(password);

    process_file(inputFile, outputFile, password);

    printf("\nSuccess! Saved to: %s\n", outputFile);
    return 0;
}