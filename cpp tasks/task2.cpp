#include<iostream>
int main(){
	auto multiplier = [](int outside_arg) {return [=](int inside_arg) { return outside_arg * inside_arg; };};

	auto twice = multiplier(3);
	std::cout << twice(4);      
	std::cout << twice(5);     

	auto thrice = multiplier(2);
	std::cout << thrice(4);      
	std::cout << thrice(5);      
}
