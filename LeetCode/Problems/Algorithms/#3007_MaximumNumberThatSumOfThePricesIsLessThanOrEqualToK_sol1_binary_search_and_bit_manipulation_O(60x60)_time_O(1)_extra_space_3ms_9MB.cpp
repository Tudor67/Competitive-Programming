class Solution {
private:
    long long countTotalBitsAt(long long num, long long bit){
        long long blockSize = 1LL << bit;
        long long blocks = (num + 1) / blockSize;
        
        long long totalBits = (blocks / 2) * blockSize;
        if(blocks % 2 == 1){
            totalBits += (num + 1) % blockSize;
        }
        
        return totalBits;
    }
    
public:
    long long findMaximumNumber(long long k, int x) {
        long long l = 0;
        long long r = 1e16;
        while(l != r){
            long long mid = (l + r + 1) / 2;
            long long totalBits = 0;
            for(long long bit = x - 1; (mid >> bit) > 0; bit += x){
                totalBits += countTotalBitsAt(mid, bit);
            }
            if(totalBits <= k){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        return r;
    }
};