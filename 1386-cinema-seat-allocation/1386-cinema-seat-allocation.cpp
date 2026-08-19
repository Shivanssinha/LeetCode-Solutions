class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, unordered_set<int>> mp;

        for (auto& seat : reservedSeats) {
            mp[seat[0]].insert(seat[1]);
        }

        int ans = 2 * n;

        for (auto& row : mp) {
            auto& reserved = row.second;

            bool left = true;
            bool right = true;
            bool middle = true;

            for (int seat = 2; seat <= 5; seat++) {
                if (reserved.count(seat)) {
                    left = false;
                }
            }

            for (int seat = 4; seat <= 7; seat++) {
                if (reserved.count(seat)) {
                    middle = false;
                }
            }

            for (int seat = 6; seat <= 9; seat++) {
                if (reserved.count(seat)) {
                    right = false;
                }
            }

            if (left && right) {
            }
            else if (left || right || middle) {
                ans--;
            }
            else {
                ans -= 2;
            }
        }

        return ans;
    }
};