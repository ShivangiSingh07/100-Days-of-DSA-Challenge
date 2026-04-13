/*
Problem Statement:
Given a string s consisting of lowercase letters,
find the first repeated character in the string.
A character is considered repeated if it appears more than once,
and among all such characters, the one whose second occurrence
has the smallest index should be returned.

Input Format:
A single string s.

Output Format:
Print the first repeated character.
If no character is repeated, print -1.

Sample Input:
geeksforgeeks

Sample Output:
e
*/

#include <stdio.h>
#include <string.h>

char firstRepeatedChar(char *s) {
    int seen[256] = {0};  // ASCII frequency tracker
    for (int i = 0; s[i] != '\0'; i++) {
        if (seen[(unsigned char)s[i]]) {
            return s[i];  // First repeated character found
        }
        seen[(unsigned char)s[i]] = 1;
    }
    return -1;  // No repeated character
}

int main() {
    char s[1000];
    scanf("%s", s);  // Read input string
    
    char result = firstRepeatedChar(s);
    if (result == -1)
        printf("-1\n");
    else
        printf("%c\n", result);
    
    return 0;
}
