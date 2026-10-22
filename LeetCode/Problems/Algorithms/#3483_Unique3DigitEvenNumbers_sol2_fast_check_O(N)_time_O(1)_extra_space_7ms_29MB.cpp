class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10);
        for(int digit: digits){
            freq[digit] += 1;
        }

        int validNumbers = 0;
        for(int num = 100; num <= 998; num += 2){
            int a = num / 100;
            int b = num / 10 % 10;
            int c = num % 10;

            freq[a] -= 1;
            freq[b] -= 1;
            freq[c] -= 1;

            if(freq[a] >= 0 && freq[b] >= 0 && freq[c] >= 0){
                validNumbers += 1;
            }

            freq[a] += 1;
            freq[b] += 1;
            freq[c] += 1;
        }

        return validNumbers;
    }
};