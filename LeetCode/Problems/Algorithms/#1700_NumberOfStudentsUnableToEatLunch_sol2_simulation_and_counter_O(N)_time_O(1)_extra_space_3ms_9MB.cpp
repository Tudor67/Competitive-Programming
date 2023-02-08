class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        const int N = students.size();

        vector<int> studentsPreference(2);
        studentsPreference[0] = count(students.begin(), students.end(), 0);
        studentsPreference[1] = N - studentsPreference[0];

        for(int i = 0; i < N; ++i){
            if(studentsPreference[sandwiches[i]] == 0){
                return N - i;
            }
            studentsPreference[sandwiches[i]] -= 1;
        }

        return 0;
    }
};