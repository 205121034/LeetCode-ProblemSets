class Solution
{
public:
    int numSteps(std::string s)
    {
        
        int stepsCount = 0;
        int carryValue = 0;
        int stringLength = static_cast<int>(s.length());

        
        for (int index = stringLength - 1; index > 0; --index)
        {
            
            int currentBit = (s[index] - '0') + carryValue;

            
            if (currentBit % 2 == 0)
            {
                
                stepsCount += 1;
            }
            else
            {
                
                stepsCount += 2;

                
                carryValue = 1;
            }
        }

        
        if (carryValue == 1)
        {
            stepsCount += 1;
        }

        return stepsCount;
    }
};