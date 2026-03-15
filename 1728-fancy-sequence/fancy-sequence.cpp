class Fancy {
public:
    typedef long long ll;

    ll mod = 1e9 + 7;
    vector<ll>seq;
    ll add = 0;
    ll mul = 1;

    long long power(int a, int b){
        if(b==0) return 1;
        long long half = power(a,b/2);
        long long result = (half*half) % mod;
        if(b%2==1) result = (result*a) % mod;
        return result;
    }
    Fancy() {
    }
    
    void append(int val) {
        ll x = (((val-add) % mod + mod) * power(mul,mod-2)) % mod;
        seq.push_back(x);
    }
    
    void addAll(int inc) {
        add = (add+inc) % mod;
    }
    
    void multAll(int m) {
        mul = (mul*m)%mod;
        add = (add*m)%mod;
    }
    
    int getIndex(int idx) {
        if(idx>=seq.size()) return -1;
        return ((seq[idx]*mul)+add)%mod;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */