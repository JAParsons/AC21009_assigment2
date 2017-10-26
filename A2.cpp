// AC21009
// John Parsons 160006092
// Alex Quinn

#include <iostream>
#include <string>

using namespace std;


int width; //width of grid
int height; //height of grid (number of generations)
int rule; //entered decimal rule
int binaryRule[8] {0,0,0,1,1,1,1,0}; //array to hold the rule in a binary format



int ruleResult(int lft, int mid, int rght) //input 3 cell states and use specified rules to return the state of the new cell 
{
	if(lft == 1 && mid == 1 && rght == 1)
	{
		return binaryRule[0];
	}
	else if(lft == 1 && mid == 1 && rght == 0)
	{
		return binaryRule[1];
	}
	else if(lft == 1 && mid == 0 && rght == 1)
	{
		return binaryRule[2];
	}
	else if(lft == 1 && mid == 0 && rght == 0)
	{	
		return binaryRule[3];
	}
	else if(lft == 0 && mid == 1 && rght == 1)
	{
		return binaryRule[4];
	}
	else if(lft == 0 && mid == 1 && rght == 0)
	{
		return binaryRule[5];
	}
	else if(lft == 0 && mid == 0 && rght == 1)
	{
		return binaryRule[6];
	}
	else if(lft == 0 && mid == 0 && rght == 0)
	{
		return binaryRule[7];
	}

	return 0;
}


void convert(int number) //method to convert an int input to binary format
{
	
}


int main()
{	
	// get user input
	cout << "Enter the desired width: ";
	cin >> width;

	cout << "Enter the desired height: ";   
	cin >> height;

	/*cout << "Enter the desired rule: ";
	cin >> rule;*/

	int currentGen[width];
	int nxtGen[width]; //vector for the next line of cells

	for(int i=0; i<width; i++) // fill array with 0's
	{
		currentGen[i] = 0;
	}

	currentGen[width/2] = 1; //put a 1 in middle of array

	for(int j=0; j<width; j++) //print first generation
	{
		cout << currentGen[j];
	}
	cout << endl; // add new line 
	

	
	for(int k=0; k<height; k++) //generate and print next generations until height is reached
	{
		for(int m=0; m<width; m++)
		{
			int lft, rght = 0;
		
			if(m==0) //if at left-end of array
			{
				lft = currentGen[(width-1)]; //get lft from other end of array
			}
			else
			{
				lft = currentGen[(m-1)]; //else get immediate lft
			}
		
			if(m==width-1) //if at right-end of array
			{
				rght = currentGen[0]; //get rght from other end of array
			}
			else
			{
				rght = currentGen[(m+1)]; //else get immediate rght
			}
				
	
			nxtGen[m] = ruleResult(lft, currentGen[m], rght); //get and set the state of next cell


		
			if(m==width-1) //if at the end of the current line
			{
				for(int l=0; l<width; l++) //print the new generation
				{
					cout << nxtGen[l];
				}

				for(int n=0; n<width; n++) //set current generation to be the next 
				{
					currentGen[n] = nxtGen[n];
				}	
				cout << endl; // add new line 
				
				
			}
		}

	}	







}
