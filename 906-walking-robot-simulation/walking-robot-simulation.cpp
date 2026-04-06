class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<string>obz;
        for(auto &obs: obstacles){
            string str = to_string(obs[0])+" "+to_string(obs[1]);
            obz.insert(str);
        }
        int x = 0;
        int y = 0;
        int maxD = 0;
        vector<pair<int,int>>dir = {{0,1},{1,0},{0,-1},{-1,0}};
        int d = 0;
        for(int i=0; i<commands.size(); i++){
            if(commands[i]==-2){
                d = (d+3)%4;
            }
            else if(commands[i]==-1){
                d = (d+1)%4;
            }
            else{
                for(int step=0; step<commands[i]; step++){
                    int newx = x+dir[d].first;
                    int newy = y+dir[d].second;
                    string nxtstep = to_string(newx)+" "+to_string(newy);
                    if(obz.find(nxtstep) != obz.end()){
                        break;
                    }
                    x=newx;
                    y=newy;
                }
            }
            maxD = max(maxD, x*x + y*y);
        }
        return maxD;
    }
};