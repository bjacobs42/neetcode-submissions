class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        int                 i;
        vector<vector<int>> result;

        i = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); ++i)
        {
            int target = -nums[i];
            int left = i + 1;
            int right = nums.size() - 1;

            while (left < right)
            {
                int sum = nums[left] + nums[right];

                if (sum == target)
                {
                    result.push_back({nums[i], nums[left], nums[right]});
                    while (left + 1 < right && nums[left] == nums[left + 1])
                        ++left;
                    while (right - 1 > left && nums[right] == nums[right - 1])
                        --right;
                    ++left;
                    --right;
                }
                else if (sum > target)
                    --right;
                else
                    ++left;
            }

            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                ++i;
        }
        return (result);
    } 
};
