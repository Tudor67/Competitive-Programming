class Solution {
public:
    int maximumGroups(vector<int>& grades) {
        const int N = grades.size();
        
        int l = 1;
        int r = N;
        while(l != r){
            int mid = (l + r + 1) / 2;
            if(mid <= (2 * N) / (mid + 1)){
                l = mid;
            }else{
                r = mid - 1;
            }
        }
        
        return r;
    }
};