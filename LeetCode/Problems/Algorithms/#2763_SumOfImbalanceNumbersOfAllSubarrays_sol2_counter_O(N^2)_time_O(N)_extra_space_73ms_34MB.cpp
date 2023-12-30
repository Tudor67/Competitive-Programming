class Solution {
public:
    int sumImbalanceNumbers(vector<int>& nums) {
        const int N = nums.size();
        
        int res = 0;
        vector<int> f(N + 2);
        
        for(int i = 0; i < N; ++i){
            int imbNumber = 0;
            int minNum = nums[i];
            int maxNum = nums[i];
            fill(f.begin(), f.end(), 0);
            
            for(int j = i; j < N; ++j){
                int x = nums[j];
                f[x] += 1;

                minNum = min(minNum, x);
                maxNum = max(maxNum, x);

                if(f[x] == 1 && minNum != maxNum){
                    if(x == minNum){
                        imbNumber += (int)(f[x + 1] == 0);
                    }else if(x == maxNum){
                        imbNumber += (int)(f[x - 1] == 0);
                    }else{
                        imbNumber += (int)(f[x + 1] == 0 && f[x - 1] == 0);
                        imbNumber -= (int)(f[x + 1] != 0 && f[x - 1] != 0);
                    }
                }

                res += imbNumber;
            }
        }
        
        return res;
    }
};