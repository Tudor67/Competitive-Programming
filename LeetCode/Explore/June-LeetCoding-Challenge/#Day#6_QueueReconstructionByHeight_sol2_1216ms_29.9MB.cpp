class Solution {
private:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return (a[0] > b[0] || (a[0] == b[0] && a[1] <= b[1]));
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int N = people.size();
        vector<vector<int>> answer = people;
        
        sort(answer.begin(), answer.end(), comp);
        
        for(int i = 1; i < N; ++i){
            answer.insert(answer.begin() + answer[i][1], answer[i]);
            answer.erase(answer.begin() + i + 1);
        }
        
        return answer;
    }
};