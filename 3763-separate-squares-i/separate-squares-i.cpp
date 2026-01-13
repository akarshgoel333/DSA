class Solution {
public:
    double separateSquares(vector<vector<int>>& squares) {
        int n = squares.size();
        double low = 1e9;
        double high = -1;
        for(int i=0; i<n; i++){
            low = min(low,(double)squares[i][1]);
            high = max(high,(double)(squares[i][1]+squares[i][2]));
        }
        
        while(high-low>1e-6){
            double mid = low + (high-low)/2;
            double upper = 0;
            double lower = 0;
            for(int i=0; i<n; i++){
                if(mid-squares[i][1]<=squares[i][2] && mid-squares[i][1]>=0){
                    upper += 1.0*(squares[i][1]+squares[i][2]-mid)*squares[i][2];
                    lower += 1.0*(mid-squares[i][1])*squares[i][2];
                }
                else if(mid >= squares[i][1] + squares[i][2]){
                lower += 1.0*squares[i][2]*squares[i][2];
                }
                else upper += 1.0*squares[i][2]*squares[i][2];
            }

            if(upper>lower) low = mid;
            else high = mid;
            cout<<mid<<" ";
        }
        return (low+high)/2;
    }
};