class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long long y = mass;
        sort(asteroids.begin(),asteroids.end());
        for(auto &x: asteroids){
            if(y>=x) y += x;
            else return false;
        }
        return true;
    }
};