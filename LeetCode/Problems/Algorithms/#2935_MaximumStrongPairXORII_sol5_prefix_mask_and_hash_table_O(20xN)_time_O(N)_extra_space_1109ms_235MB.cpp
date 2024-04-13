class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        const int N = nums.size();
        const int MAX_BITS = 20;

        int res = 0;
        unordered_map<int, int> minFor;
        unordered_map<int, int> maxFor;

        for(int bit = MAX_BITS - 1; bit >= 0; --bit){
            res <<= 1;
            minFor.clear();
            maxFor.clear();

            for(int num: nums){
                int prefMask = (num >> bit);
                if(minFor.count(prefMask)){
                    minFor[prefMask] = min(minFor[prefMask], num);
                    maxFor[prefMask] = max(maxFor[prefMask], num);
                }else{
                    minFor[prefMask] = num;
                    maxFor[prefMask] = num;
                }
            }

            for(const pair<const int, int>& P: minFor){
                int a = P.first;
                int b = res ^ 1 ^ a;
                if(a <= b && maxFor.count(b) && 2 * maxFor[a] >= minFor[b]){
                    res |= 1;
                }
            }
        }

        return res;
    }
};