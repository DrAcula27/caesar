#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    //check user entered a single command-line argument.
    if (argc == 2)
    {
        //check user single command-line argument is all integers.
        bool valid = true;
        for (int i = 0, len = strlen(argv[1]); i < len; i++)
        {
            if (isdigit(argv[1][i]) == 0) //isdigit returns 0 when character is non-numeric.
            {
                valid = false;
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
        //convert the command-line argument to an int.
        if (valid == true)
        {
            int key = atoi(argv[1]); //atoi converts strings to ints.

            //prompt user for text to code (plaintext).
            string plaintext = get_string("plaintext: ");

            //change plaintext to ciphertext by iterating through user's plaintext string.
            //need to preserve case, and only change alphabetical characters.
            printf("ciphertext: ");
            for (int j = 0, k = strlen(plaintext); j < k; j++)
            {
                bool upper = isupper(plaintext[j]); //for use with uppercase chars.
                bool lower = islower(plaintext[j]); //for use with lowercase chars.
                int index, c, p = plaintext[j];
                if (isalpha(p))
                {
                    if (upper == true)
                    {
                        index = p - 65; //to normalize an index to "wrap around" from Z to A using the key.
                        c = (index + key) % 26; //for large number inputs.
                        c += 65; //add ascii value for A back after adding the key.
                        printf("%c", c);
                    }
                    else if (lower == true)
                    {
                        index = p - 97;
                        c = (index + key) % 26;
                        c += 97;
                        printf("%c", c);
                    }
                }
                else
                {
                    printf("%c", p);
                }
            }
        //print a new line after all code runs.
        printf("\n");
        }
        else
        {
            valid = false;
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}