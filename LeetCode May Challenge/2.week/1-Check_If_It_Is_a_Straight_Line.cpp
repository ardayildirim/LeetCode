
    bool checkStraightLine(vector<vector<int>>& coordinates) 
    {
        sort(coordinates.begin(),coordinates.end());
        int prevx = coordinates[0][0];
        int prevy = coordinates[0][1];
        int len = coordinates.size();
        int prev = prevx;
        for(int i = 1; i < len; i++)
        {
            if(coordinates[i][0] == prev)
                return false;
            prev = coordinates[i][0];
        }
        double ratio = (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
        for(int i = 1; i < len; i++)
        {
            if( (coordinates[i][1] - prevy) / (coordinates[i][0] - prevx) != ratio)
                return false;
            prevx = coordinates[i][0];
            prevy = coordinates[i][1];
        }
        return true;
    }
