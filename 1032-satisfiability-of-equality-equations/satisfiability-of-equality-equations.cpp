class Solution {
public:
    vector<int>parent,rank;
    int find(int i){
        if(i==parent[i]) return i;
        return parent[i] = find(parent[i]);
    }
    void Union(int i, int j){
        int xp = find(i);
        int yp = find(j);
        if(xp==yp) return;
        if(rank[xp]>rank[yp]) parent[yp]=xp;
        else if(rank[xp]<rank[yp]) parent[xp]=yp;
        else{
            parent[xp]=yp;
            rank[yp]++;
        }
    }
    bool equationsPossible(vector<string>& eqs) {
        int n = eqs.size();
        parent.resize(26);
        rank.resize(26);
        for(int i=0; i<26; i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(string &s: eqs){
            int x = s[0]-'a';
            int y = s[3]-'a';
            int sign = s[1];
            if(sign == '=') Union(x,y);
        }
        for(string &s: eqs){
            int x = s[0]-'a';
            int y = s[3]-'a';
            int sign = s[1];
            if(sign == '!'){
                int xp = find(x);
                int yp = find(y);
                if(xp==yp) return false;
            }
        }
        return true;
    }
};