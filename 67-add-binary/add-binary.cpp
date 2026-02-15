class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.length(), n2 = b.length();
        string ans = "";
        int carry = 0;
        int i=n2-1, j=n1-1;
        while(i>=0 || j>=0 || carry){
            int sum = carry;
            if(j>=0) sum += a[j--]-'0';
            if(i>=0) sum += b[i--]-'0';
            ans += (sum%2)+'0';
            carry = sum/2;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};