class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int student: students){
            q.push(student);
        }

        stack<int> st;
        for(int i = (int)sandwiches.size() - 1; i >= 0; --i){
            st.push(sandwiches[i]);
        }

        int consecutiveLeaveCount = 0;
        while(!st.empty() && consecutiveLeaveCount < q.size()){
            if(st.top() == q.front()){
                consecutiveLeaveCount = 0;
                st.pop();
                q.pop();
            }else{
                consecutiveLeaveCount += 1;
                q.push(q.front());
                q.pop();
            }
        }

        return st.size();
    }
};