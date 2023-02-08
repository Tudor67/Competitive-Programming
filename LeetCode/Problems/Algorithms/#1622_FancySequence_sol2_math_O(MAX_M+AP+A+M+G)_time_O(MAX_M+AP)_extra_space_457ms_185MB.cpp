class Fancy {
private:
    const long long MODULO = 1e9 + 7;
    const long long MAX_M = 100;
    long long mCoef;
    long long mCoefInv;
    long long aCoef;
    vector<long long> inv;
    vector<long long> seq;

public:
    Fancy() {
        mCoef = 1;
        mCoefInv = 1;
        aCoef = 0;

        inv.assign(MAX_M + 1, 1);
        for(long long i = 2; i <= MAX_M; ++i){
            inv[i] = MODULO - ((MODULO / i) * inv[MODULO % i] % MODULO);
        }
    }
    
    void append(int val) {
        seq.push_back((val - aCoef + MODULO) * mCoefInv % MODULO);
    }
    
    void addAll(int inc) {
        aCoef = (aCoef + inc) % MODULO;
    }
    
    void multAll(int m) {
        mCoef = (mCoef * m) % MODULO;
        mCoefInv = (mCoefInv * inv[m]) % MODULO;
        aCoef = (aCoef * m) % MODULO;
    }
    
    int getIndex(int idx) {
        if(idx >= (int)seq.size()){
            return -1;
        }
        return (seq[idx] * mCoef + aCoef) % MODULO;
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