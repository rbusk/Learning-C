/* Puzzle 
 * Ryan Busk
 *
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


template <typename T> // templated class
class Puzzle
{
	public:
		Puzzle(string); // construstor
		void userInput(); // user input function
		void setInput(int row, int column, T number); // set input to board
		void playGame(); // run the game
		void displayBoard(); // display board in command line
		int checkInput(int row, int column, T number); // check if user input is valid
		int checkRow(int row, T number); // check input against row
		int checkColumn(int column, T number); // check input against column
		int checkBox(int row, int column, T number); // check input against box
		int checkZero(); // check board for any zeros
	private:
		vector<vector <T> > puzzle; // vector of vectors
};

template<typename T> 
Puzzle<T>::Puzzle(string fileName)
{
	T value; // template input
	vector<T> tempVec; // temp vec
	ifstream infile; // file input
	infile.open(fileName.c_str()); // read from file

	while (!infile.eof()) // wait til end of file
	{
		for ( int j = 0; j < 9; j++)
		{
			infile >> 	value; // scan in value
			tempVec.push_back(value); // set value in vector
		}
		puzzle.push_back(tempVec); // push value into another vector
		tempVec.clear(); // clear temp vector
	}
}

template<typename T>
void Puzzle<T>::displayBoard()
{
	cout << "-------------" << endl; // box off board
	for ( int i = 0; i < 9; i++)
	{
		cout << "|"; // box off board
		for ( int j = 0; j < 9; j++)
		{
			cout << puzzle[i][j]; // display input
			if((j +1) % 3 == 0) 
				cout << "|"; // box every three numbers
		}

		if((i +1) % 3 == 0) // box every three lines
		{
			cout << endl;
			cout << "-------------";
		}
		cout << endl;
	}

	cout << endl;
}

template<typename T>
void Puzzle<T>::playGame() // play game method
{
	displayBoard(); // display board
	while(!checkZero()) //cehck if board is full
	{
		userInput(); // ask for user input
		displayBoard(); // display board
	}
}

template<typename T>
void Puzzle<T>::userInput()
{
	T input; // template input
	int row, column; 

	cout << "What column would you like to add to? " << endl;
	cin >> column; // input column choice

	cout << "What row would you like to add to? " << endl;
	cin >> row; // input row choice

	cout << "What would you like to input? " << endl;
	cin >> input; //  input inout choice

	if(checkInput(row, column, input))
	{
		setInput(row, column, input); //set input if it is valid
	}
}

template<typename T>
int Puzzle<T>::checkInput(int row, int column, T input)
{
	int i = 0;

	i += checkRow(row, input); // check row if valid input
	i += checkColumn(column, input); // check column for valid input
	i += checkBox(row, column, input); // check box for valid input

	if (i == 3) // if increment i is 3, input is valid
		return 1;
	else
		return 0;
}

template<typename T>
int Puzzle<T>::checkRow(int row, T input) // check row
{
	for (int i = 0; i < 9; i++) // cycle through row
	{
		if(puzzle[row][i] == input)
		{
			cout << "Does not work in that row" << endl;
			return 0; // if input matches another spot, input is not valid, return 0
		}
	}
	return 1;
}

template<typename T>
int Puzzle<T>::checkColumn(int column, T input)
{
	for (int i = 0; i < 9; i++) // iterate through the column
	{
		if(puzzle[i][column] == input) 
		{
			cout << "Does not work in that column" <<  endl;
			return 0; // if input is already there, return 0
		}
	}
	return 1;
}

template<typename T>
int Puzzle<T>::checkZero() // cehck board for any zeros
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if(puzzle[i][j] == 0)
			{
				return 0; // if board has zeros on it, the game is not over, return 0
			}
		}
	}
	cout << "You win" << endl;
	return 1; // return one
}

template<typename T>
void Puzzle<T>::setInput(int row, int column, T input) // set user input
{
	puzzle[row][column] = input; // set user input to board
}

template<typename T>
int Puzzle<T>::checkBox(int row, int column, T input)
{
	int x,y;

	// set starter row and column to top left of box that user is inputting into

	if(row < 3)
	{
		x = 0;
	}
	else if(row > 2 && row < 6)
	{
		x = 3;
	}
	else
	{
		x = 6;
	}
	
	if(column < 3)
	{
		y = 0;
	}
	else if(column > 2 && column < 6)
	{
		y = 3;
	}
	else
	{
		y = 6;
	}


	for(int i = x; i < x+3; i++)
	{
		for(int j = y; j < y+3; j++)
		{
			if(input == puzzle[x][y])
			{
				return 0; // if any in box match input, return 0
			}
		}
	}
	return 1;
}






