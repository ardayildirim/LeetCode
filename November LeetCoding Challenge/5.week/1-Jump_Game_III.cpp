class Solution {
private:
    bool reach(vector<vector<int>>& vertices,int i, int end)
    {
        if(vertices[i][0]==i && vertices[i][1]==i)
            return true;
        if(vertices[i][2]!=0)
            return false;
        vertices[i][2]+=1;
        if(vertices[i][0]==-1 && vertices[i][1]==-1)
            return false;
        if(vertices[i][0]==-1)
            return reach(vertices,vertices[i][1],end);
        if(vertices[i][1]==-1)
            return reach(vertices,vertices[i][0],end);
        return reach(vertices,vertices[i][0],end) || reach(vertices,vertices[i][1],end);
    }
public:
    bool canReach(vector<int>& arr, int start) {
        int len = arr.size();
        int ind=0;
        vector<int> zerosInd;
        for(;ind<len;ind++)
        {
            if(arr[ind]==0)
                zerosInd.push_back(ind);
        }
        if(!zerosInd.size())
            return false;
        vector<vector<int>> vertices(len,vector<int>(3,0));
        for(int i=0;i<len;i++)
        {
            if(i-arr[i]<0)
                vertices[i][0]=-1;
            else
                vertices[i][0]=i-arr[i];
            if(i+arr[i]>=len)
                vertices[i][1]=-1;
            else
                vertices[i][1]=i+arr[i];
        }
        for(int i : zerosInd){
            if(reach(vertices,start,i))
                return true;
            for(int i=0;i<len;i++)
                vertices[i][2]=0;
        }
        return false;
    }
};