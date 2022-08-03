#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
int dupe[26];
int main(int argc, string argv[])
{
    if (argc == 1 || argc > 2)
    {
        printf("Not enough or too many arguments!\n"); //checks to make sure only one argument, the key, is entered (besides program name)
        return 1;

    }
     if (strlen(argv[1]) != 26 )
    {
        printf("Please provide a valid 26 character key\n"); //invalid if key is not 26 characters
        return 1;
    }
        string cipher = argv[1];
    for (int a = 0; a < 26; a++)  //
    {
        char c = cipher[a];
        if(isalpha(c) == 0 ) //checks to see if all of cipher key is alphabetical
        {
            printf("Please provide a valid 26 character key\n");
            return 1;
        }
    }

    for (int b = 0; b < 26; b++)
    {

        int c1 = toupper(cipher[b]); //convers cipher key to uppercase to check for duplicates in nested for loop below
        dupe[b] = c1;
    }
    for (int an = 0; an < 26; an++)
    {
        for (int dp = 0; dp < 26 && dp != an; dp++)
        {
            if (dupe[an] == dupe[dp] || dupe[an] == dupe[dp] + 26 || dupe[an] == dupe[dp] - 26 ) //checks for duplicates, also possible differences between upper and lower by adding/subtracting 26
            {
                printf("Please provide a valid 26 character key\n");
                return 1;
            }
        }
    }

    string plain = get_string("plaintext:  "); //After passing all previous tests, asks user for input for message to convert
    for (int i = 0; i < strlen(plain); i++)
    {
        if (isupper(plain[i]) != 0)
        {
           int value = plain[i];
           plain[i] = toupper(cipher[value - 65]); //converts each element in user input to the new letter from cipher key, while keeping uppercase letters the same

        }
        else if (islower(plain[i]) != 0)
        {
            int value = plain[i];
            plain[i] = tolower(cipher[value - 97]); ///converts each element in user input to the new letter from cipher key, while keeping lowercase letters the same

        }
    }
    printf("ciphertext: %s\n", plain); //prints out the encrypted message
    return 0;
}
