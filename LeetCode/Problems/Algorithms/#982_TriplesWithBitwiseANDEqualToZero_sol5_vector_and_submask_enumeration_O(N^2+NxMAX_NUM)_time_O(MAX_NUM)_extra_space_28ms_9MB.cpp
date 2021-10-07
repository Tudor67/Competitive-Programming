class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = max(1, *max_element(nums.begin(), nums.end()));
        const int MAX_BIT = (int)floor(log2(MAX_NUM));
        
        vector<int> count(MAX_NUM + 1, 0);
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                count[nums[j] & nums[k]] += 1;
            }
        }
        
        int triplets = 0;
        for(int i = 0; i < N; ++i){
            int complementPairMask = nums[i] ^ ((1 << (MAX_BIT + 1)) - 1);
            int complementPairSubmask = complementPairMask;
            while(complementPairSubmask >= 1){
                if(complementPairSubmask <= MAX_NUM){
                    triplets += count[complementPairSubmask];
                }
                complementPairSubmask = (complementPairSubmask - 1) & complementPairMask;
            }
            triplets += count[0];
        }
        
        return triplets;
    }
};