class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        const int N = seats.size();

        vector<int> sortedSeats = seats;
        sort(sortedSeats.begin(), sortedSeats.end());

        vector<int> sortedStudents = students;
        sort(sortedStudents.begin(), sortedStudents.end());

        int minMoves = 0;
        for(int i = 0; i < N; ++i){
            minMoves += abs(sortedSeats[i] - sortedStudents[i]);
        }

        return minMoves;
    }
};