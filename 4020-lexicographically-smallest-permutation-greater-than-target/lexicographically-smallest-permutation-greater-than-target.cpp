class Solution {
public:
    string ans = "";
    bool solve(string &curr, vector<int>&freq, int i, string &target, bool gr8){
        if(i==target.length()){
            if(gr8){
                ans = curr;
                return true;
            }
            return false;
        }
        for(char ch='a'; ch<='z'; ch++){
            if(freq[ch-'a']==0) continue;
            if(!gr8 && ch<target[i]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;
            bool isgr8 = gr8 || ch>target[i];

            if(solve(curr,freq,i+1,target,isgr8)) return true;

            curr.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int>freq(26,0);
        for(auto ch: s) freq[ch-'a']++;
        string curr = "";
        solve(curr,freq,0,target,false);
        return ans;
    }
};