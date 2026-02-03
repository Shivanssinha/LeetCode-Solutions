#include <vector>
using namespace std;

// Problem: 766. Toeplitz Matrix
// Difficulty: Easy
// Platform: LeetCode
//
// Intuition:
// In a Toeplitz matrix, every diagonal from top-left to bottom-right
// must contain the same elements.
// So, each element should be equal to the element diagonally above it.
//
// Approach:
// 1. Start checking from index (1,1) because the first row and first column
//    do not have a top-left diagonal neighbor.
// 2. For every matrix[i][j], compare it with matrix[i-1][j-1].
// 3. If any mismatch is found, return false.
// 4. If all elements satisfy the condition, return true.
// Time Complexity: O(m * n)
// Space Complexity: O(1)

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                if (matrix[i][j] != matrix[i - 1][j - 1]) {
                    return false;
                }
            }
        }
        return true;
    }
};
