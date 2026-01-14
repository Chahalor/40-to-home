#include <iostream>
#include <stack>

#include "MutantStack.hpp"

__attribute_maybe_unused__
static void	print_std_stack(
	std::stack<int> &s
)
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

__attribute_maybe_unused__
static void	print_mutant_stack(
	const MutantStack<int> &s
)
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

/* int main()
{
	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return 0;
} */