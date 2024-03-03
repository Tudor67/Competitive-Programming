class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        const int N = nums.size();

        int maxPoint = 0;
        for(const vector<int>& V: nums){
            maxPoint = max(maxPoint, V[1]);
        }
        
        vector<int> delta(maxPoint + 2);
        for(const vector<int>& V: nums){
            int a = V[0];
            int b = V[1];
            delta[a] += 1;
            delta[b + 1] -= 1;
        }

        int res = 0;
        int currentCars = 0;
        for(int i = 0; i <= maxPoint; ++i){
            currentCars += delta[i];
            if(currentCars >= 1){
                res += 1;
            }
        }

        return res;
    }
};