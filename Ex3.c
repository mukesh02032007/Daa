#include <stdio.h>
#include <string.h>
void search(char pat[], char txt[])
{
    int i, j;
    int n = strlen(txt);
    int m = strlen(pat);
    // Loop through text
    for (i = 0; i <= n - m; i++)
    {
        // Check pattern match
        for (j = 0; j < m; j++)
        {
            if (txt[i + j] != pat[j])
                break;
        }
        // If pattern found
        if (j == m)
        {
            printf("Pattern found at index %d\n", i);
        }
    }
}
int main()
{
    char txt[100], pat[100];
    printf("Enter the text: ");
    gets(txt);
    printf("Enter the pattern: ");
    gets(pat);
    search(pat, txt);
    return 0;
}
