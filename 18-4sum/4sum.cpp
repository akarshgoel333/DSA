class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n=nums.size();
        if(n<4) return {};
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        for(int i=0; i<n-3; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int a = nums[i];
            for(int j=i+1; j<n-2; j++){
                if(j>i+1 && nums[j]==nums[j-1]) continue;
                int b = nums[j];
                int start = j+1, end = n-1;
                while(start<end){
                    int c = nums[start], d = nums[end];
                    long long sum = a+b;
                    sum += c+d;
                    if(sum==target){
                        ans.push_back({a,b,c,d});
                        cout<<i<<j<<start<<end<<endl;
                        while(nums[start]==c && end>start) start++;
                        while(start<end && nums[end]==d) end--;
                    }
                    else if(sum<target) start++;
                    else end--;
                }
            }
        }
        return ans;
    }
};