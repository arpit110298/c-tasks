#include<iostream>

int main(){
    /*
     * Better readability
     * TODO: Read about lambda captures
     *
	   auto multiplier = [](int outside_arg) {
           return [=](int inside_arg) { return outside_arg * inside_arg; };
       };
     */
	auto multiplier = [](int outside_arg) {return [=](int inside_arg) { return outside_arg * inside_arg; };};

	auto twice = multiplier(3);
    // TODO: At least add newline character after every print statement
	std::cout << twice(4);      
	std::cout << twice(5);     

	auto thrice = multiplier(2);
	std::cout << thrice(4);      
	std::cout << thrice(5);      
    // TODO: should flush the std::cout stream
    // TODO: return statement?
}
