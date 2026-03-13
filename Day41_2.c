/*
You are given an array of CPU tasks, each labeled with a letter from A to Z, and a number n. Each CPU interval can be idle or allow the completion of one task. Tasks can be completed in any order, but there's a constraint: there has to be a gap of at least n intervals between two tasks with the same label.

Return the minimum number of CPU intervals required to complete all tasks.

 

Example 1:

Input: tasks = ["A","A","A","B","B","B"], n = 2

Output: 8

Explanation: A possible sequence is: A -> B -> idle -> A -> B -> idle -> A -> B.

After completing task A, you must wait two intervals before doing A again. The same applies to task B. In the 3rd interval, neither A nor B can be done, so you idle. By the 4th interval, you can do A again as 2 intervals have passed.

Example 2:

Input: tasks = ["A","C","A","B","D","B"], n = 1

Output: 6

Explanation: A possible sequence is: A -> B -> C -> D -> A -> B.

With a cooling interval of 1, you can repeat a task after just one other task.

Example 3:

Input: tasks = ["A","A","A", "B","B","B"], n = 3

Output: 10

Explanation: A possible sequence is: A -> B -> idle -> idle -> A -> B -> idle -> idle -> A -> B.

There are only two types of tasks, A and B, which need to be separated by 3 intervals. This leads to idling twice between repetitions of these tasks.

 

Constraints:

1 <= tasks.length <= 104
tasks[i] is an uppercase English letter.
0 <= n <= 100
 

*/
#include <stdio.h>

int leastInterval(char* tasks, int tasksSize, int n) {
    int freq[26] = {0};

    // Count frequency of each task
    for (int i = 0; i < tasksSize; i++) {
        freq[tasks[i] - 'A']++;
    }

    // Find max frequency
    int maxFreq = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > maxFreq) {
            maxFreq = freq[i];
        }
    }

    // Count how many tasks have max frequency
    int countMax = 0;
    for (int i = 0; i < 26; i++) {
        if (freq[i] == maxFreq) {
            countMax++;
        }
    }

    int partCount = maxFreq - 1;
    int partLength = n + 1;
    int minLength = partCount * partLength + countMax;

    return (minLength > tasksSize) ? minLength : tasksSize;
}

int main() {
    // Example 1
    char tasks1[] = {'A','A','A','B','B','B'};
    printf("%d\n", leastInterval(tasks1, 6, 2)); // Output: 8

    // Example 2
    char tasks2[] = {'A','C','A','B','D','B'};
    printf("%d\n", leastInterval(tasks2, 6, 1)); // Output: 6

    // Example 3
    char tasks3[] = {'A','A','A','B','B','B'};
    printf("%d\n", leastInterval(tasks3, 6, 3)); // Output: 10

    return 0;
}
