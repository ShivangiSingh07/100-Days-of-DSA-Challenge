/*
Question:
Given a string s consisting of lowercase English letters, 
find and return the first character that does not repeat in the string. 
If all characters repeat, return '$'.

Input Format:
A single string s.

Output Format:
Print the first non-repeating character or '$' if none exists.

Sample Input:
geeksforgeeks

Sample Output:
f

Explanation:
The character 'f' occurs only once in the string and appears before any other non-repeating character.
*/

#include <stdio.h>
#include <string.h>

char firstNonRepeatingChar(char *s) {
    int freq[26] = {0};  // Array to store frequency of each lowercase letter

    // Count frequency of each character
    for (int i = 0; s[i] != '\0'; i++) {
        freq[s[i] - 'a']++;
    }

    // Find the first character with frequency 1
    for (int i = 0; s[i] != '\0'; i++) {
        if (freq[s[i] - 'a'] == 1) {
            return s[i];
        }
    }

    // If none found, return '$'
    return '$';
}

int main() {
    char s[100];
    scanf("%s", s);  // Read input string

    char result = firstNonRepeatingChar(s);
    printf("%c\n", result);

    return 0;
}
