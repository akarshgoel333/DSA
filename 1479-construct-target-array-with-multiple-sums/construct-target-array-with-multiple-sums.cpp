class Solution {
public:
    bool isPossible(vector<int>& target) {
        priority_queue<long long>pq(target.begin(),target.end());
        long long sumi = accumulate(target.begin(),target.end(),0LL);
        long long maxE, rem, newE;
        while(pq.top()>1){
            maxE = pq.top();
            rem = sumi - maxE;
            if(rem<=0 || rem>=maxE) return false;
            newE = maxE % rem;
            if(newE==0){
                if(rem!=1) return false;
                else return true;
            }
            sumi = rem + newE; 
            pq.pop();
            pq.push(newE);
        }
        return true;
    }
};