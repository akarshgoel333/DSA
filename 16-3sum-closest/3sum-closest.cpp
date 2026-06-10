class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        int ans = nums[0]+nums[1]+nums[2];
        int n = nums.size();
        for(int i=0; i<n-2; i++){
            int st=i+1, end=n-1;
            while(st<end){
                int sum = nums[i]+nums[st]+nums[end];
                int mini = abs(target-sum);
                if(abs(target-sum)<abs(target-ans)){
                    ans = sum;
                }
                if(sum==target) return target;
                if(sum>target) end--;
                else st++;
                
            }
        }
        return ans;
    }
};