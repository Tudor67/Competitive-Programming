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
        vector<bool> vis(k, false);
        while(true){
            modSum = (modSum + pow10) % k;
            if(modSum == 0){
                return len;
            }
            if(vis[modSum]){
                return -1;
            }
            vis[modSum] = true;
            pow10 = (pow10 * 10) % k;
            len += 1;
        }
        
        return -1;
    }
};