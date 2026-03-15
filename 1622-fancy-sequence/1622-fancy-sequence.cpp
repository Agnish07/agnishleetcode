class Fancy {
public:
    long long add = 0;
    long long mul = 1;
    long long MOD = 1e9+7;
    vector<long long> seq;

    long long power(long long a, long long b){
        if(b == 0) return 1;
        long long half = power(a, b/2);
        long long result = (half * half) % MOD;

        if(b%2 == 1){
            result = (result*a) % MOD;
        }

        return result;
    }

    Fancy() {
        
    }
    
    void append(int val) {
        seq.push_back(((val-add + MOD) % MOD * power(mul, MOD-2)%MOD));
    }
    
    void addAll(int inc) {
        add = (add + inc) % MOD;
    }
    
    void multAll(int m) {
        add = (add * m) % MOD;
        mul =  (mul * m) % MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= seq.size()) return -1;
        int x = seq[idx];
        return ((x*mul)+add) % MOD;
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