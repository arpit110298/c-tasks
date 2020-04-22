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

std::vector<std::string> tokenize(std::string line)
{
	std::vector<std::string> tokens;
	boost::algorithm::split(tokens, line, boost::is_any_of(","));
	return(tokens);
}




std::string take_input(int argc, char *argv[])
{
	std::string filename;
	po::options_description desc("Allowed Options");	
	desc.add_options()
		("inp", po::value<std::string>(&filename)->default_value("abc"), "inputfile" )
	;
	po::variables_map vm;
	po::store(po::parse_command_line(argc, argv, desc), vm);
	po::notify(vm);
	if(vm.count("inp"))
	{
		return(filename);
	}
}

struct employee* read_from_file(std::string filename)
{
	struct employee *empl = new struct employee[20];
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
			empl[i].id = stoi(tokens[0]);
			empl[i].name = tokens[1];
			empl[i].dept = tokens[2];
			empl[i].salary = stoi(tokens[3]);
			++i;
		}
		file.close();
		return(empl);
	}

}

bool sortparameter(employee a, employee b)
{
	return(a.salary<b.salary);
}

int main(int argc, char *argv[])
{
	std::string filename = take_input(argc ,argv);
	struct employee *empl = read_from_file(filename);
	std::sort(empl, empl+20, sortparameter);
	for(int i=0; i<20; i++)
	{
		std::cout << empl[i].salary << std::endl;
	}
	
}
