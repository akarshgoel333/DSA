class Solution {
public:
    vector<int> twoSum(vector<int>& num, int tar) {
        int st = 0, end = num.size()-1;
        while(st<end){
            int sum = num[st]+num[end];
            if(sum==tar) return {st+1,end+1};
            else if(sum<tar) st++;
            else end--;
        }
        return {};
    }
};