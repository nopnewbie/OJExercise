class Solution 
{
    bool biSearch(const int target, size_t x, size_t y, const vector<vector<int> >& array)
    {
        size_t upperBound = y;
        for (const auto& a : array)
        {
            if (a.empty())
                continue;

            size_t up;

            if (a.size() < upperBound)
            {
                up = upper_bound(a.cbegin(), a.cend(), target) - a.cbegin();
            }
            else
            {
                up = upper_bound(a.cbegin(), a.cbegin() + upperBound, target) - a.cbegin();
            }

            if (*(a.cbegin() + up) == target || (up > 0 && *(a.cbegin() + up - 1) == target))
                return true;

            if (up != a.size())
                upperBound = up;
        }
        return false;
    }

public:
    bool Find(int target, vector<vector<int> > array) 
    {
        if (array.empty())
            return false;
        size_t maxLen = 0;
        for (const auto& a : array)
        {
            maxLen = maxLen > a.size() ? maxLen : a.size();
        }
        return biSearch(target, 0, maxLen, array);
    }


};