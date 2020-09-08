class Solution {
private:
    void permutate(vector<int>& A, const int& START_IDX, string& max_time){
        if(START_IDX == A.size()){
            string hh = to_string(A[0]) + to_string(A[1]);
            string mm = to_string(A[2]) + to_string(A[3]);
            if(hh <= "23" && mm <= "59"){
                string cur_time = hh + ":" + mm;
                if(max_time.empty() || cur_time > max_time){
                    max_time = cur_time;
                }
            }
        }else{
            for(int i = START_IDX; i < A.size(); ++i){
                swap(A[START_IDX], A[i]);
                permutate(A, START_IDX + 1, max_time);
                swap(A[START_IDX], A[i]);
            }
        }
    }
    
public:
    string largestTimeFromDigits(vector<int>& A) {
        string max_time;
        permutate(A, 0, max_time);
        return max_time;
    }
};