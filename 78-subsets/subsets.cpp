class Solution {
public:
    void subseq(vector<int>&arr, int idx, int end, vector<vector<int>>&ans, vector<int>&temp){
        if(idx==end){
            ans.push_back(temp);
            return;
        }
        subseq(arr,idx+1,end,ans,temp);
        temp.push_back(arr[idx]);
        subseq(arr,idx+1,end,ans,temp);
        temp.pop_back();
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        subseq(nums,0,nums.size(),ans,temp);
        return ans;
    }
};