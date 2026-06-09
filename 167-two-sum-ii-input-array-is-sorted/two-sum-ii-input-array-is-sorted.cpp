class Solution {
public:
    vector<int> twoSum(vector<int>& num, int tar) {
        int n = num.size();
        int st = 0, end = n-1;
        while(st<end){
            if(num[st]+num[end]==tar) return {st+1,end+1};
            else if(num[st]+num[end]<tar) st++;
            else end--;
        }
        return {0,0};
    }
};