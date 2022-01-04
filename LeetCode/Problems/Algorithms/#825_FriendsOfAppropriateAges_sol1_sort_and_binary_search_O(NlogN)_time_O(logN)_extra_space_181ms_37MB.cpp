class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        const int N = ages.size();
        
        sort(ages.begin(), ages.end());
        
        int count = 0;
        for(int x: ages){
            int i = upper_bound(ages.begin(), ages.end(), 0.5 * x + 7) - ages.begin();
            int j = upper_bound(ages.begin(), ages.end(), x) - ages.begin() - 1;
            if(i <= j){
                count += j - i;
            }
        }
        
        return count;
    }
};