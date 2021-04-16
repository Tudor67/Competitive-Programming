class Solution {
private:
    long long getMinTime(vector<int>& piles, const int& K){
        long long t = 0;
        for(int pile: piles){
            t += (pile + K - 1) / K;
        }
        return t;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end());
        while(l != r){
            int mid = (l + r) / 2;
            if(getMinTime(piles, mid) <= h){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return r;
    }
};