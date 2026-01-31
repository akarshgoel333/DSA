class Solution {
public:
    char nextGreatestLetter(vector<char>& ltr, char tgt) {
        char ans = ltr[0];
        int i=0, j=ltr.size()-1;
        while(i<=j){
            int mid = i + (j-i)/2;
            if(ltr[mid]>tgt){
                ans = ltr[mid];
                j = mid-1;
            }
            else i = mid+1;
        }
        return ans;
    }
};