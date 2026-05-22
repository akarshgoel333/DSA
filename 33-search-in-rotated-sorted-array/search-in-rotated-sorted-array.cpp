class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int start = 0;
        int end = n-1;
        while(start<end){
            int mid = start+(end-start)/2;
            if(nums[mid]>nums.back()) start=mid+1;
            else end=mid; 
        }
        int rot = start;
        start=0, end = n-1;
        while(start<=end){
            int mid = start+(end-start)/2;
            int real = (mid+rot)%n;
            if(nums[real]==target) return real;
            if(nums[real]<target) start=mid+1;
            else end=mid-1;
        }
        return -1;
    }
};