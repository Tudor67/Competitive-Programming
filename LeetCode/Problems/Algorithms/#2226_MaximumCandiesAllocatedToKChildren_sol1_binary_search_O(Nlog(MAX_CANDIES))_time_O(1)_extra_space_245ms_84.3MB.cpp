class Solution {
private:
    long long countSubPilesWithCandiesAtLeast(vector<int>& candies, const int& CANDIES_THRESHOLD){
        long long subPiles = 0;
        for(int c: candies){
            subPiles += (c / CANDIES_THRESHOLD);
        }
        return subPiles;
    }
    
public:
    int maximumCandies(vector<int>& candies, long long k) {
        const int N = candies.size();
        const int MAX_CANDIES = *max_element(candies.begin(), candies.end());
        
        int l = 0;
        int r = MAX_CANDIES;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(countSubPilesWithCandiesAtLeast(candies, mid) < k){
                r = mid - 1;
            }else{
                l = mid;
            }
        }
        
        return r;
    }
};