class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        const int N = obstacles.size();

        vector<int> answer(N);

        // At ith step (when we processed only obstacles[0 .. i]):
        //    v[j]: min obstacle height of a non-decreasing subsequence/course of length (j + 1)
        vector<int> v;
        for(int i = 0; i < N; ++i){
            int j = upper_bound(v.begin(), v.end(), obstacles[i]) - v.begin();
            if(j == (int)v.size()){
                v.resize(j + 1);
            }
            v[j] = obstacles[i];
            answer[i] = j + 1;
        }

        return answer;
    }
};