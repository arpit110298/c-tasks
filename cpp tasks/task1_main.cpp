#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<boost/program_options.hpp>
#include<boost/algorithm/string.hpp>
#include<algorithm>
namespace po = boost::program_options;

struct employee
{
	int id;
	std::string name;
	std::string dept;
	int salary;
		
};

// TODO: Start using trailing return types
std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> tokens;
	boost::algorithm::split(tokens, line, boost::is_any_of(","));
    // TODO: Why did you write tokens inside parenthesis?
    // It should not be written in paranthesis
    // https://stackoverflow.com/questions/4762662/are-parentheses-around-the-result-significant-in-a-return-statement
	return(tokens);
}



// If it is compiled with option -Werror, then the compilation would fail
// TODO: This function produces warning, Try not to ignore warnings..... warning: control reaches end of non-void function
std::string take_input(int argc, char *argv[])
{
	std::string filename;
	po::options_description desc("Allowed Options");	
	desc.add_options()
        // TODO: Always add help option, User does not exactly know how to use your application
        // TODO: Instead of default, it should be mandatory. Let the user pass the file instead of using your own file.
		("inp", po::value<std::string>(&filename)->default_value("abc"), "inputfile" )
	;
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);
    // I don't think you needed to check vm.count here, since you made it default. ie it will always be true
	if(vm.count("inp"))
	{
		return(filename);
	}
    // TODO: function does not return anything. You are just lucky here, since the if condition above will always be true
}

// TODO: This function can be designed without using raw pointers
// TODO: Try not to use raw pointers
// TODO: 'filename' parameter should be const, Since we are not going to modify it. First instict should be to always go with const 
struct employee* read_from_file(std::string filename)
{
    // TODO: Where have you delete this memory?? How did you know it is going to be 20 ??
	struct employee *empl = new struct employee[20];
    // TODO: instead of calling open(), pass filename to the object while constructing. You won't have to call close() on the file then
	std::fstream file;
	file.open(filename);
	std::vector<std::string> v;
	int i = 0;
	std::vector<std::string> tokens;
        if (file.is_open())
  	{
		std::string line;
		while(std::getline(file, line))
		{
			//std::cout << line;
			tokens = tokenize(line);
            // TODO: Instead of separate assignments, better to create constructor to do the work for you
			empl[i].id = stoi(tokens[0]);
			empl[i].name = tokens[1];
			empl[i].dept = tokens[2];
			empl[i].salary = stoi(tokens[3]);
			++i;
		}
		file.close();
        // TODO: Why wrote in paranthesis
		return(empl);
	}
    // TODO: What if the if condition is false, what are you going to return then ??

}

// TODO: employee should be const. don't make useless copies
bool sortparameter(employee a, employee b)
{
	return(a.salary<b.salary);
}

int main(int argc, char *argv[])
{
    // TODO: 'filename' should be made 'const'
	std::string filename = take_input(argc ,argv);
	struct employee *empl = read_from_file(filename);
	std::sort(empl, empl+20, sortparameter);
    // TODO: pre-increment instead of post-increment
	for(int i=0; i<20; i++)
	{
        // TODO: Why did you just print salary, How am I going to know that which employee has highest salary
        // TODO: std::endl flushes the cout stream.. It is not good to flush it everytime
		std::cout << empl[i].salary << std::endl;
	}
    // TODO: Did not return anything
	
}
