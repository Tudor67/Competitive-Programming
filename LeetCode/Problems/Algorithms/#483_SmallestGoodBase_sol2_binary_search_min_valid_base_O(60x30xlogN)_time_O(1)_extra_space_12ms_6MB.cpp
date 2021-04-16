class Solution {
private:
    long long geoSum(const long long& BASE, const long long& MAX_POW, const long long& N){
        long long s = 0;
        long long p = 1;
        for(int currentPow = 0; currentPow <= MAX_POW; ++currentPow){
            s += p;
            if(currentPow < MAX_POW){
                if(p > (N - s) / BASE){
                    return LLONG_MAX;
                }
                p *= BASE;
            }
        }
        return s;
    }
    
public:
    string smallestGoodBase(string n) {
        const long long MAX_POW = 60;
        const long long N = stoll(n);
        long long minValidBase = N - 1;
        for(int currentPow = 1; currentPow <= MAX_POW; ++currentPow){
            long long l = 2;
            long long r = N;
            while(l != r){
                long long mid = (l + r + 1) / 2;
                if(geoSum(mid, currentPow, N) <= N){
                    l = mid;
                }else{
                    r = mid - 1;
                }
            }
            if(geoSum(r, currentPow, N) == N){
                minValidBase = min(r, minValidBase);
            }
        }
        return to_string(minValidBase);
    }
};