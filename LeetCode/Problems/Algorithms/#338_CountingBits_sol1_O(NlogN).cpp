class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> answer(num + 1);
        for(int i = 0; i <= num; ++i){
            int bit_cnt = 0;
            for(int j = 0; (1LL << j) <= num; ++j){
                if(i & (1 << j)){
                    ++bit_cnt;
                }
            }
            answer[i] = bit_cnt;
        }
        return answer;
    }
};