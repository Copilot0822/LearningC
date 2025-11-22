#include <stdio.h>
int arr[100] = {-1};
int main(int argc, char const *argv[])
{
    /* code */
    for (int i = 0; i < 100; i++)
    {
        arr[i] = -1;
    }

    char word[100] = " ";

    printf("Enter String: ");

    scanf("%s", word);
    printf("\n");
    printf("Result after vowel reversal:\n");


    numVowels(word);
    // printf("\n\n");
    for (int i = 0; i < 100; i++)
    {
        // printf("%d\n", arr[i]);
    }

    int num;
    for (int i = 0; i < 100; i++)
    {
        if (arr[i] == -1)
        {
            num = i;
            break;
        }
    }

    // printf("%d", num);

    char newword[100] = {0};
    // newword = word;

    for (size_t i = 0; i < 100; i++)
    {
        newword[i] = word[i];
    }
    for (int i = 0; i < 100; i++)
    {
        // printf("%c", newword[i]);
    }

    printf("original: %s\n", word);


    printf("vowels reversed: ");
    for (int i = 0; i < num; i++)
    {
        newword[arr[i]] = word[arr[num - i -1]];
    }

    // printf("\n\n\n");
    for (int i = 0; i < 100; i++)
    {
        printf("%c", newword[i]);
    }

    // printf("%s", newword);

    return 0;
}
// int arr[100] = {-1};
int numVowels(char word[100])
{
    int numv = 0;
    // int arr[100] = {-1};

    for (int i = 0; i < 100; i++)
    {
        if (word[i] == 0)
        {
            break;
        }
        if (word[i] == 'a' || word[i] == 'e' || word[i] == 105 || word[i] == 111 || word[i] == 117 || word[i] == 'A' || word[i] == 'E' || word[i] == 'I' || word[i] == 'O' || word[i] == 'U')
        {
            for (int j = 0; j < 100; j++)
            {
                if (arr[j] == -1)
                {
                    arr[j] = i;
                    break;
                }
            }
            numv++;
        }

        // printf("%d\n", word[i]);
    }

    // printf("%d", numv);
    return numv;
}