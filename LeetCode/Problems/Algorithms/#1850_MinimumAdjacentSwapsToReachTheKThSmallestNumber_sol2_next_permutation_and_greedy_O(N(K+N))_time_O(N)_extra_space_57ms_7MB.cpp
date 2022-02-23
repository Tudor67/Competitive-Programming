class Solution {
private:
    void nextPermutation(string& num){
        const int N = num.length();
        
        int firstIdxToSwap = 0;
        for(int i = N - 1; i - 1 >= 0; --i){
            if(num[i - 1] < num[i]){
                firstIdxToSwap = i - 1;
                break;
            }
        }
        
        int secondIdxToSwap = 0;
        for(int i = N - 1; i >= firstIdxToSwap; --i){
            if(num[firstIdxToSwap] < num[i]){
                secondIdxToSwap = i;
                break;
            }
        }
        
        if(firstIdxToSwap != secondIdxToSwap){
            swap(num[firstIdxToSwap], num[secondIdxToSwap]);
            reverse(num.begin() + firstIdxToSwap + 1, num.end());
        }
    }
    
public:
    int getMinSwaps(string initialNum, int k) {
        const int N = initialNum.length();
        
        string num = initialNum;
        for(int i = 1; i <= k; ++i){
            nextPermutation(num);
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