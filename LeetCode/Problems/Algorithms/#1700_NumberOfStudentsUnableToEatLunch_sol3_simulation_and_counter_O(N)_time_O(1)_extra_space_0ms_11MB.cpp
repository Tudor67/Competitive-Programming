class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        const int N = students.size();

        vector<int> studCount(2);
        for(int i = 0; i < N; ++i){
            studCount[students[i]] += 1;
        }

        for(int i = 0; i < N; ++i){
            if(studCount[sandwiches[i]] >= 1){
                studCount[sandwiches[i]] -= 1;
            }else{
                return N - i;
            }
        }

        return 0;
    }
};