class Fancy {
private:
    const int MODULO = 1'000'000'007;
    vector<int> seq;
    long long multCoeff;
    long long addCoeff;
    vector<pair<long long, long long>> coeffs;

    long long fastPow(long long a, long long n){
        a %= MODULO;
        long long res = 1;
        while(n > 0){
            if(n & 1){
                res = (res * a) % MODULO;
            }
            a = (a * a) % MODULO;
            n >>= 1;
        }
        return res;
    }

    long long modInverse(long long a){
        return fastPow(a, MODULO - 2);
    }

public:
    Fancy() {
        multCoeff = 1;
        addCoeff = 0;
    }
    
    void append(int val) {
        seq.push_back(val);
        coeffs.push_back({multCoeff, addCoeff});
    }
    
    void addAll(int inc) {
        addCoeff = (addCoeff + inc) % MODULO;
    }
    
    void multAll(int m) {
        multCoeff = (multCoeff * m) % MODULO;
        addCoeff = (addCoeff * m) % MODULO;
    }
    
    int getIndex(int idx) {
        if(idx >= (int)seq.size()){
            return -1;
        }

        long long m0 = coeffs[idx].first;
        long long a0 = coeffs[idx].second;
        long long m0Inv = modInverse(m0);
        long long a0Inv = (MODULO - a0 * m0Inv % MODULO) % MODULO;

        long long m = (m0Inv * multCoeff) % MODULO;
        long long a = (a0Inv * multCoeff + addCoeff) % MODULO;

        return (seq[idx] * m + a) % MODULO;
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