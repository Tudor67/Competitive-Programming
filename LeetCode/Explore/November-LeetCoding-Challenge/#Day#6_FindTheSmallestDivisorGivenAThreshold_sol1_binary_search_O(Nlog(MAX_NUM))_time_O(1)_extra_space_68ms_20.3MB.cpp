class Solution {
private:
    long long sum(const vector<int>& NUMS, const int& DIVISOR){
        long long s = 0;
        for(int num: NUMS){
            s += (num / DIVISOR) + (num % DIVISOR > 0);
        }
        return s;
    }
    
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while(l != r){
            int mid = (l + r) / 2;
            if(sum(nums, mid) <= threshold){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};