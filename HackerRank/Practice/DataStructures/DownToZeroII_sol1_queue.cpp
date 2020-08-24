int downToZero(int n) {
     const int INF = n + 10;
     
     vector<int> dist(n + 1, INF);
     dist[n] = 0;

     queue<int> q;
     q.push(n);

     while(dist[0] == INF){
         int num = q.front();
         q.pop();

        for(int i = 2; i * i <= num; ++i){
            if(num % i == 0){
                int max_divisor = num / i;
                if(dist[max_divisor] == INF){
                    dist[max_divisor] = 1 + dist[num];
                    q.push(max_divisor);
                }
            }
        }

        if(dist[num - 1] == INF){
            dist[num - 1] = 1 + dist[num];
            q.push(num - 1);
        }
     }

     return dist[0];
}