class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        const int N = ages.size();
        const int MAX_AGE = *max_element(ages.begin(), ages.end());
        
        vector<int> count(MAX_AGE + 1);
        for(int age: ages){
            count[age] += 1;
        }
        
        int idx = -1;
        for(int age = 0; age <= MAX_AGE; ++age){
            while(count[age] > 0){
                count[age] -= 1;
                ages[++idx] = age;
            }
        }
        
        int requestsCount = 0;
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
                requestsCount += j - i;
            }
        }
        
        return requestsCount;
    }
};