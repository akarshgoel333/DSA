class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hvar = hBars[0];
        int hdiff = 2;
        int var = 2;
        for(int i=1; i<hBars.size(); i++){
            if(hBars[i] == hvar+1){
                var++;
            }
            else{
                var = 2;
            }
            hdiff = max(var,hdiff);
            hvar = hBars[i];
        }
        int vdiff = 2;
        int vvar = vBars[0];
        var = 2;
        for(int i=1; i<vBars.size(); i++){
            if(vBars[i] == vvar+1){
                var++;
            }
            else{
                var = 2;
            }
            vdiff = max(var,vdiff);
            vvar = vBars[i];
        }
        return min(hdiff*hdiff,vdiff*vdiff);
    }
};