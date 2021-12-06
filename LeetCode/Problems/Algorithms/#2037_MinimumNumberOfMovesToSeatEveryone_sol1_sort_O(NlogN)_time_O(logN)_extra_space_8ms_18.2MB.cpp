class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        const int N = seats.size();
        
        sort(seats.begin(), seats.end());
        sort(students.begin(), students.end());
        
        int minMoves = 0;
        for(int i = 0; i < N; ++i){
            minMoves += abs(seats[i] - students[i]);
        }
        
        return minMoves;
    }
};