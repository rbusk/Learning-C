/* Main program for part one puzzle
 * Ryan Busk
*/

#include "Puzzle.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	string fileName = "board"; // set name from file
	string fileName2 = "charboard"; // set name from file
	Puzzle<char> letterPuzzle(fileName2); // instantiate class
	letterPuzzle.displayBoard(); // display wordoku
	Puzzle<int> numberPuzzle(fileName); // instantiate class
	numberPuzzle.playGame(); // play sudoku


}
