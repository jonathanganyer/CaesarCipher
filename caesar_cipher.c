#include <stdio.h>
void caesar(char *plaintext, char *ciphertext, int key, int crypt);

int main(void)
{
    do
    {
        char intext[32],outtext[32]= {'\0'};
        int key;
        char crypt;
        int crypt_mode=0;
        printf("\nEnter your plaintext/ciphertext: ");
        scanf("%s", intext);
        getchar();
        printf("Encrypt or Decrypt (e/d)? ");
        crypt = getchar();
        if(crypt=='e')
        {
            crypt_mode=1;
        }
        else
        {
            crypt_mode=0;
        }
        printf("Enter a cipher key (0-25): ");
        scanf("%d", &key);
        getchar();
        caesar(intext,outtext,key,crypt_mode);
        printf("The ciphertext is: %s \n", outtext);
        printf("Use again (y/n)? ");
    }
    while(getchar() != 'n');
}

void caesar(char *plaintext, char *ciphertext, int key, int crypt)
{
    int i=0;
    int new_letter;
    char alphabet[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    while(*(plaintext+i) != '\0')
    {
        if(crypt==1)
            new_letter = ((*(plaintext+i)-97)+key)%26;    //'a' begins at 97 decimal, offset to 0.
        else
        {
            new_letter = ((*(plaintext+i)-97)-key)%26;    //'a' begins at 97 decimal, offset to 0.
            if(new_letter<0)
                new_letter=new_letter+26;
        }
        *(ciphertext+i)=alphabet[new_letter];
        i++;
    }

}

