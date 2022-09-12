class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        /*
          Three cases of self crossing:
          
               Case 1                         Case 2                             Case 3
         (c <= a && d >= b)         (c > a && d == b && c <= e + a)   (c > a && d > b && c <= e + a && c >= e && d <= b + f)
                 b                               b                                 b
          +--------------+                +--------------+                  +--------------+
          |              |                |              |                  |              |
          |              |                |              |                  |              |
          |              |                |              |                  |              |
        c |              | a            c |              | a              c |              | a
          |              |                |              |                  |              |
          |              |                |              |                  |              |
          |              |                |              |                  |              |    f
          +------------------->           |              |                  |         <----|--------+
                 d       |                |              |                  |              |        |
                         |                |              |                  |              |        |
                         +                |              +                  |              +        |
                                          |              ^                  |                       |
                                          |              |                  |                       |
                                          |              | e                |                       | e
                                          |              |                  |                       |
                                          +--------------+                  +-----------------------+
                                                  d                                  d
        */
        const int N = distance.size();
        
        for(int i = 0; i < N; ++i){
            int a = (i < N ? distance[i] : 0);
            int b = (i + 1 < N ? distance[i + 1] : 0);
            int c = (i + 2 < N ? distance[i + 2] : 0);
            int d = (i + 3 < N ? distance[i + 3] : 0);
            int e = (i + 4 < N ? distance[i + 4] : 0);
            int f = (i + 5 < N ? distance[i + 5] : 0);
            if(d > 0 && c <= a && d >= b){
                return true;
            }
            if(e > 0 && c > a && d == b && c <= e + a){
                return true;
            }
            if(f > 0 && c > a && d > b && c <= e + a && c >= e && d <= b + f){
                return true;
            }
        }
        
        return false;
    }
};