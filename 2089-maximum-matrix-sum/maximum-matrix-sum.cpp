class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long sum = 0;
        int minAbsolute = INT_MAX;
        int negative = 0;

        for (const vector<int>& nums : matrix) {
            for (int num : nums) {
                if (num < 0) {
                    negative++;
                }

                minAbsolute = min(abs(num), minAbsolute);
                sum += abs(num);
            }
        }
        
        if (negative % 2 == 0) {
            return sum;
        }
        else {
            return sum - 2 * minAbsolute;
        }
    }
};