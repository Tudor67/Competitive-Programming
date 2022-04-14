class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        for(const string& OP: ops){
            if(OP == "+"){
                int num2 = st.top(); st.pop();
                int num1 = st.top(); st.pop();
                st.push(num1);
                st.push(num2);
                st.push(num1 + num2);
            }else if(OP == "D"){
                st.push(2 * st.top());
            }else if(OP == "C"){
                st.pop();
            }else{
                st.push(stoi(OP));
            }
        }
        
        int scoreSum = 0;
        while(!st.empty()){
            scoreSum += st.top();
            st.pop();
        }
        
        return scoreSum;
    }
};