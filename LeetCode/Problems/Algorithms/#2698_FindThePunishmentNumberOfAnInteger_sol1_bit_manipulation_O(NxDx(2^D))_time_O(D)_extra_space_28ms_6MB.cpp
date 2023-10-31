class Solution {
private:
    bool canBePartitioned(int num){
        string s = to_string(num * num);
        
        const int L = s.length();
        const int FULL_MASK = (1 << L) - 1;
        
        for(int mask = 1; mask <= FULL_MASK; ++mask){
            if((mask >> (L - 1)) & 1){
                int sum = 0;
                int x = 0;
                for(int bit = 0; bit < L; ++bit){
                    x = x * 10 + (s[bit] - '0');
                    if((mask >> bit) & 1){
                        sum += x;
                        x = 0;
                    }
                }

                if(sum == num){
                    return true;
                }
            }
        }
        
        return false;
    }
    
public:
    int punishmentNumber(int n) {
        int res = 0;
        for(int i = 1; i <= n; ++i){
            if(canBePartitioned(i)){
                res += (i * i);
            }
        }
        return res;
    }
};