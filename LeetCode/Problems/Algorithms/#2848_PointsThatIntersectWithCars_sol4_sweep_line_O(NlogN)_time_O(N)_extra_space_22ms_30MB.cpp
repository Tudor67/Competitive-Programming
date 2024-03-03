class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        const int N = nums.size();

        map<int, int> delta;
        for(const vector<int>& V: nums){
            int a = V[0];
            int b = V[1];
            delta[a] += 1;
            delta[b + 1] -= 1;
        }

        int res = 0;
        int prevPoint = INT_MAX;
        int currentCars = 0;
        for(const pair<const int, int>& P: delta){
            int currentPoint = P.first;
            int currentDelta = P.second;
            if(currentCars >= 1 && prevPoint < currentPoint){
                res += (currentPoint - prevPoint);
            }
            currentCars += currentDelta;
            prevPoint = currentPoint;
        }

        return res;
    }
};