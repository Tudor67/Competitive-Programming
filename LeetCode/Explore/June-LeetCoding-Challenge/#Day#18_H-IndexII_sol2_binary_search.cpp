class Solution {
public:
    int hIndex(vector<int>& citations) {
        int answer = 0;
        if(citations.empty() || citations.back() == 0){
            answer = 0;
        }else{
            const int N = citations.size();
            int l = 0;
            int r = N - 1;
            while(l != r){
                int mid = l + (r - l) / 2;
                int h = N - mid;
                if(citations[mid] < h){
                    l = mid + 1;
                }else{
                    r = mid;
                }
            }
            answer = N - r;
        }
        return answer;
    }
};