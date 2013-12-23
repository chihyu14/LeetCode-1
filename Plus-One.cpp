class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        //Big Int
        int size = digits.size()-1;
        digits[size] += 1;
        for(int i=size; i>0; --i)
            {
                if(digits[i]>9)
                    {
                        digits[i] = 0;
                        digits[i-1] += 1;
                    }
            }
        if(digits[0]>9)
            {
                digits[0] = 0;
                digits.insert(digits.begin(), 1);
            }
        return digits;
    }
};