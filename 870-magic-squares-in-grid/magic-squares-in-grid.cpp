class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int i=0, j=0;
        int cnt = 0;
        while(j<m-2){
            i=0;
            while(i<n-2){
                bool five = false;
                bool flag = true;
                for(int a=i; a<i+3; a++){
                    for(int b=j; b<j+3; b++){
                        if(grid[a][b]==5){
                            if(!five) five=true;
                            else{
                                flag=false;
                            }
                        }
                        if(grid[a][b]<=0 || grid[a][b]>9){
                            flag=false;
                        }
                        if(!flag) break;
                    }
                    // cout<<flag<<" ";
                }
                if(grid[i+1][j+1]==5 && flag){
                    if(grid[i][j]+grid[i+1][j]+grid[i+2][j]==15 && grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]==15 && grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]==15 && grid[i][j]+grid[i][j+1]+grid[i][j+2]==15 && grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]==15){
                        cnt++;
                        // cout<<i<<" "<<j<<endl;
                    }
                }
                i++;
            }
            j++;
        }
        return cnt;
    }
};