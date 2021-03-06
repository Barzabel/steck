#include <iostream>
#include "steck.h"
#include "string"

class any
{
public:
	template<typename T>
	any(const T& t) : held_(new holder<T>(t)) {}



	~any() { delete held_; }



	template<typename U>
	U cast() const
	{
		if (typeid(U) != held_->type_info())
			throw std::runtime_error("Bad any cast");
		return static_cast<holder<U>*>(held_)->t_;
	}
private:
	struct base_holder
	{
		virtual ~base_holder() {}
		virtual const std::type_info& type_info() const = 0;
	};

	template<typename T> 
	struct holder : base_holder
	{
		holder(const T& t) : t_(t) {}
		const std::type_info& type_info() const
		{
			return typeid(t_);
		}
		T t_;
	};
private:
	base_holder* held_;
};


bool fun(char *a ) {
	Steck<char>steck;
	
	while (*a != '\0') {
		{
				if (*a == '(')
				{
					steck.push(*a);
				}
				if (*a == ')') 
				{
					if (steck.Size() == 0) {
						return false;
					}
					steck.pop();
				}
		}
			a++;
	}
		if (steck.Size() == 0) {
			return true;
		}
		else {
			return false;
		}
	}
	


int fun2(char *a) {
	Steck<char>steck1;
	Steck<int>steck2;
	int res = 0;
	char *b = a;
	int i = -1;
	while (*b != '\0') {
		b++;
		i++;
	}
	while (i >= 0)
	{
		steck1.push(*(a + i));
		i--;
	}
	int a1 = 0;
	int b1 = 0;

	while (steck1.Size() > 0) {
		if ((steck1.Size() > 0) && (steck1.peek() >= '0') && (steck1.peek() <= '9') && (steck2.Size() < 2))
		{
			if (steck2.Size() > 0) {
				//cout << steck2.peek() << endl;
			}

			steck2.push(0);
			


			while ((steck1.Size() > 0) && (steck1.peek() >= '0') && (steck1.peek() <= '9') && (steck2.Size() > 0))
			{

				steck2.push(steck2.pop() * 10 + int(steck1.pop() - '0'));

			}
			//cout << steck2.peek() << endl;
		}
		else 
		{
			if (steck1.peek() == '+') {
				steck2.push(steck2.pop() + steck2.pop());
				steck1.pop();
				
			}
			if ((steck1.peek() == '-')) {
				a1 = steck2.pop();
				b1 = steck2.pop();
				steck2.push(b1 - a1);
				
				steck1.pop();
				
			}
			if ((steck1.peek() == '*')) {
				steck2.push(steck2.pop() * steck2.pop());
				steck1.pop();
				
			}
			if ((steck1.peek() == '/')) {
				steck2.push(steck2.pop_in_head() / steck2.pop());
				steck1.pop();
				

			}
			if ((steck1.peek() == '=')) {
				return steck2.peek();
				
			}
			else if (steck1.peek() == ' ') {
				steck1.pop();
			}


		}

		

		
		
		
	}
return steck2.peek();
}

int main()
{
	Steck<int>a;
	a.push(1);
	char s[] = "82 22 + 55 -2*3/ =";
	cout<<fun2(s);
    // fun2(s);





	return 0;
}