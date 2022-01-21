class Solution {
private:
    bool isValid(vector<int>& piles, int speed, int h){
        for(int bananas: piles){
            h -= (bananas + speed - 1) / speed;
            if(h < 0){
                return false;
            }
        }
        return true;
    }
    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        const int N = piles.size();
        const int MAX_ELEM = *max_element(piles.begin(), piles.end());
        
        int l = 1;
        int r = MAX_ELEM;
        while(l != r){
            int mid = (l + r) / 2;
            if(isValid(piles, mid, h)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        
        return r;
    }
};