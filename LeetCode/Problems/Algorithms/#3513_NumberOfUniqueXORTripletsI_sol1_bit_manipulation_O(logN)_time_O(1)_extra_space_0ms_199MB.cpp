class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int N = nums.size();

        if(N <= 2){
            return N;
        }

        int res = 1;
        while(res <= N){
            res *= 2;
        }
        
        return res;
    }
};