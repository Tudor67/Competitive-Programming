class Solution {
private:
    int computeRangeSum(vector<int>& prefSum, int l, int r){
        if(l > r){
            return 0;
        }
        if(l == 0){
            return prefSum[r];
        }
        return prefSum[r] - prefSum[l - 1];
    }
    
    int computeRangeMinMoves(vector<int>& nums, const int& L, const int& MID_ONE_POS, const int& R,
                             vector<int>& prefZeros, vector<int>& prefOnes,
                             vector<int>& prefMoves, vector<int>& suffMoves){
        const int N = nums.size();
        
        // range1: [L .. MID_ONE_POS]
        int leftOnes = computeRangeSum(prefOnes, 0, L - 1);
        int rangeZeros1 = computeRangeSum(prefZeros, L, MID_ONE_POS);
        int rangeMinMoves1 = computeRangeSum(prefMoves, L, MID_ONE_POS) - leftOnes * rangeZeros1;
        
        // range2: [MID_ONE_POS .. R]
        int rightOnes = computeRangeSum(prefOnes, R + 1, N - 1);
        int rangeZeros2 = computeRangeSum(prefZeros, MID_ONE_POS, R);
        int rangeMinMoves2 = suffMoves[MID_ONE_POS] - (R + 1 < N ? suffMoves[R + 1] : 0) - rightOnes * rangeZeros2;
        
        return rangeMinMoves1 + rangeMinMoves2;
    }
    
public:
    int minMoves(vector<int>& nums, int k) {
        const int N = nums.size();
        
        vector<int> prefZeros(N);
        vector<int> prefOnes(N);
        prefZeros[0] = (int)(nums[0] == 0);
        prefOnes[0] = (int)(nums[0] == 1);
        for(int i = 1; i < N; ++i){
            prefZeros[i] = prefZeros[i - 1] + (int)(nums[i] == 0);
            prefOnes[i] = prefOnes[i - 1] + (int)(nums[i] == 1);
        }
        
        vector<int> prefMoves(N);
        prefMoves[0] = 0;
        for(int i = 1; i < N; ++i){
            if(nums[i] == 0){
                prefMoves[i] = prefMoves[i - 1] + computeRangeSum(prefOnes, 0, i - 1);
            }else{
                prefMoves[i] = prefMoves[i - 1];
            }
        }
        
        vector<int> suffMoves(N);
        suffMoves[N - 1] = 0;
        for(int i = N - 2; i >= 0; --i){
            if(nums[i] == 0){
                suffMoves[i] = computeRangeSum(prefOnes, i + 1, N - 1) + suffMoves[i + 1];
            }else{
                suffMoves[i] = suffMoves[i + 1];
            }
        }
        
        int answer = INT_MAX;
        int ones = 0;
        int midOnes = 0;
        int midOnePos = -1;
        int i = 0;
        for(int j = 0; j < N; ++j){
            ones += nums[j];
            while(ones > k || nums[i] == 0){
                ones -= nums[i];
                midOnes -= nums[i];
                i += 1;
            }
            while(midOnePos < j && midOnes <= k / 2){
                midOnePos += 1;
                midOnes += nums[midOnePos];
            }
            if(ones == k && nums[j] == 1){
                answer = min(answer, computeRangeMinMoves(nums, i, midOnePos, j,
                                                          prefZeros, prefOnes, prefMoves, suffMoves));
            }
            if(answer == 0){
                break;
            }
        }
        
        return answer;
    }
};