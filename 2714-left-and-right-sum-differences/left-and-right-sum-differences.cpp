class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        vector<int>arr(n,0);
        for(int i=1; i<n; i++){
            arr[i] += nums[i-1]+arr[i-1];
        }
        int sum = 0;
        for(int i=n-2; i>=0; i--){
            sum += nums[i+1];
            arr[i] = abs(arr[i]-sum);
        }
        return arr;
    }
};