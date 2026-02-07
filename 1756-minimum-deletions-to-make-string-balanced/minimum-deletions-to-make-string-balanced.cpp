class Solution {
public:
    int minimumDeletions(string s) {
        int bba=0, del=0;
        for(auto cc: s){
            if(cc == 'b'){
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