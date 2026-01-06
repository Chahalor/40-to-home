#include <iostream>
#include <stack>

#include "MutantStack.hpp"

static void	print_std_stack(std::stack<int> s)
{
	std::cout << "std::stack contents (top -> bottom): ";
	while (!s.empty())
	{
		std::cout << s.top();
		s.pop();
		if (!s.empty())
			std::cout << ", ";
	}
	std::cout << std::endl;
}

static void	print_mutant_stack(const MutantStack<int> &s)
{
	MutantStack<int>::const_iterator it = s.begin();
	MutantStack<int>::const_iterator ite = s.end();

	std::cout << "MutantStack contents (bottom -> top): ";
	while (it != ite)
	{
		std::cout << *it;
		++it;
		if (it != ite)
			std::cout << ", ";
	}
	std::cout << std::endl;
}

int	main()
{
	std::stack<int>	st;
	MutantStack<int>	ms;

	st.push(5);
	st.push(17);
	ms.push(5);
	ms.push(17);

	std::cout << "std::stack top: " << st.top() << ", size: " << st.size() << std::endl;
	std::cout << "MutantStack top: " << ms.top() << ", size: " << ms.size() << std::endl;

	st.pop();
	ms.pop();

	st.push(3);
	st.push(5);
	st.push(737);
	st.push(0);

	ms.push(3);
	ms.push(5);
	ms.push(737);
	ms.push(0);

	print_std_stack(st);
	print_mutant_stack(ms);

	return (0);
}
