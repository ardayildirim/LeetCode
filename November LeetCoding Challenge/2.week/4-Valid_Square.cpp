class Solution 
{
private:
    float find_dist(vector<int> &p1,vector<int> &p2)
    {
        return sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]));
    }
public:
    //float comparisons may not be accurate. so instead of '==' i use difference is
    // less than 0.001 
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) 
    {
        float d12,d13,d14;
        d12 = find_dist(p1,p2); 
        d13 =  find_dist(p1,p3);
        d14 = find_dist(p1,p4);
        if( abs(d12 - d13) <= 0.001 && p2 != p3)
        {
            if(d14 / d13 - 1.4142 <= 0.001 && find_dist(p4,p2)-d12 <= 0.001  && find_dist(p4,p3)-d12 <= 0.001 )
                return true;
            return false;
        }
        if( abs(d12 - d14) <= 0.001 && p2 != p4)
        {
            if(d13 / d12 - 1.4142 <= 0.001 && find_dist(p3,p4)-d12 <= 0.001  && find_dist(p3,p2)-d12 <= 0.001)
            {

                return true;
            }
                
            return false;
        }
        if( abs(d13-d14) <= 0.001 && p3 != p4)
        {
            if(d12 / d13 - 1.4142 <= 0.001  && find_dist(p2,p3)-d13 <= 0.001  && find_dist(p4,p2)-d13 <= 0.001)
                return true;
            return false;
        }

        return false;
        
    }
};