//#include "encryption.h"
#include <iostream>
#include <fstream>
#include <filesystem>

using namespace std; 
namespace fs = std::filesystem;
int sizeOfDirectory2(string path);
void fillArray2(string *pathToFill, int size, string path);

void decrypt(string key)
{
	string path = "/mnt/c/Users/yavuz/important_files";

	int size = sizeOfDirectory2(path);
	string* paths = new string[size];
	fillArray2(paths, size, path);


	char c;
	for(int i = 0; i < size; i++)
	{
		fstream handler;
		handler.open(paths[i], ios::in | ios::out );

		if(handler.is_open())
		{
			while(handler.get(c))
			{
				char temp;
				int orderInKey;
				for(int j = 0; j < 95; j++)
				{
					if(c == key[j])
					{
						orderInKey = j;
						break;
					}
				
				}
				temp = char(orderInKey + 32);
				
		                handler.seekp(-1, ios::cur);
				handler.put(temp);	

	
			}
			handler.close();

		}
	}	
	
}





void fillArray2(string* pathToFill, int size, string path)
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

int sizeOfDirectory2(string path)
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



     
