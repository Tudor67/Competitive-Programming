class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        
        for(int startDigit = 1; startDigit <= 9; ++startDigit){
            int num = startDigit;
            while(num <= high){
                if(low <= num){
                    answer.push_back(num);
                }
                int nextDigit = (num % 10) + 1;
                if(nextDigit <= 9){
                    num = 10 * num + nextDigit;
                }else{
                    break;
                }
            }
        }
        
        sort(answer.begin(), answer.end());
        
        return answer;
    }
};