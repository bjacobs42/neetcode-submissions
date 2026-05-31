class Solution 
{
public:
    int maxArea(vector<int>& heights)
    {
        int left = 0;
        int right = heights.size() - 1;
        int biggestArea = 0;

        while (left < right)
        {
            int area = (right - left) * std::min(heights[left], heights[right]);
            biggestArea = std::max(area, biggestArea);

            if (heights[left] < heights[right])
                ++left;
            else if (heights[left] > heights[right])
                --right;
            else
            {
                ++left;
                --right;
            }
        }
        return (biggestArea);
    }
};
