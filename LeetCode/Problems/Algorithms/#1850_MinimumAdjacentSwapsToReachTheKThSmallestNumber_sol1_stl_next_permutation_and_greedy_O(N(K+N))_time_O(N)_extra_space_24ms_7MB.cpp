class Solution {
public:
    int getMinSwaps(string initialNum, int k) {
        const int N = initialNum.length();
        
        string num = initialNum;
        for(int i = 1; i <= k; ++i){
            next_permutation(num.begin(), num.end());
        }
        
        int swaps = 0;
        for(int i = 0; i < N; ++i){
            int targetPos = find(num.begin() + i, num.end(), initialNum[i]) - num.begin();
            for(int j = targetPos; j - 1 >= i; --j){
                swap(num[j - 1], num[j]);
                swaps += 1;
            }
        }
        
        return swaps;
    }
};