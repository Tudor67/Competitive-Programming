class Solution {
private:
    bool isValid(const string& A, const string& B, const string& TARGET){
        const int A_LEN = A.length();
        const int B_LEN = B.length();
        const int TARGET_LEN = TARGET.length();
        return (A_LEN + B_LEN == TARGET_LEN &&
                TARGET.compare(0, A_LEN, A) == 0 &&
                TARGET.compare(A_LEN, B_LEN, B) == 0);
    }
    
public:
    int numOfPairs(vector<string>& nums, string target) {
        const int N = nums.size();
        
        int pairsCount = 0;
        for(int i = 0; i < N; ++i){
            for(int j = 0; j < N; ++j){
                if(i != j && isValid(nums[i], nums[j], target)){
                    pairsCount += 1;
                }
            }
        }
        
        return pairsCount;
    }
};