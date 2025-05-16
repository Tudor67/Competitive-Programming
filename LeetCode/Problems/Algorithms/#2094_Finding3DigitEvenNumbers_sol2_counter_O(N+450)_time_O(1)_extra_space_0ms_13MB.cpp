class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        const int N = digits.size();

        vector<int> freq(10);
        for(int digit: digits){
            freq[digit] += 1;
        }

        vector<int> evenNumbers;
        for(int a = 1; a <= 9; ++a){
            for(int b = 0; b <= 9; ++b){
                for(int c = 0; c <= 8; c += 2){
                    freq[a] -= 1;
                    freq[b] -= 1;
                    freq[c] -= 1;
                    if(min({freq[a], freq[b], freq[c]}) >= 0){
                        evenNumbers.push_back(a * 100 + b * 10 + c);
                    }
                    freq[a] += 1;
                    freq[b] += 1;
                    freq[c] += 1;
                }
            }
        }

        return evenNumbers;
    }
};