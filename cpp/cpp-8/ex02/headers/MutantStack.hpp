#pragma once

#include <stack>

#define	MUTANT_STACK_ALLOC_SIZE	16

template<typename T>
class MutantStack: public std::stack<T>
{
	private:
		T		*_stack;
		size_t	_capacity;
		size_t	_nb_elt;

	public:
		typedef int *		iterator;
		typedef const int *	const_iterator;

	/* -Constructors- */
		MutantStack();
		MutantStack(const MutantStack &_other);

	/* -Destructors-  */
		~MutantStack();

	/*    -Getter-    */
	const T	&top(void) const;
	T		&top(void);
	bool	empty(void) const;
	size_t	size(void) const;

	/*    -Setter-    */
		//...

	/*  -Operators-   */
		MutantStack &operator=(const MutantStack &_other);

	/*  -Modifiers-   */
		void	push(const T &_value);
		void	pop(void);

	/*  -Modifiers-   */
		iterator		begin(void);
		iterator		end(void);

		const_iterator	begin(void) const;
		const_iterator	end(void) const;

		const_iterator	cbegin() const;
		const_iterator	cend() const;
};

#include "MutantStack.tpp"