class Solution {
public:
    int nextGreaterElement(int n) {
        string s = to_string(n);
        next_permutation(s.begin(), s.end());
        long long next_greater_candidate = stoll(s);
        
        int answer = -1;
        if(n < next_greater_candidate && next_greater_candidate <= INT_MAX){
            answer = (int)next_greater_candidate;
        }
        
        return answer;
    }
};