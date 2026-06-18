class Solution {
public:
    double angleClock(int hr, int mint) {
        double hagl = hr%12 + (double)mint/60;
        hagl *= 30;
        double magl = mint*6;
        double res = abs(hagl-magl);
        if(res<=180) return res;
        return 360-res;
    }
};