class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        std::unordered_map<int, int> mp;
        std::vector<int> ans;

        //  用哈希表来做
        for (int i = 0; i < nums.size(); i++) //  对于数组中的每个数据
        {
            //  判断target - numbers[i]在不在
            if (mp.count(target - nums[i])) //  如果在里面
            {
                //  那么numbers中就存在两个数和为target
                ans.push_back(mp[target - nums[i]]);
                ans.push_back(i);
                break;
            }

            if (mp.count(nums[i]) != 1)
            {
                mp[nums[i]] = i;
            }
        }
        return ans;
    }
};