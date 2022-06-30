class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        const int N = people.size();
        
        // sort people in increasing order of heights (in case of ties: decreasing order of k)
        vector<vector<int>> sortedPeople = people;
        sort(sortedPeople.begin(), sortedPeople.end(),
             [](const vector<int>& LHS, const vector<int>& RHS){
                 return (LHS[0] < RHS[0] || (LHS[0] == RHS[0] && LHS[1] > RHS[1]));
             });
        
        // insert the shortest person at index equal to his k (==sortedPersons[0][1])
        // insert the second shortest person at index i such that there are k (==sortedPersons[1][1]) empty places
        //                                                                  to the left of i (i.e. in res[0 .. i - 1])
        // insert the third shortest person at index i such that there are k (==sortedPersons[2][1]) empty places
        //                                                                  to the left of i (i.e. in res[0 .. i - 1])
        // ...
        // insert the (N - 1)th shortest person at index i such that there are k (==sortedPersons[N - 1][1]) empty places
        //                                                                  to the left of i (i.e. in res[0 .. i - 1])
        vector<vector<int>> res(N, vector<int>(2, -1));
        for(const vector<int>& PERSON: sortedPeople){
            int h = PERSON[0];
            int k = PERSON[1];
            int emptyPlaces = 0;
            for(int i = 0; i < N; ++i){
                if(res[i][0] == -1){
                    emptyPlaces += 1;
                }
                if(emptyPlaces == k + 1){
                    res[i] = PERSON;
                    break;
                }
            }
        }
        
        return res;
    }
};