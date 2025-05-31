//approach-1 : recursion +memorisation
class Solution {
public:
    unordered_map<int, int> mpp;
    bool helper(vector<int>& stones, int curr, int gap,
                vector<vector<int>>& dp) {
        int n = stones.size();
        if (dp[curr][gap] != -1) {
            return dp[curr][gap];
        }
        if (curr == n - 1)
            return true;
        bool result = false;
        for (int next = gap - 1; next <= gap + 1; next++) {
            if (next > 0) {
                int next_stone = stones[curr] + next;
                if (mpp.find(next_stone) != mpp.end()) {
                    result =
                        result || helper(stones, mpp[next_stone], next, dp);
                }
            }
        }
        return dp[curr][gap] = result;
    }
    bool canCross(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) {
            return false;
        }

        for (int i = 0; i < stones.size(); ++i)
            mpp[stones[i]] = i;
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return helper(stones, 0, 0, dp);
    }
};
