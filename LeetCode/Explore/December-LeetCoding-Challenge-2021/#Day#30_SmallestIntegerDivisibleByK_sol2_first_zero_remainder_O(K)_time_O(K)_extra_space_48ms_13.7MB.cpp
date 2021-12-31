class Solution {
public:
    int smallestRepunitDivByK(int k) {
        // Case 0: even k
        if(k % 2 == 0){
            return -1;
        }
        
        // Case 1: odd k
        int len = 1;
        int pow10 = 1;
        int modSum = 0;
        unordered_set<int> vis;
        while(true){
            modSum = (modSum + pow10) % k;
            if(modSum == 0){
                return len;
            }
            if(vis.count(modSum)){
                return -1;
            }
            vis.insert(modSum);
            pow10 = (pow10 * 10) % k;
            len += 1;
        }
        
        return -1;
    }
};
