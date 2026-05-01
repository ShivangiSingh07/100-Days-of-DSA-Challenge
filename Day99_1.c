/*
Problem:
Given a target distance and arrays of car positions and speeds,
compute the number of car fleets that will arrive at the destination.

Definition:
- A car fleet is a group of cars traveling together at the same speed.
- If a faster car catches up to a slower car before reaching the target,
  they form a single fleet and travel together.

Approach:
1. Pair each car’s position and speed.
2. Sort cars by position in descending order (closest to target first).
3. Compute time = (target - position) / speed for each car.
4. Traverse cars:
   - If current car’s time > last fleet time, it forms a new fleet.
   - Otherwise, it joins the existing fleet.
5. Return the number of fleets.

Input:
- First line: integer n (number of cars)
- Second line: integer target (destination distance)
- Next line: n space-separated integers (positions)
- Next line: n space-separated integers (speeds)

Output:
- Number of car fleets

Example:
Input:
4
12
10 8 0 5
2 4 1 1

Output:
3
Explanation:
Car at 10 (time=1) forms fleet 1.
Car at 8 (time=1) joins fleet 1.
Car at 5 (time=7) forms fleet 2.
Car at 0 (time=12) forms fleet 3.
*/

#include <stdio.h>
#include <stdlib.h>

// Structure to hold car info
typedef struct {
    int position;
    int speed;
} Car;

// Comparator for sorting cars by position descending
int cmp(const void* a, const void* b) {
    return ((Car*)b)->position - ((Car*)a)->position;
}

int carFleet(int target, int position[], int speed[], int n) {
    Car cars[n];
    for (int i = 0; i < n; i++) {
        cars[i].position = position[i];
        cars[i].speed = speed[i];
    }

    // Sort cars by position descending
    qsort(cars, n, sizeof(Car), cmp);

    int fleets = 0;
    double lastTime = -1.0;

    for (int i = 0; i < n; i++) {
        double time = (double)(target - cars[i].position) / cars[i].speed;
        if (time > lastTime) {
            fleets++;
            lastTime = time;
        }
        // else: car joins the fleet ahead
    }
    return fleets;
}

int main() {
    int n, target;
    scanf("%d", &n);
    scanf("%d", &target);

    int position[n], speed[n];
    for (int i = 0; i < n; i++) scanf("%d", &position[i]);
    for (int i = 0; i < n; i++) scanf("%d", &speed[i]);

    printf("%d\n", carFleet(target, position, speed, n));
    return 0;
}
