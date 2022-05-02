class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        const int N = nums.size();
        
        unordered_map<int, vector<int>> positionsOf;
        for(int i = 0; i < N; ++i){
            positionsOf[nums[i]].push_back(i);
        }
        
        int res = 0;
        vector<int> count(N);
        for(const pair<int, vector<int>>& P: positionsOf){
            const vector<int>& POSITIONS = P.second;
            for(int pos: POSITIONS){
                for(int x = 1; x * x <= pos; ++x){
                    if(pos % x == 0){
                        count[x] += 1;
                        if(x != pos / x){
                            count[pos / x] += 1;
                        }
                    }
                }
            }
            for(int pos: POSITIONS){
                for(int x = 1; x * x <= pos; ++x){
                    if(pos % x == 0){
                        count[x] -= 1;
                        if(x != pos / x){
                            count[pos / x] -= 1;
                        }
                    }
                }
                int complementPos = k / gcd(k, pos);
                if(complementPos < N){
                    res += count[complementPos];
                }
            }
        }
        
        return res;
    }
};