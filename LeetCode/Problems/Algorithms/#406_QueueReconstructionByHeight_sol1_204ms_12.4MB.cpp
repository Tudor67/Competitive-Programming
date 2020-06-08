class Solution {
private:
    static bool comp(const vector<int>& a, const vector<int>& b){
        return (a[1] < b[1] || (a[1] == b[1] && a[0] <= b[0]));
    }
    
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        vector<vector<int>> answer = people;
        
        sort(answer.begin(), answer.end(), comp);
        
        for(int i = 1; i < answer.size(); ++i){
            int pos = -1;
            int cnt = 0;
            for(int j = 0; j < i; ++j){
                cnt += (answer[j][0] >= answer[i][0]);
                if(cnt > answer[i][1]){
                    pos = j;
                    break;
                }
            }
            if(pos != -1){
                vector<int> temp = answer[i];
                for(int j = i; j >= pos + 1; --j){
                    answer[j] = answer[j - 1];
                }
                answer[pos] = temp;
            }
        }
        
        return answer;
    }
};