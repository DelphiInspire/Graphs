#include <vector>
#include <algorithm>

class Solution
{
private:
	std::vector<std::pair<int, int>> mList;
	std::vector<int> result;
	int mTarget;


public:
	std::vector<int> twoSum(std::vector<int>& nums, int target)
	{
		for (size_t counter = 0; counter < nums.size(); counter++)
			mList.push_back(std::make_pair(nums[counter], counter));
		std::sort(mList.begin(), mList.end());
		mTarget = target;
		int first = 0;
		int last = mList.size() - 1;
		while (first < last)
		{
			int s = mList[first].first + mList[last].first;
			if (s > target)
			{
				last--;
			}
			else if (s < target)
			{
				first++;
			}
			else
			{
				result.push_back(first);
				result.push_back(last);
				return result;
			}
		}
		return result;
	}
};
