class Solution {
private:
    bool is_overlapping(const vector<int>& I1, const vector<int>& I2){
        return (max(I1.front(), I2.front()) <= min(I1.back(), I2.back()));
    }
    
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        const int N = intervals.size();
        vector<vector<int>> answer = intervals;
        
        bool updated = false;
        for(int i = 0; i < N; ++i){
            if(is_overlapping(answer[i], newInterval)){
                answer[i][0] = min(answer[i][0], newInterval[0]);
                answer[i][1] = max(answer[i][1], newInterval[1]);
                newInterval = answer[i];
                updated = true;
            }
        }
        
        if(updated){
            int size = 0;
            for(int j = 1; j < N; ++j){
                if(answer[size][0] == answer[j][0]){
                    answer[size][1] = answer[j][1];
                }else{
                    answer[size + 1] = answer[j];
                    size += 1;
                }
            }
            answer.resize(size + 1);
        }else{
            for(int i = 0; i <= N; ++i){
                if(i == N || newInterval.back() < answer[i].front()){
                    answer.insert(answer.begin() + i, newInterval);
                    break;
                }
            }
        }
        
        return answer;
    }
};