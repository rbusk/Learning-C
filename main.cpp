/* Main program for part one puzzle
 * Ryan Busk
*/

#include "Puzzle.h"
#include <iostream>
using namespace std;

int main()
{
	int k = 2;

	cout << k;
	Puzzle<int> numberPuzzle("board");


	numberPuzzle.displayBoard();

}
