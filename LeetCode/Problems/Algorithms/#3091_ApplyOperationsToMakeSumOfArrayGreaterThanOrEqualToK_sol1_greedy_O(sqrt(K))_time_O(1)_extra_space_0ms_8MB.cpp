class Solution {
public:
    int minOperations(int k) {
        int minOps = k;
        for(int i = 1; i <= k && i - 1 <= minOps; ++i){
            int ops = (i - 1) + 
                      (k - i + i - 1) / i;
            minOps = min(minOps, ops);
        }
        return minOps;
    }
};