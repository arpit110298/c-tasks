#include<iostream>
#include <chrono> 

// TODO: Try not use using namespace
using namespace std::chrono; 


void func()
{
	std::cout << "Hello World\n";
}


// TODO: One thing, every time you have to calculate time of snippet. You will have to write the statements again and again
// TODO: Try to make a reusable component

int main()
{	
	auto start = high_resolution_clock::now();
	func();
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	std::cout << "Time to execute is : ";
	std::cout << duration.count() << " microsecinds" << std::endl;

    // TODO: return statement ??
}
