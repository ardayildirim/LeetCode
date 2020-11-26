class Solution 
{
public:
    int calculate(string s) 
    {
        string sy1;
        stack<char> opStack;
        int len = s.length();
        int i = 0;
        while(i < len)
        {
            char& c = s[i];
            if(c == ' ')
            {
                i++;
                continue;
            }
            else if(c == '+')
            {
                while(! opStack.empty())
                {
                    sy1.append(1,opStack.top());
                    sy1.append(1,'[');
                    opStack.pop();
                        
                }
                opStack.push(c);
                i++;
            }
            else if(c == '-')
            {
                while(! opStack.empty())
                {
                    sy1.append(1,opStack.top());
                    sy1.append(1,'[');
                    opStack.pop();
                        
                }
                opStack.push(c);
                i++;
            }
            else if(c == '*')
            {
                while( !opStack.empty() && (opStack.top() == '/' || opStack.top() == '*') )
                {
                    sy1.append(1,opStack.top());
                    sy1.append(1,'[');
                    opStack.pop();
                }
                opStack.push(c);
                i++;
            }
            else if(c == '/')
            {
                while( !opStack.empty() && (opStack.top() == '/' || opStack.top() == '*') )
                {
                    sy1.append(1,opStack.top());
                    sy1.append(1,'[');
                    opStack.pop();
                }
                opStack.push(c);
                i++;
            }
            else
            {
                while(i < len && (s[i] >= '0' && s[i] <= '9'))
                {
                    sy1.append(1,s[i]);
                    i++;
                }
                sy1.append(1,'[');
            }
        }
        while(!opStack.empty())
        {
            sy1.append(1,opStack.top());
            opStack.pop();
            sy1.append(1,'[');
        }
        stack<int> valStack;
        i = 0;
        len = sy1.length();
        while(i < len)
        {
            if(sy1[i] == '[')
            {
                i++;
                continue;
            }
            else if(sy1[i] == '+')
            {
                int temp = valStack.top();
                valStack.pop();
                int temp2 = valStack.top();
                valStack.pop();
                valStack.push(temp+temp2);
                i++;
            }
            else if(sy1[i] == '-')
            {
                int temp = valStack.top();
                valStack.pop();
                int temp2 = valStack.top();
                valStack.pop();
                valStack.push(temp2-temp);
                i++;
            }
            else if(sy1[i] == '*')
            {
                int temp = valStack.top();
                valStack.pop();
                int temp2 = valStack.top();
                valStack.pop();
                valStack.push(temp*temp2);
                i++;
            }
            else if(sy1[i] == '/')
            {
                int temp = valStack.top();
                valStack.pop();
                int temp2 = valStack.top();
                valStack.pop();
                valStack.push(temp2/temp);

                i++;
            }
            else
            {
                int temp = 0;
                while(i < len && sy1[i] >= '0' && sy1[i] <= '9')
                {
                    temp = 10* temp + (sy1[i] - '0');
                    i++;
                }

                valStack.push(temp);
                
            }
        }
        return valStack.top();
    }
};