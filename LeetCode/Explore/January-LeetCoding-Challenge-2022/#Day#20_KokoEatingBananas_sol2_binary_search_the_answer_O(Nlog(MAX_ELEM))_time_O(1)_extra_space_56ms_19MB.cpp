class Solution {
private:
    long long computeTime(vector<int>& piles, int speed){
        long long totalTime = 0;
        for(long long bananas: piles){
            totalTime += (bananas + speed - 1) / speed;
        }
        return totalTime;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int N = piles.size();
        const int MAX_ELEM = *max_element(piles.begin(), piles.end());
        
        int l = 1;
        int r = MAX_ELEM;
        while(l != r){
            int mid = (l + r) / 2;
            if(computeTime(piles, mid) <= h){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};