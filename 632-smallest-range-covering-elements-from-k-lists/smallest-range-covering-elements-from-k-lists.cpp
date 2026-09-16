class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        vector<pair<int,pair<int,int>>>arr;
        int maxi = INT_MIN;
        for(int i=0; i<nums.size(); i++){
            arr.push_back(make_pair(nums[i][0],make_pair(i,0)));
            maxi = max(maxi,nums[i][0]);
        }

        priority_queue< pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> >pq(arr.begin(),arr.end());
        int mini = pq.top().first;
        vector<int>ans = {mini,maxi};
        pair<int,pair<int,int>> res;
        int data,i,j;
        while(true){
            res = pq.top();
            data = res.first;
            i = res.second.first;
            j = res.second.second;
            j++;
            pq.pop();
            if(j == nums[i].size()) break;
            pq.push(make_pair(nums[i][j],make_pair(i,j)));
            maxi = max(maxi,nums[i][j]);
            mini = pq.top().first;
            if(maxi-mini < ans[1]-ans[0]){
                ans[1] = maxi;
                ans[0] = mini;
            }
        }
        return ans;
    }
};