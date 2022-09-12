class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        /*
          We have a path without cross if:
          0.) distances.size() <= 3 OR
          1.) All distances represent one expanding spiral OR
          2.) All distances represent one shrinking spiral OR
          3.) All distances represent one expanding spiral followed by one shrinking spiral.
              Pay attention to details when transitioning from expanding to shrinking spiral.
              If the first size/distance (d[i]) of the shrinking spiral is greater than or equal to
              the difference of its previous complementary sizes (d[i - 2] - d[i - 4]),
              we should decrease the size of previous border (d[i - 1] -= d[i - 3])
              to avoid intersection of expanding spiral.
                  
               
              Case 1: (d[i] >= d[i - 2] - d[i - 4])             Case 2: (d[i] < d[i - 2] - d[i - 4])
                     decrease the previous border                       don't decrease the previous border
                      (d[i - 1] -= d[i - 3])
              
                shrinking spiral                                       shrinking spiral
                      d[i]                                                    d[i]
                    ________                                                 ______
                   |        |                                               |      |
                   |   ___  |                                               |   |  |
                   |  |   | |                                               |   |  |
                   |  |__ | |                                               |   |  |
                   |______| |                                               |   |  |
                            |                                               |   |  |
                d[i - 4]    |  d[i - 1]                       d[i - 4]      |   |  |  d[i - 1]
                ________    |                                 ________      |   |  |
               |   ___  |   |                                |   ___  |     |   |  |
               |  |   | |   |                                |  |   | |     |   |  |
      d[i - 3] |  |_____|   |                       d[i - 3] |  |_____|     |   |  |
               |            |                                |              |___|  |
               |____________|                                |_____________________|
                  
                  d[i - 2]                                           d[i - 2]
              expanding spiral                                   expanding spiral
        */
        const int N = distance.size();
        
        // Step 1: distances.size() <= 3
        if(N <= 3){
            return false;
        }
        
        // Step 2: expanding spiral
        vector<int> d = distance;
        int i = 2;
        while(i < N && d[i] > d[i - 2]){
            i += 1;
        }
        
        // Step 3: transition from expanding spiral to shrinking spiral
        if(i < N){
            if((i == 3 && d[i] == d[i - 2]) ||
               (i >= 4 && d[i] >= d[i - 2] - d[i - 4])){
                d[i - 1] -= d[i - 3];
            }
            i += 1;
        }
        
        // Step 4: shrinking spiral
        while(i < N && d[i] < d[i - 2]){
            i += 1;
        }
        
        return (i < N);
    }
};