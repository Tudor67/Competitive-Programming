class Solution {
private:
    long long computeTotalHours(vector<int>& piles, int speed){
        long long totalHours = 0;
        for(int bananas: piles){
            totalHours += (bananas + speed - 1) / speed;
        }
        return totalHours;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int N = piles.size();
        const int MAX_ELEM = *max_element(piles.begin(), piles.end());

        int l = 1;
        int r = MAX_ELEM;
        while(l != r){
            int mid = (l + r) / 2;
            if(computeTotalHours(piles, mid) <= h){
                r = mid;
            }else{
                l = mid + 1;
            }
        }

        return r;
    }
};