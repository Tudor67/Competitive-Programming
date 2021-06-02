class Solution {
public:
    double nthPersonGetsNthSeat(int n) {
        /*
           Nice problem.
           Let's generate all possible cases/configurations for small values of n:
           
           -> n = 1:
                    seat index:      1
                    passenger index: 1 (*)
                    p = 1 / 1 = 1;
                    
           -> n = 2:
                    seat index:       1   2
                    passenger index: |1|  2 (*)
                                      2  |1|
                    p = 1 / 2 = 0.5;

           -> n = 3:
                    seat index:      1  2  3
                    passenger index: |1 2| 3 (*)
                                     |2 1| 3 (*)
                                     3 |1 2|
                                     3 |2 1|
                    p = 2 / 4 = 0.5;
            
           -> n = 4:
                    seat index:      1  2  3 4
                    passenger index: |1 2 3| 4 (*)
                                     |2 1 3| 4 (*)
                                     |3 1 2| 4 (*)
                                     |3 2 1| 4 (*)
                                     4 |1 2 3|
                                     4 |1 3 2|
                                     4 |2 1 3|
                                     4 |2 3 1|
                    p = 4 / 8 = 0.5;
                    
           Observations:
             1.) We can generate configurations for n using (slightly modified) configurations from previous step (i.e., n - 1):
                 -> totalConfigs(n) = 2 * totalConfigs(n - 1), where totalConfigs(1) = 1;
             2.) half of configurations will have nth passenger on nth seat/position;
                 half of configurations will have nth passenger on 1st seat/position;
                 this is true because nth passenger will be the last who takes his seat,
                 this means that at the last step (i.e., step n) n - 1 seats are taken (seats in range [1, n - 1] or [2, n]);
                 intuition: nth passenger cannot take a seat in range[2, n - 1] because those positions are already taken by previous passengers (following the rule in the problem description);
                 for example, if 2nd seat is not taken at step n (where n >= 3) then it means that 2nd passenger didn't take his correct seat at previous steps => this violates the rules from description => it is not a possible configuration at step n;
             3.) At step n we have 2 ^ (n - 1) possible configurations,
                 half of which are with nth passenger on nth position/seat;
             4.) So the answer is (2 ^ (n - 2)) / (2 ^ (n - 1)) = (2 ^ 0) / (2 ^ 1) = 1 / 2 = 0.5, where n >= 2;
                 For n = 1, the answer is equal to 1;
        */
        if(n == 1){
            return 1;
        }
        return 0.5;
    }
};