class Solution {
public:
    string result = "";
    char midchar = '$';
    int half = 0;
    bool solve(string &curr, vector<int>&freq, string &target, int i, bool gr8){
        if(curr.length()==half){
            string left = curr;
            string right = curr;
            reverse(right.begin(),right.end());
            if(midchar!='$') left += midchar;
            left += right;
            if(left>target){
                result = left;
                return true;
            }
            return false;
        }
        for(char ch='a'; ch<='z'; ch++){
            if(freq[ch-'a']==0) continue;
            if(!gr8 && target[i]>ch) continue;
            curr.push_back(ch);
            freq[ch-'a']--;
            gr8 = gr8 || ch>target[i];
            if(solve(curr,freq,target,i+1,gr8)) return true;
            curr.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int>freq(26,0);
        for(auto ch: s) freq[ch-'a']++;
        int odd = 0;
        for(int i=0; i<26; i++){
            if(freq[i]%2!=0){
                odd++;
                midchar = 'a'+i;
            }
            freq[i] /= 2;
        }
        if(odd>1) return result;
        half = target.length()/2;
        string curr = "";
        solve(curr,freq,target,0,false);
        
        return result;
    }
};