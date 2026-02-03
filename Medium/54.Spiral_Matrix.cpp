#include <vector>
using namespace std;

// Problem: 54. Spiral Matrix
// Difficulty: Medium
// Platform: LeetCode
//
// Intuition:
// The spiral order traversal can be simulated by maintaining four boundaries:
// top, bottom, left, and right.
// At each step, we traverse one side of the current boundary and then shrink it.
// This continues until all elements are visited.
//
// Approach:
// 1. Initialize four pointers: top, bottom, left, right.
// 2. Traverse from left to right along the top row, then move top down.
// 3. Traverse from top to bottom along the right column, then move right left.
// 4. Traverse from right to left along the bottom row (if valid), then move bottom up.
// 5. Traverse from bottom to top along the left column (if valid), then move left right.
// 6. Repeat while the boundaries are valid.
// Time Complexity: O(m * n)
// Space Complexity: O(1) extra space (excluding output array)

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        vector<int> ans;

        while (top <= bottom && left <= right) {

            // Traverse top row (left → right)
            for (int c = left; c <= right; c++) {
                ans.push_back(matrix[top][c]);
            }
            top++;

            // Traverse right column (top → bottom)
            for (int r = top; r <= bottom; r++) {
                ans.push_back(matrix[r][right]);
            }
            right--;

            // Traverse bottom row (right → left), if still valid
            if (top <= bottom) {
                for (int c = right; c >= left; c--) {
                    ans.push_back(matrix[bottom][c]);
                }
                bottom--;
            }

            // Traverse left column (bottom → top), if still valid
            if (left <= right) {
                for (int r = bottom; r >= top; r--) {
                    ans.push_back(matrix[r][left]);
                }
                left++;
            }
        }

        return ans;
    }
};
