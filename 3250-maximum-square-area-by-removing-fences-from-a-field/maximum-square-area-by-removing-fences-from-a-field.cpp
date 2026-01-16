class Solution {
public:
    int maximizeSquareArea(int m, int n, vector<int>& hF, vector<int>& vF) {
        const int MOD = 1e9 + 7;

        // Add borders
        hF.push_back(1);
        hF.push_back(m);
        vF.push_back(1);
        vF.push_back(n);

        sort(hF.begin(), hF.end());
        sort(vF.begin(), vF.end());

        unordered_set<long long> hcnt;

        for (int i = 0; i < hF.size(); i++) {
            for (int j = i + 1; j < hF.size(); j++) {
                hcnt.insert((long long)hF[j] - hF[i]);
            }
        }

        long long ans = -1;

        for (int i = 0; i < vF.size(); i++) {
            for (int j = i + 1; j < vF.size(); j++) {
                long long d = (long long)vF[j] - vF[i];
                if (hcnt.count(d)) {
                    ans = max(ans, d);
                }
            }
        }

        if (ans == -1) return -1;
        return (int)((ans % MOD) * (ans % MOD) % MOD);
    }
};
