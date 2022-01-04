class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        const int N = ages.size();
        
        sort(ages.begin(), ages.end());
        
        int count = 0;
        int i = 0;
        int j = 0;
        for(int x: ages){
            while(i < N && ages[i] <= 0.5 * x + 7){
                i += 1;
            }
            while(j + 1 < N && ages[j + 1] <= x){
                j += 1;
            }
            if(i <= j){
                count += j - i;
            }
        }
        
        return count;
    }
};