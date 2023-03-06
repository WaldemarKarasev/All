#include <iostream>
#include <vector>

void printStack(const std::vector<int> &stack)
{
	for (const auto& element : stack)
		std::cout << element << ' ';
	std::cout << "(cap " << stack.capacity() << " length " << stack.size() << ")\n";
}


int main()
{
	std::vector<int> stack;

	printStack(stack);
		
	stack.push_back(7); 
	printStack(stack);
	
	stack.push_back(4);
	printStack(stack);

	stack.push_back(1);
	printStack(stack);

	std::cout << "top: " << stack.back() << '\n'; 
		
	stack.pop_back(); 
	printStack(stack);
	
	stack.pop_back();
	printStack(stack);

	stack.pop_back();
	printStack(stack);
	
	std::cout << '\n';
	std::vector<int> vect = { 0, 1, 2, 3, 4, 5 };
	std::cout << "size: " << vect.size() << " cap: " << vect.capacity() <<'\n';
	
	vect.push_back(6); 
	std::cout << "size: " << vect.size() << " cap: " << vect.capacity() <<'\n';

	return 0;
}