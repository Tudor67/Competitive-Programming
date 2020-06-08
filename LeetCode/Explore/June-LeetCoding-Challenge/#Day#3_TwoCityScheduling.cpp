class Solution {
private:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return (a[1] - a[0] < b[1] - b[0]);
    }
    
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int answer = 0;
        sort(costs.begin(), costs.end(), comp);
        for(int i = 0; i < costs.size(); ++i){
            if(i < costs.size() / 2){
                answer += costs[i][1];
            }else{
                answer += costs[i][0];
            }
        }
        return answer;
    }
};