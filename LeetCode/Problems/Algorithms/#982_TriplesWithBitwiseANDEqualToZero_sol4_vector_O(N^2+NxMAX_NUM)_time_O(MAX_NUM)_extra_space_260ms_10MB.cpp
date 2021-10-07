class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = *max_element(nums.begin(), nums.end());
        
        vector<int> count(MAX_NUM + 1, 0);
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                count[nums[j] & nums[k]] += 1;
            }
        }
        
        vector<int> complementPairs;
        for(int complementPair = 0; complementPair <= MAX_NUM; ++complementPair){
            if(count[complementPair] >= 1){
                complementPairs.push_back(complementPair);
            }
        }
        
        int triplets = 0;
        for(int i = 0; i < N; ++i){
            for(int complementPair: complementPairs){
                if((nums[i] & complementPair) == 0){
                    triplets += count[complementPair];
                }
            }
        }
        
        return triplets;
    }
};