class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& A) {
        const int N = A.size();
        vector<int> answer(N);
        int p1 = 0;
        int p2 = N - 1;
        for(int num: A){
            if(num % 2 == 0){
                answer[p1++] = num;
            }else{
                answer[p2--] = num;
            }
        }
        return answer;
    }
};