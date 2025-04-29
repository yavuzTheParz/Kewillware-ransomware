#include <cstdlib>
#include <iostream>
#include <ctime>

using namespace std;


bool letterContain(char kaka[], int x, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (kaka[i] == x)
			return false; 
	}

	return true; 
}

string generate_key()
{
	srand(time(NULL)); 
	char key[27];
	for(int i= 0; i < 27; i++)
	{
 		int x = 0; 	
		while(1)
		{	
		       		
    			x = (rand() % 94) + 32;
			 if(letterContain(key, x, 27))
				 break;
		}  
		key[i] = x;
	
	}
	for(int i = 0; i < 27; i++)
		cout << key[i] << endl;

	return key;
}



int main()
{
	generate_key(); 

}
