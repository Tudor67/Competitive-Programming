class Solution {
private:
    int solve(vector<int>& nums, int l, int r){
        if(l == r){
            return nums[r];
        }
        
        int mid = (l + r) / 2;
        int leftCandidate = solve(nums, l, mid);
        int rightCandidate = solve(nums, mid + 1, r);
        
        if(leftCandidate == rightCandidate){
            return rightCandidate;
        }
        
        int leftCandidateCount = count(nums.begin() + l, nums.begin() + r + 1, leftCandidate);
        int rightCandidateCount = count(nums.begin() + l, nums.begin() + r + 1, rightCandidate);
        if(leftCandidateCount <= rightCandidateCount){
            return rightCandidate;
        }
        
        return leftCandidate;
    }
    
public:
    int majorityElement(vector<int>& nums) {
        const int N = nums.size();
        
        int candidate = solve(nums, 0, N - 1);
        int candidateCount = count(nums.begin(), nums.end(), candidate);
        
        if(candidateCount > N / 2){
            return candidate;
        }
        
        return INT_MIN;
    }
};