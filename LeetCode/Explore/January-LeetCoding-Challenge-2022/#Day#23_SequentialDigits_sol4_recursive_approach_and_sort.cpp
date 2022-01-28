class Solution {
private:
    void back(int num, int low, int high, vector<int>& answer){
        if(low <= num && num <= high){
            answer.push_back(num);
        }
        int nextDigit = (num % 10) + 1;
        if(nextDigit <= 9){
            back(10 * num + nextDigit, low, high, answer);
        }
    }
    
public:
    vector<int> sequentialDigits(int low, int high) {
        vector<int> answer;
        for(int startDigit = 1; startDigit <= 9; ++startDigit){
            back(startDigit, low, high, answer);
        }
        sort(answer.begin(), answer.end());
        return answer;
    }
};