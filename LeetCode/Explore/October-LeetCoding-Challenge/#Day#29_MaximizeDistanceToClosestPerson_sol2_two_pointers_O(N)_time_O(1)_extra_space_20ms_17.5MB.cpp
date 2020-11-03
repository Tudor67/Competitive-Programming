class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        const int N = seats.size();
        
        // Step 1: check special cases when the first or last seats are empty
        int answer = max(find(seats.begin(), seats.end(), 1) - seats.begin(),
                         find(seats.rbegin(), seats.rend(), 1) - seats.rbegin());
        
        // Step 2: select the max interval of form [...,1,0,0,...,0,0,0,1,..]
        //         (i.e., interval of consecutive zeros surrounded by 1)
        for(int p1 = -1, p2 = 0; p2 < N; ++p2){
            if(seats[p2] == 1){
                if(p1 != -1){
                    answer = max((p2 - p1) / 2, answer);
                }
                p1 = p2;
            }
        }
        
        return answer;
    }
};