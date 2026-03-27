#include <iostream>
#include <string>
#include <vector>

bool partition(std::string example, std::vector<double>& nums, std::vector<char>& act)
{
	for (int p = 0; p < example.size();)
	{
		if (example[p] >= '0' && example[p] <= '9')
		{
			double r = 0;
			while (p < example.size() && example[p] >= '0' && example[p] <= '9')
			{
				r = r * 10 + (example[p] - '0');
				p++;
			}
			nums.push_back(r);
		}
		else if (example[p] == ' ')
		{
			while(p < example.size() && example[p] == ' ')
			{
				p++;
			}
		}
		else if (example[p] == '+' || example[p] == '-' || example[p] == '*' || example[p] == '/')
		{
			if (p==0 || (act.size() == nums.size()))
			{
				std::cerr << "Invalid expression\n";
				return false;
			}
			act.push_back(example[p]);
			p++;
		}
		else
		{
			std::cerr << "Invalid symbol\n";
			return false;
		}
	}
	return true;
}
bool processMulDiv(std::vector<double>& nums, std::vector<char>& act)
{
	for (int p = 0; p < act.size(); ) {
		if (act[p] == '*' || act[p] == '/')
		{
			double res = 0;
			if (act[p] == '*')
			{
				res = nums[p] * nums[p + 1];
			}
			else if (act[p] == '/')
			{
				if (nums[p + 1] == 0) {
					std::cerr << "Division by zero\n";
					return false;
				}
				res = nums[p] / nums[p + 1];
			}
			nums[p] = res;
			nums.erase(nums.begin() + p + 1);
			act.erase(act.begin() + p);
		}
		else p++;
	}
	return true;
}
void processAddSub(std::vector<double>& nums, std::vector<char>& act)
{
	for (int p = 0; p < act.size(); ) {
		if (act[p] == '+' || act[p] == '-')
		{
			double res = 0;
			if (act[p] == '+')
			{
				res = nums[p] + nums[p + 1];
			}
			else if (act[p] == '-')
			{
				res = nums[p] - nums[p + 1];
			}
			nums[p] = res;
			nums.erase(nums.begin() + p + 1);
			act.erase(act.begin() + p);
		}
		else p++;
	}
}
int main()
{
	std::string example;
	getline(std::cin, example);
	std::vector<double> nums;
	std::vector<char> act;
	if (partition(example, nums, act))
	{
		if (nums.empty()) {
			std::cerr << "Invalid expression\n";
			return 0;
		}
		if (nums.size() == act.size() + 1) { 
			if (!processMulDiv(nums, act)) return 0;
			processAddSub(nums, act);
			std::cout << "Result:" << nums[0] << std::endl;
		}
		else
		{
			std::cerr << "Invalid expression\n";
			return 0;
		}
	}
	return 0;
}
