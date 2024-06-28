class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        const int N = nums.size();

        int minFlips = 0;
        int flipStatus = 0;
        queue<int> flipStarts;

        for(int i = 0; i < N; ++i){
            if(i - k == flipStarts.front()){
                flipStatus ^= 1;
                flipStarts.pop();
            }
            if((nums[i] ^ flipStatus) == 0){
                if(i + k - 1 < N){
                    minFlips += 1;
                    flipStatus ^= 1;
                    flipStarts.push(i);
                }else{
                    minFlips = -1;
                    break;
                }
            }
        }

        return minFlips;
    }
};