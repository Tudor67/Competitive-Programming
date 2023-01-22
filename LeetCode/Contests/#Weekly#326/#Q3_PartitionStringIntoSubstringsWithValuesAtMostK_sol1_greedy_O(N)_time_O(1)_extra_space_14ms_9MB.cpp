class Solution {
public:
    int minimumPartition(string s, int k) {
        const int N = s.length();

        // Special case
        for(char c: s){
            if((c - '0') > k){
                return -1;
            }
        }
        
        // Greedily maximize the size of each partition
        // (as long as the partition is valid)
        int res = 1;
        int num = 0;
        for(char c: s){
            if(num <= (k - (c - '0')) / 10){
                num = num * 10 + (c - '0');
            }else{
                res += 1;
                num = (c - '0');
            }
        }
        
        return res;
    }
};