class Solution {
private:
    static bool comp(const vector<int>& LHS, const vector<int>& RHS){
        return (LHS[0] - LHS[1] < RHS[0] - RHS[1]);
    }
    
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        const int N = costs.size() / 2;
        
        nth_element(costs.begin(), costs.begin() + N - 1, costs.end(), comp);
        
        int res = 0;
        for(int i = 0; i < 2 * N; ++i){
            if(i < N){
                res += costs[i][0];
            }else{
                res += costs[i][1];
            }
        }
        
        return res;
    }
};