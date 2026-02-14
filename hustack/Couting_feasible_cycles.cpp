// Given n points on a plane, each point i has coordinates x[i] and y[i], count the number of cycles that start from a point, visit all the (n-1) other points exactly once, and return to the starting point, such that the total distance of the cycle is less than or equal to a given number L. Note that, the distance from point i to point j is the Manhattan distance |x[i] - x[j]| + |y[i] - y[j]|
// Input:
// Line 1: An integersn (1 ≤ n ≤ 15).
// Line i+1: Contains two integers, , separated by a space, for the coordinates (x[i] and y[i]) of point i (0≤ x[i], y[i] ≤ 100).
// Line n+2: contains an integer L (1 ≤ L ≤ 100000).
// Output:
// One integer for the number of feasible cycles
// Example:
// Input
// 5
// 41 67
// 34 0
// 69 24
// 78 58
// 62 64
// 222
// Output
// 2