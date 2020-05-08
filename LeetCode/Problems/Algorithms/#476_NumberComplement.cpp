class Solution {
public:
    int findComplement(int num) {
        int answer = 0;         
        for(int j = 0; j <= 30 && (1 << j) <= num; ++j){
            if((num & (1 << j)) == 0){
                answer |= (1 << j);
            }
        }
        return answer;
    }
};