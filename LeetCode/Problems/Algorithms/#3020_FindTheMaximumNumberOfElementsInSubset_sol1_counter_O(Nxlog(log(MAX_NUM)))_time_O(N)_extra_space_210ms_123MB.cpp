class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long, int> f;
        for(long long num: nums){
            f[num] += 1;
        }
        
        int maxLen = 1;
        for(const pair<const long long, int>& P: f){
            long long num = P.first;
            int len = 0;
            
            if(num == 1){
                len = f[num];
            }else{
                while(f.count(num)){
                    if(f[num] == 1){
                        len += 1;
                        break;
                    }else{
                        len += 2;
                        num *= num;
                    }
                }
            }
            
            if(len % 2 == 0){
                len -= 1;
            }
            
            maxLen = max(maxLen, len);
        }
        
        return maxLen;
    }
};