class Solution {
public:
    int numberOfPoints(vector<vector<int>>& nums) {
        const int N = nums.size();

        int maxPoint = 0;
        for(const vector<int>& V: nums){
            maxPoint = max(maxPoint, V[1]);
        }
        
        int res = 0;
        for(int point = 0; point <= maxPoint; ++point){
            for(const vector<int>& V: nums){
                if(V[0] <= point && point <= V[1]){
                    res += 1;
                    break;
                }
            }
        }

        return res;
    }
};