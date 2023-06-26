#include  "MutantStack.hpp"
#include  <deque>
#include  <list>

void testIterator( void ) 
{	
	{
		printHeader("TEST: ITERATOR", '=', ORANGE);
		printHeader("MutantStack", '~', MAGENTA);

		MutantStack<int> mstack;

		printSeparator();
		std::cout << "Adding elements: 5 | 17" << std::endl;
		mstack.push(5);
		mstack.push(17);

		printSeparator();
		std::cout << "Elements in stack after adding: " << std::endl;
		printStackOrder(mstack);

		printSeparator();
		std::cout << "First element: " << mstack.top() << std::endl;

		printSeparator();
		std::cout << "Removing the first element..." << std::endl;
		mstack.pop();

		printSeparator();
		std::cout << "Size = " << mstack.size() << std::endl;
		
		printSeparator();
		std::cout << "Printing stack elements after removal:" << std::endl;
		printStackOrder(mstack);
		
		printSeparator();
		std::cout << "Adding elements: 3 | 5 | 737 | 0" << std::endl;	
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;

		printSeparator();
		std::cout << "Printing stack elements:" << std::endl;
		while (it != ite)
		{
			std::cout << " | " <<*it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		printHeader("Deque", '~', MAGENTA);
		std::deque<int> deque;
		std::cout << "Adding elements: 5 | 17" << std::endl;
		deque.push_back(5);
		deque.push_back(17);

		printSeparator();
		std::cout << "Elements in stack after adding: " << std::endl;
		printStackOrder(deque);

		printSeparator();
		std::cout << "First element: " << deque.back() << std::endl;

		printSeparator();
		std::cout << "Remove first element..." << std::endl;
		deque.pop_back();

		printSeparator();
		std::cout << "size = " << deque.size() << std::endl;
		
		printSeparator();
		std::cout << "Printing stack elements after removal:" << std::endl;
		printStackOrder(deque);
		
		printSeparator();
		std::cout << "Adding elements: 3 | 5 | 737 | 0" << std::endl;	
		deque.push_back(3);
		deque.push_back(5);
		deque.push_back(737);
		deque.push_back(0);
		MutantStack<int>::iterator it = deque.begin();
		MutantStack<int>::iterator ite = deque.end();
		++it;
		--it;

		printSeparator();
		std::cout << "Printing stack elements :" << std::endl;
		while (it != ite)
		{
			std::cout << " | " <<*it << std::endl;
			++it;
		}
		std::stack<int> s(deque);
	}
	std::cout << std::endl << std::endl;
}

void	testReverseIterator(void)
{
	printHeader("TEST: REVERSE ITERATOR", '=', ORANGE);
	{
		printHeader("MutantStack", '=', MAGENTA);
		MutantStack<int> mstack;
		printSeparator();

		std::cout << "Adding elements: 5 | 17" << std::endl;
		mstack.push(5);
		mstack.push(17);

		printSeparator();
		std::cout << "Elements in stack after adding: " << std::endl;
    	printStackOrder(mstack);

		printSeparator();
		std::cout << "First element: " << mstack.top() << std::endl;

		printSeparator();
		std::cout << "Removing first element..." << std::endl;
		mstack.pop();

		printSeparator();
		std::cout << "Size = " << mstack.size() << std::endl;
		
		printSeparator();
		std::cout << "Printing stack elements after removal:" << std::endl;
		printStackOrder(mstack);
		
		printSeparator();
		std::cout << "Adding elements: 3 | 5 | 737 | 0" << std::endl;	
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::reverse_iterator it = mstack.rbegin();
		MutantStack<int>::reverse_iterator ite = mstack.rend();
		++it;
		--it;

		printSeparator();
		std::cout << "Printing stack elements:" << std::endl;
		while (it != ite)
		{
			std::cout << " | " <<*it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		printHeader("Deque", '=', MAGENTA);
		std::list<int> list;
		std::cout << "Adding elements: 5 | 17" << std::endl;
		list.push_back(5);
		list.push_back(17);

		printSeparator();
		std::cout << "Elements in stack after adding: " << std::endl;
    	printStackOrder(list);

		printSeparator();
		std::cout << "First element: " << list.back() << std::endl;

		printSeparator();
		std::cout << "Removing first element..." << std::endl;
		list.pop_back();

		printSeparator();
		std::cout << "Size = " << list.size() << std::endl;
		
		printSeparator();
		std::cout << "Printing stack elements after removal:" << std::endl;
		printStackOrder(list);
		
		printSeparator();
		std::cout << "Adding elements: 3 | 5 | 737 | 0" << std::endl;	
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::reverse_iterator it = list.rbegin();
		std::list<int>::reverse_iterator ite = list.rend();
		++it;
		--it;

		printSeparator();
		std::cout << "Printing stack elements :" << std::endl;
		while (it != ite)
		{
			std::cout << " | " <<*it << std::endl;
			++it;
		}
		std::list<int> s(list);
	}
	std::cout << std::endl << std::endl;
}

void	testCopy()
{
	printHeader("TEST: COPY", '=', ORANGE);
	MutantStack<int> stack;
	std::cout << "Adding elements..." << std::endl;
	for (int i = 0; i < 5; i++)
		stack.push(i + 2);

	printSeparator();
	std::cout << "Elements in stack after adding: " << std::endl;
	printStackOrder(stack);

	printSeparator();
	MutantStack<int>	copyStack(stack);
	std::cout << "Elements in copy instance: " << std::endl;
	printStackOrder(copyStack);

	printSeparator();
	std::cout << "Removing elements from the stack..." << std::endl;
	stack.pop();
	stack.pop();

	printSeparator();
	std::cout << "Printing stack elements after removal: (Modified)" << std::endl;
	printStackOrder(stack);

	printSeparator();
	std::cout << "Printing copy instance elements after removal: (Unmodified)" << std::endl;
	printStackOrder(copyStack);

}

int main()
{	
	testIterator();
	testReverseIterator();
	testCopy();
}