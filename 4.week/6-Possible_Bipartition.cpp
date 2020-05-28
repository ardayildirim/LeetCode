class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
        int i, j;
        int k,u;
        int v,s;
        vector<vector<int>> graph(N, vector<int>());
        queue<int> q;
        vector<int> visited(N, 0);
        int ds = dislikes.size();
        for(i = 0; i < ds; i++)
        {
            v = dislikes[i][1] - 1;
            u = dislikes[i][0] - 1;
            
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        
        for(i = 0; i < N; i++)
        {
            if(visited[i] != 0)
                continue;    
            q.push(i);
            visited[i] = 1;
            while(!q.empty())
            {
                s = q.size();
                for(j = 0; j < s; j++)
                {
                    u = q.front();
                    q.pop();
                    for(k = 0; k < graph[u].size(); k++)
                    {
                        v = graph[u][k];
                        if(visited[v] == 0)
                        {
                            q.push(v);
                            visited[v] = visited[u] == 1 ? 2 : 1;
                        }
                        
                        if(visited[v] == visited[u])
                        {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
        
    }
};
