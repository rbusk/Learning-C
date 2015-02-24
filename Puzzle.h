/* Puzzle 
 * Ryan Busk
 *
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;


template <typename T>
class Puzzle
{
	public:
		Puzzle(string);
		void userInput(int row, int column);
		void play();
		void displayBoard();
		int checkInput(int row, int column);
	private:
		vector<vector <T> > puzzle;
};

template<typename T>

Puzzle<T>::Puzzle(string fileName)
{
	T value;
	ifstream infile;
	infile.open(fileName.c_str());
	int k = 2;
	cout << k;

	for ( int i = 0; i < 9; i++)
	{
		for ( int j = 0; j < 9; j++)
		{
			infile >> value;
			puzzle[i][j] = value;
		}
	}
}

template< typename T>
void Puzzle<T>::displayBoard()
{
	for ( int i = 0; i < 9; i++)
	{
		for ( int j = 0; j < 9; j++)
		{
			cout << puzzle[i][j];
		}
		cout << endl;
	}
}


