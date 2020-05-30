class Solution {
    bool cycle(vector<int> v[], int i, vector<char>& visited)
    {
        if(visited[i] == 1)
            return true;
        visited[i] = 1;
        for(auto j : v[i])
            if(cycle(v,j,visited))
                return true;
        visited[i] = 2;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> v[numCourses];
        vector<char> visited(numCourses,0);
        for(auto i : prerequisites)
        {
            v[i[1]].push_back(i[0]);
        }
        for(int i = 0; i < numCourses; i++)
            if(cycle(v,i,visited))
                return false;
        return true;
    }
};
