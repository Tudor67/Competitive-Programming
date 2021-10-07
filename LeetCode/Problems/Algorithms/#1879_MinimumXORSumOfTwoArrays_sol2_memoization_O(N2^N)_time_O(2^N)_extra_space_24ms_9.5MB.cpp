class Solution {
private:
    const int INF = 1e9;
    
    int solve(int idx1, vector<int>& nums1, vector<int>& nums2, int visMask2, vector<int>& memo){
        if(memo[visMask2] == INF){
            if(idx1 < 0){
                memo[visMask2] = 0;
            }else{
                for(int idx2 = (int)nums2.size() - 1; idx2 >= 0; --idx2){
                    if(!((visMask2 >> idx2) & 1)){
                        int cost = (nums1[idx1] ^ nums2[idx2]) + solve(idx1 - 1, nums1, nums2, visMask2 | (1 << idx2), memo);
                        memo[visMask2] = min(cost, memo[visMask2]);
                    }
                }
            }
        }
        return memo[visMask2];
    }
    
public:
    int minimumXORSum(vector<int>& nums1, vector<int>& nums2) {
        const int N = nums1.size();
        const int FULL_MASK = (1 << N) - 1;
        vector<int> memo(FULL_MASK + 1, INF);
        return solve(N - 1, nums1, nums2, 0, memo);
    }
};