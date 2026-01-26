class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        int mini = INT_MAX;
        sort(arr.begin(),arr.end());
        vector<vector<int>> ans;
        for(int i=0; i<n-1; i++){
            if(arr[i+1]-arr[i]<mini){
                mini = min(arr[i+1]-arr[i],mini);
                ans.clear();
                ans.push_back({arr[i],arr[i+1]});
            }
            else if(arr[i+1]-arr[i]==mini){
                ans.push_back({arr[i],arr[i+1]});
            }
        }
        return ans;
    }
};