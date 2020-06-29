class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int answer = 0;
        for(int bit = 0; bit < 32; ++bit){
            int cnt = 0;
            for(int num: nums){
                if(num & (1 << bit)){
                    ++cnt;
                }
            }
            if(cnt % 3 == 1){
                answer |= (1 << bit);
            }
        }
        return answer;
    }
};