class Solution {
public:
    int mirrorReflection(int p, int q) 
    {
        bool right = false;
        int y = 0;
        int dir = 1; //1 means up, 2 means down, initially up
        while( !((right && y == 0) || (right &&  y == p) || (!right && y == p))) 
        {
            if(dir == 1 && y + q < p)
            {
                y += q;
            }
            else if(dir == 1)
            {
                dir = 0;
                y = 2*p-y-q;
            }
            else if(dir == 0 && y - q >= 0)
            {
                y -= q;
            }
            else if(dir == 0)
            {
                dir = 1;
                y = q - y;
            }
            right = !right;
            
        }
        if(right && y == 0)
            return 0;
        if(right &&  y == p)
            return 1;
        if(!right && y == p)
            return 2;
        return 0;
    }
};