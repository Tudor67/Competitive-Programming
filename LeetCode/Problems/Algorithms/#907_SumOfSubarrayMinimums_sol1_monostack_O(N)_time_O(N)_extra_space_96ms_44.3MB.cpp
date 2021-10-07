class Solution {
private:
    vector<int> computeClosestPositionsToTheRight(const vector<int>& A, const int& N){
        // r[i]: closest position to the right such that A[i] > A[r[i]] and i < r[i]
        //       it can be computed efficiently (i.e., in O(N) time and space) using a monostack
        vector<int> r(N + 2);
        stack<int> st;
        st.push(N + 1);
        for(int i = N; i >= 1; --i){
            while(A[i] <= A[st.top()]){
                st.pop();
            }
            r[i] = st.top();
            st.push(i);
        }
        return r;
    }
    
    vector<int> computeClosestPositionsToTheLeft(const vector<int>& A, const int& N){
        // l[i]: closest position to the left such that A[l[i]] <= A[i] and l[i] < i
        //       it can be computed efficiently (i.e., in O(N) time and space) using a monostack
        vector<int> l(N + 2);
        stack<int> st;
        st.push(0);
        for(int i = 1; i <= N; ++i){
            while(A[st.top()] > A[i]){
                st.pop();
            }
            l[i] = st.top();
            st.push(i);
        }
        return l;
    }
    
public:
    int sumSubarrayMins(vector<int>& arr) {
        const int MODULO = 1e9 + 7;
        const int N = arr.size();
        
        vector<int> a(N + 2);
        a[0] = a[N + 1] = -1;
        copy(arr.begin(), arr.end(), a.begin() + 1);
        
        vector<int> r = computeClosestPositionsToTheRight(a, N);
        vector<int> l = computeClosestPositionsToTheLeft(a, N);
        
        long long answer = 0;
        for(long long i = 1; i <= N; ++i){
            answer += (i - l[i]) * a[i] * (r[i] - i);
            answer %= MODULO;
        }
        
        return answer;
    }
};