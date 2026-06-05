class Solution
{
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = n * m - 1;

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            std::cout << mid << "\n";
            int selected = matrix[(int)(mid / m)][mid % m];

            if (selected == target)
                return (true);

            if (selected > target)
                right = mid - 1;
            else
                left = mid + 1;
        }
        return (false);
    }
};
