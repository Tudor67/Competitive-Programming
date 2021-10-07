class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int N = nums.size();
        
        unordered_map<int, int> count;
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                count[nums[j] & nums[k]] += 1;
            }
        }
        
        int triplets = 0;
        for(int i = 0; i < N; ++i){
            for(const pair<int, int>& P: count){
                int complementPair = P.first;
                if((nums[i] & complementPair) == 0){
                    triplets += count[complementPair];
                }
            }
        }
        
        return triplets;
    }
};