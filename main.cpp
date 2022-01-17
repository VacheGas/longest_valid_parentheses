#include <iostream>
#include <stack>

class Solution {
private:
    int     ret_max(int new_max, int old_max);
public:
    int longestValidParentheses(std::string s);
};

int Solution::ret_max(int new_max, int old_max)
{
    if(new_max > old_max)
        return (new_max);
    else
        return (old_max);
}

int Solution::longestValidParentheses(std::string line)
{
	std::stack<int> st;
	int 			i;
	size_t			length;
	int				max_len;

	i = 0;
	st.push(-1);
	max_len = 0;
	length = line.length();
	while (i < length)
	{
		if(line[i] == '(')
			st.push(i);
		else
			{
				st.pop();
				if(st.empty())
					st.push(i);
				else
					max_len = ret_max(max_len, i - st.top());
			}
		i++;
	}
	return (max_len);
}

int main()
{
	std::string s;
	Solution valid_parentheses;
	int result;

	s = ")()())()()(";
	result = valid_parentheses.longestValidParentheses(s);
	std::cout << result;
	s = "()(()";
	result = valid_parentheses.longestValidParentheses(s);
	std::cout << result;
	s = ")()())";
	result = valid_parentheses.longestValidParentheses(s);
	std::cout << result;
	s = "(())";
	result = valid_parentheses.longestValidParentheses(s);
	std::cout << result;
	s = "()";
	result = valid_parentheses.longestValidParentheses(s);
	std::cout << result;
}