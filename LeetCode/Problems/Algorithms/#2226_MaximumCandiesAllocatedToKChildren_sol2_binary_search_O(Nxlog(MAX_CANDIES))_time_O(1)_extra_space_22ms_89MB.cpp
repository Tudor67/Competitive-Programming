class Solution {
private:
    long long countMaxChildren(vector<int>& candies, int targetCandiesPerChild){
        long long maxChildren = 0;
        for(int c: candies){
            maxChildren += (c / targetCandiesPerChild);
        }
        return maxChildren;
    }

public:
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 0;
        int r = *max_element(candies.begin(), candies.end());

        while(l != r){
            int mid = (l + r + 1) / 2;
            if(countMaxChildren(candies, mid) < k){
                r = mid - 1;
            }else{
                l = mid;
            }
        }

        return r;
    }
};