class Solution {
public:
    int countTriplets(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_NUM = max(1, *max_element(nums.begin(), nums.end()));
        const int MAX_BIT = (int)floor(log2(MAX_NUM));
        
        unordered_map<int, int> numCount;
        for(int i = 0; i < N; ++i){
            numCount[nums[i]] += 1;
        }
        
        unordered_map<int, int> pairCount;
        for(int j = 0; j < N; ++j){
            for(int k = 0; k < N; ++k){
                pairCount[nums[j] & nums[k]] += 1;
            }
        }
        
        int triplets = 0;
        for(const pair<int, int>& P: numCount){
            int num = P.first;
            int complementPairMask = num ^ ((1 << (MAX_BIT + 1)) - 1);
            int complementPairSubmask = complementPairMask;
            while(complementPairSubmask >= 1){
                if(pairCount.find(complementPairSubmask) != pairCount.end()){
                    triplets += (numCount[num] * pairCount[complementPairSubmask]);
                }
                complementPairSubmask = (complementPairSubmask - 1) & complementPairMask;
            }
            if(pairCount.find(complementPairSubmask) != pairCount.end()){
                triplets += (numCount[num] * pairCount[0]);
            }
        }
        
        return triplets;
    }
};