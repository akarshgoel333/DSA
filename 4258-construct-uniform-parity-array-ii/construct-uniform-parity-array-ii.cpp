class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        int eve = 0;
        for(int x: nums1){
            if(x%2==0) eve++;
            else odd++;
        }
        if(odd==0 || eve==0) return true;
        int mini = *min_element(nums1.begin(),nums1.end());
        if(mini%2!=0) return true;
        return false;
    }
};