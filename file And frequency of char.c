#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *in, *out;
    char ch;

    int word = 0;
    int spc = 0;

    in = fopen("input.txt", "r");
    if (in == NULL) {
        printf("Cannot open source file.\n");
        exit(1);
    }
    out = fopen("output.txt", "w");
    if (out == NULL) {
        printf("Cannot open destination file.\n");
        exit(1);
    }

    int freq[128] = {};        // stores frequency of characters
    int words[128] = {};    // stores number of words having each character

    int seen[128] = {};

    do {
        // read each character from input file
        ch = getc(in);

        // increase frequency of the corresponding character
        freq[ch]++;

        // if character is seen for the first time in current word
        if (!seen[ch])
            words[ch]++;

        // mark character as seen (in current word)
        seen[ch] = 1;

        // if we have encountered any whitespace character
        if (ch == ' ' || ch == '\n' || ch == '\t')
        {
            // reset flag
            for (int i = 0; i < 93; i++)
                seen[i] = 0;

            // increase word frequency
            word++;
        }
    }
    while (!feof(in));

    // print histogram data in the output file
    fputs("character    frequency     word frequency", out);

    for (int i = 65; i <= 90; i++)
    if (freq[i] != 0)
        fprintf(out, "\n%c\t\t\t\t%2d\t\t\t\t%2d", i, freq[i], words[i]);

    for (int i = 97; i <= 122; i++)
    if (freq[i] != 0)
        fprintf(out, "\n%c\t\t\t\t%2d\t\t\t\t%2d", i, freq[i], words[i]);


    for (int i = 48; i <= 57; i++)
    if (freq[i] != 0)
        fprintf(out, "\n%c\t\t\t\t%2d\t\t\t\t%2d", i, freq[i], words[i]);

    fputs("\n\nSpecial characters -\n", out);

    for (int i = 33; i <= 47; i++)
    {
        spc += freq[i];
        if (freq[i] != 0)
            fprintf(out, "\n%c\t\t\t\t%2d", i, freq[i]);
            printf("\n%c\t\t\t\t%2d", i, freq[i]);
    }

    for (int i = 58; i <= 64; i++)
    {
        spc += freq[i];
        if (freq[i] != 0)
            fprintf(out, "\n%c\t\t\t\t%2d", i, freq[i]);
            printf("\n%c\t\t\t\t%2d", i, freq[i]);
    }

    for (int i = 91; i <= 96; i++)
    {
        spc += freq[i];
        if (freq[i] != 0)
            fprintf(out, "\n%c\t\t\t\t%2d", i, freq[i]);
            printf("\n%c\t\t\t\t%2d", i, freq[i]);
    }

    for (int i = 123; i <= 126; i++)
    {
        spc += freq[i];
        if (freq[i] != 0)
            fprintf(out, "\n%c\t\t\t\t%2d", i, freq[i]);
            printf("\n%c\t\t\t\t%2d", i, freq[i]);
    }

    fprintf(out, "\n\nTotal no. of Special characters are %d ", spc);
    fprintf(out, "\n\nTotal no. of words are %d ", word);

    fclose(out);
    fclose(in);

    return 0;
}
