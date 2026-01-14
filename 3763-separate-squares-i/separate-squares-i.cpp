class Solution {
public:
    bool check(vector<vector<int>>& squares, double total, double mid){
        double bott = 0.0;
        for(auto &sq: squares){
            double y = sq[1];
            double l = sq[2];
            if(mid >= (y+l)) bott += l*l;
            else if(mid > y) bott += (mid-y)*l;
        }
        return (bott >= (total)/2.0);
    }
    double separateSquares(vector<vector<int>>& squares) {
        double low = INT_MAX;
        double high = INT_MIN;
        double total = 0.0;
        for(auto &sq : squares){
            double x = sq[0];
            double y = sq[1];
            double l = sq[2];

            total += l*l;
            
            low = min(low,y);
            high = max(high,y+l);
        }
        
        double res = 0.0;
        while(high-low>1e-5){
            double mid = low + (high-low)/2.0;
            
            if(check(squares,total,mid)==true){
                res = mid;
                high = mid;
            }
            else low = mid;
        }
        return res;
    }
};