#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std;
void encrypt(string key);
namespace fs = std::filesystem;
int sizeOfDirectory(std::string path);
void fillArray(string *pathToFill, int size, string path); 


void encrypt(string key)
{
	string path = "/mnt/c/Users/yavuz/important_files";

	int size = sizeOfDirectory(path);
	string* paths = new string[size];
	fillArray(paths, size, path);


	for(int i = 0; i < size; i++)
	{
		char c;
		fstream handler;
		handler.open(paths[i], ios::in | ios::out);

		while(handler.get(c))
		{
			char temp;
			temp = key[c - 32];
			handler.seekp(-1, ios::cur);
			handler.put(temp);
		}
		handler.close();

	}
}


void fillArray(string *pathToFill, int size, string path)
{	
	int counter = 0;
	for (const auto& entry : fs::directory_iterator(path)) 
	{
        	if (fs::is_regular_file(entry.status())) 
		{
			pathToFill[counter] = entry.path();
			counter++;
        	}
   	}
}

int sizeOfDirectory(string path)
{
	int counter = 0;
	
	for (const auto& entry : fs::directory_iterator(path)) 
	{
        	if (fs::is_regular_file(entry.status())) 
		{
			counter++;
        	}
   	}
	return counter;
}

