class Solution {
private:
    void back(vector<int>& count, string& currentNum, const string& MAX_NUM, int& answer){
        if(currentNum.size() < MAX_NUM.size() || (currentNum.size() == MAX_NUM.size() && currentNum <= MAX_NUM)){
            answer += (!currentNum.empty());
            for(int digit = 0; digit <= 9; ++digit){
                if(count[digit] >= 1){
                    count[digit] -= 1;
                    currentNum.push_back(digit + '0');
                    back(count, currentNum, MAX_NUM, answer);
                    currentNum.pop_back();
                    count[digit] += 1;
                }
            }
        }
    }
    
public:
    int atMostNGivenDigitSet(vector<string>& digits, int n) {
        vector<int> count(10, 0);
        for(string s: digits){
            int digit = s[0] - '0';
            count[digit] = 9;
        }
        
        string currentNum;
        const string MAX_NUM = to_string(n);
        int answer = 0;
        
        back(count, currentNum, MAX_NUM, answer);
        
        return answer;
    }
};