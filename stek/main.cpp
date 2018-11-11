#include <iostream>
#include "string"
#include "steck.h"


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
	try {
		while (*a != '\0') {
			if (*a == '(') {
				steck.push(*a);
			}
			if(*a == ')') {
				steck.pop();
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
	catch (out_of_range) {
		return false;
	}

}

	
int main()
{
	Steck<int>a;
	a.push(0);
	a.push(1);
	a.push(2);
	a.push(3);
	char s[] = "(((()))";
	
	cout << a.pop_in_head();

	
 


	return 0;
}