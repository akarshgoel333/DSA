class Solution {
public:
    int minimumDeletions(string s) {
        int n = s.length();
        int bba=0, del=0;
        for(int i=0; i<n; i++){
            if(s[i]=='b'){
                bba++;
            }
            else if(bba>0){
                bba--;
                del++;
            }
        }
        return del;
    }
};