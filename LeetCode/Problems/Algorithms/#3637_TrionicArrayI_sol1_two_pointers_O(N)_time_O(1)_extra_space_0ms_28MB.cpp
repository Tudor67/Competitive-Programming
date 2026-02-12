class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        const int N = nums.size();

        int p = 0;
        while(p + 1 < N && nums[p] < nums[p + 1]){
            p += 1;
        }

        int q = p;
        while(q + 1 < N && nums[q] > nums[q + 1]){
            q += 1;
        }

        int r = q;
        while(r + 1 < N && nums[r] < nums[r + 1]){
            r += 1;
        }

        return (0 < p && p < q && q < r && r == N - 1);
    }
};