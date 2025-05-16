class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        const int N = digits.size();

        vector<int> evenNumbers;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                for(int k = 0; k < N; ++k){
                    if(i == j || i == k || j == k){
                        continue;
                    }
                    if(digits[i] == 0 || digits[k] % 2 == 1){
                        continue;
                    }
                    evenNumbers.push_back(digits[i] * 100 + digits[j] * 10 + digits[k]);
                }
            }
        }

        sort(evenNumbers.begin(), evenNumbers.end());
        evenNumbers.resize(unique(evenNumbers.begin(), evenNumbers.end()) - evenNumbers.begin());

        return evenNumbers;
    }
};