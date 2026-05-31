class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int         num_count = nums.size();
        vector<int> output(num_count, 1);

        int i = 0;
        int product = 1;
        while (i < num_count) {
            output[i] *= product;
            product *= nums[i];
            ++i;
        }

        --i;
        product = 1;
        while (i >= 0) {
            output[i] *= product;
            product *= nums[i];
            --i;
        }
        return (output);
    }
};
