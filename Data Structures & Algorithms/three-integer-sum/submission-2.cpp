class Solution
{
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        vector<vector<int>> result;
        int                 n = nums.size();

        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < n - 2 && nums[i] <= 0; ++i)
        {
            if (i > 0 && nums[i - 1] == nums[i])
                continue;

            int left = i + 1;
            int right = n - 1;

            while (left < right)
            {
                long sum = nums[i] + nums[left] + nums[right];

                if (sum == 0)
                {
                    int left_val = nums[left];
                    int right_val = nums[right];
                    result.push_back({nums[i], left_val, right_val});

                    while (left < right && left_val == nums[left])
                        ++left;
                    while (right > left && right_val == nums[right])
                        --right;
                }
                else if (sum > 0)
                    --right;
                else
                    ++left;
            }
        }
        return (result);
    } 
};
