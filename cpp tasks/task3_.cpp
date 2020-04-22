#include<iostream>
#include <chrono> 
using namespace std::chrono; 


void func()
{
	std::cout << "Hello World\n";
}


int main()
{	
	auto start = high_resolution_clock::now();
	func();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time to execute is : ";
	std::cout << duration.count() << " microsecinds" << std::endl;
}
