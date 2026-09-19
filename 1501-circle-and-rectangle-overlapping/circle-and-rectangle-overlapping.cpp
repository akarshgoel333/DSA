class Solution {
public:
    bool checkOverlap(int r, int xc, int yc, int x1, int y1, int x2, int y2) {
        if((y2<yc-r) || (y1>yc+r)) return false;
        if((x2<xc-r) || (x1>xc+r)) return false;
        int dist1 = pow(xc-x1,2)+pow(yc-y1,2);
        int dist2 = pow(xc-x2,2)+pow(yc-y2,2);
        int dist3 = pow(xc-x2,2)+pow(yc-y1,2);
        int dist4 = pow(xc-x1,2)+pow(yc-y2,2);
        int rad = pow(r,2)+pow((x2-x1)/2,2)+pow((y2-y1)/2,2);
        return ((dist1<=rad) || (dist2<=rad) || (dist3<=rad) || (dist4<=rad));
    }
};