class Fancy {
private:
    const long long MODULO = 1e9 + 7;
    vector<long long> vals;
    vector<long long> startOperationIndex;
    vector<long long> aPrefSum;
    vector<long long> mPrefProd;

    long long fastPow(long long a, long long n){
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
        aPrefSum = {0};
        mPrefProd = {1};
    }
    
    void append(int val) {
        vals.push_back(val);
        startOperationIndex.push_back(aPrefSum.size());
    }
    
    void addAll(int inc) {
        aPrefSum.push_back((aPrefSum.back() + inc) % MODULO);
        mPrefProd.push_back(mPrefProd.back());
    }
    
    void multAll(int m) {
        aPrefSum.push_back((aPrefSum.back() * m) % MODULO);
        mPrefProd.push_back((mPrefProd.back() * m) % MODULO);
    }
    
    int getIndex(int idx) {
        if(idx >= (int)vals.size()){
            return -1;
        }
        int opIndex = startOperationIndex[idx] - 1;
        long long mProd = mPrefProd.back() * modInverse(mPrefProd[opIndex]) % MODULO;
        long long aSum = (aPrefSum.back() - (aPrefSum[opIndex] * mProd % MODULO) + MODULO) % MODULO;
        return (vals[idx] * mProd + aSum) % MODULO;
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