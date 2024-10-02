#include <stdio.h>
#include <string.h>
void Encrypt(){
    char plainText[100]; 
    printf("Enter the plaintext: ");
    scanf("%s", plainText); //I know this is unsafe
    int length = strlen(plainText);
    printf("Enter the key: ");
    int offset;
    scanf("%d", &offset);
    for(int x = 0; x < length; x++){
        plainText[x] = (plainText[x] - 'a' + offset) % 26 + 'a';
    }
    printf("%s\n", plainText);
}

void Decrypt(){
    char cipherText[100];
    printf("Enter the ciphertext: ");
    scanf("%s", cipherText); //I know this is unsafe code
    int length = strlen(cipherText);
    for(int offset = 0; offset < 26; offset++){
        for(int x = 0; x < length; x++){
            cipherText[x] = (cipherText[x] - 'a' + 1) % 26 + 'a';
        }
        printf("\nText #%d: %s\n",offset + 1, cipherText);
    }
}

int main(){
    int choice = 0;
    while (choice != 3){
        printf("1. Encrypt a message\n2. Decrypt a message\n3. Quit Program\nEnter what you want to do: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                Encrypt();
                break;
            case 2:
                Decrypt();
                break;
            case 3:
                printf("Goodbye\n");
                break;
            default:
                printf("Please choose a valid option (1-3)");
                break;
        }
    }
    return 0;
}