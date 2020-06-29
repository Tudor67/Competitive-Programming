class Solution {
private:
    bool contains_duplicate(const vector<int>& nums, const int& VAL){
        int cnt = 0;
        for(int num: nums){
            if(num <= VAL){
                ++cnt;
            }
        }
        return (cnt > VAL); // Dirichlet's principle
    }
    
public:
    int findDuplicate(vector<int>& nums) {
        const int N = (int)nums.size() - 1;
        int l = 1;
        int r = N;
        while(l != r){
            int mid = l + (r - l) / 2;
            if(contains_duplicate(nums, mid)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};