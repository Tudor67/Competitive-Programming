class Solution {
private:
    struct MaxComparator{
        bool operator()(const string& LHS, const string& RHS) const{
            if(LHS.length() == RHS.length()){
                return (LHS > RHS);
            }
            return (LHS.length() > RHS.length());
        }
    };
    
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        const int N = nums.size();
        priority_queue<string, vector<string>, MaxComparator> minHeap;
        for(int i = 0; i < N; ++i){
            minHeap.push(nums[i]);
            if((int)minHeap.size() == k + 1){
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};