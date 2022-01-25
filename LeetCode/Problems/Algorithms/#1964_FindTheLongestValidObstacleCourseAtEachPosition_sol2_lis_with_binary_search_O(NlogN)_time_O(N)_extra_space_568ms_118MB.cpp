class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        const int N = obstacles.size();
        vector<int> answer(N);
        vector<int> v;
        for(int i = 0; i < N; ++i){
            int pos = upper_bound(v.begin(), v.end(), obstacles[i]) - v.begin();
            if(pos == v.size()){
                v.push_back(0);
            }
            v[pos] = obstacles[i];
            answer[i] = pos + 1;
        }
        return answer;
    }
};