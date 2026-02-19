/*
Problem: Given an array of integers, find two elements whose sum is closest to zero.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the pair of elements whose sum is closest to zero

Example:
Input:
5
1 60 -10 70 -80

Output:
-10 1

Explanation: Among all possible pairs, the sum of -10 and 1 is -9, which is the closest to zero compared to other pairs.
*/
using System;

class PairSumClosestToZero
{
    static void Main()
    {
        // Read input size
        int n = int.Parse(Console.ReadLine());
        
        // Read array elements
        string[] input = Console.ReadLine().Split(' ');
        int[] arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            arr[i] = int.Parse(input[i]);
        }

        // Sort the array for two-pointer approach
        Array.Sort(arr);

        int left = 0;
        int right = n - 1;
        int minSum = int.MaxValue;
        int minLeft = left, minRight = right;

        // Two-pointer traversal
        while (left < right)
        {
            int sum = arr[left] + arr[right];

            if (Math.Abs(sum) < Math.Abs(minSum))
            {
                minSum = sum;
                minLeft = left;
                minRight = right;
            }

            // Move pointers based on sum
            if (sum < 0)
                left++;
            else
                right--;
        }

        // Print the pair
        Console.WriteLine($"{arr[minLeft]} {arr[minRight]}");
    }
}
