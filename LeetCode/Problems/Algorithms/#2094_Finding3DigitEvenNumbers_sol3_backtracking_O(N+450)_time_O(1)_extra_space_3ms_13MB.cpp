class Solution {
private:
    const int K = 3;

    void back(int level, int currNum, vector<int>& freq, vector<int>& evenNumbers){
        if(level == K){
            if(currNum % 2 == 0){
                evenNumbers.push_back(currNum);
            }
        }else{
            int startDigit = (level == 0 ? 1 : 0);
            for(int digit = startDigit; digit <= 9; ++digit){
                if(freq[digit] >= 1){
                    freq[digit] -= 1;
                    back(level + 1, currNum * 10 + digit, freq, evenNumbers);
                    freq[digit] += 1;
                }
            }
        }
    }

public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        const int N = digits.size();

        vector<int> freq(10);
        for(int digit: digits){
            freq[digit] += 1;
        }

        vector<int> evenNumbers;
        back(0, 0, freq, evenNumbers);

        return evenNumbers;
    }
};