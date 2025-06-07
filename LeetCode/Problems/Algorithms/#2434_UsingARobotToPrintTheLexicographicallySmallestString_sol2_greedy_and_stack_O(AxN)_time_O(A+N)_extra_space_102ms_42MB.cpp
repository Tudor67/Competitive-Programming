class Solution {
private:
    bool containsSmallerElem(vector<int>& freq, int threshold){
        for(int elem = 0; elem < threshold; ++elem){
            if(freq[elem] >= 1){
                return true;
            }
        }
        return false;
    }

public:
    string robotWithString(string s) {
        const int N = s.length();
        const int A = 26;
        
        vector<int> freq(A);
        for(int i = 0; i < N; ++i){
            freq[s[i] - 'a'] += 1;
        }

        string res;
        stack<int> st;
        for(int i = 0; i < N; ++i){
            freq[s[i] - 'a'] -= 1;
            st.push(i);
            while(!st.empty() && !containsSmallerElem(freq, s[st.top()] - 'a')){
                res += s[st.top()];
                st.pop();
            }
        }

        return res;
    }
};