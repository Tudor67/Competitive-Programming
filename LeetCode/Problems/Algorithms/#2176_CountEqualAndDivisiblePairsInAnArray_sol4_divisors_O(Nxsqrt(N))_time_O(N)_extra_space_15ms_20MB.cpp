class Solution {
public:
    int countPairs(vector<int>& nums, int k) {
        const int N = nums.size();

        unordered_map<int, vector<int>> numToIndices;
        for(int i = 0; i < N; ++i){
            numToIndices[nums[i]].push_back(i);
        }

        int validPairs = 0;
        for(const auto& [_, indices]: numToIndices){
            unordered_map<int, int> f;
            for(int index: indices){
                if(index == 0){
                    validPairs += (int)indices.size() - 1;
                }else{
                    int complementIndex = k / gcd(k, index);
                    if(complementIndex < N){
                        validPairs += f[complementIndex];
                    }
                }

                for(int x = 1; x * x <= index; ++x){
                    if(index % x == 0){
                        f[x] += 1;
                        if(x != index / x){
                            f[index / x] += 1;
                        }
                    }
                }
            }
        }

        return validPairs;
    }
};