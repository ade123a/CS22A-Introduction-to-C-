/**
  ARRAYS and FUNCTIONS
  Project: Simulate a simplified version of "The Deal or No Deal" TV game
*/

// Davie Truong

#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


void gamerule(void);
void playgame(ofstream &outputFile, int cases[], string name);
void shuffle(int cases[], int size);
int getValidNum(int low, int high);
string getName(void);
void endGame(void);

const int SIZE = 10;
const int LOW = 1;


int main()
{
    srand(time(NULL));

    string name;
    char option;
    int temp;
    ofstream outputFile;

    int cases[SIZE] = {0, 0, 0, 1, 10, 100, 1000, 10000, 100000, 1000000}; // CREATES AN ARRAY OF 10 CASES

    gamerule();

    outputFile.open("players.txt");// OPENS OR CREATES THE OUTPUTFILE


do
    {
        shuffle(cases, SIZE);
        name = getName();//GETS THE USER'S NAME FROM THE FUNCTION AND ASSIGNS IT TO NAME VARIABLE
        playgame(outputFile, cases, name);

        cout << "Does another player want to play? Enter 'Y' for YES or 'N' for NO" << endl;
        cin >> option;

    }while (option == 'Y' || option == 'y');

    outputFile.close();//CLOSES THE OUTPUTFILE
    endGame();

    return 0;
}



void gamerule(void) // THIS FUNCTION TELLS THE USER WHAT THE RULES OF THE GAME ARE
{
    cout << "*****RULES OF THE GAME*****" << endl << endl;
    cout << "There are 10 briefcases with different amounts of money in them." << endl;
    cout << "We have 3 cases that contain no money." << endl << endl;
    cout << "We also have one case with $1, one with $10, one with $100, one - $1,000, one - $10,000, one - 100,000, and finally one with 1 million dollars." << endl << endl;
    cout << "Different amounts are randomly assigned to cases. You are allowed to open up to 3 cases. " << endl << endl;
    cout << "After the case is open - you are shown its content. You will be asked Deal or NoDeal?" << endl << endl;
    cout << "If you choose Deal - you gets to keep the money in the recently opened case and the game is over. " << endl;
    cout << "If you choose No Deal - then you can open another case." << endl << endl;
    cout << "After 3 cases have been opened, you will get the most recent case." << endl;
    cout << "Then the game will be over." << endl << endl;
    cout << "*****RULES OF THE GAME*****" << endl << endl;
}



void shuffle(int cases[], int size) // THIS FUNCTION SUFFLES THE CASES SO THAT IT WOULD BE RANDOM EVERYTIME THE FUNCTION IS USED
{
    int r;
    int temp;

    for (int i = 0; i < size; i ++)
    {
        r = rand() % size;
        temp = cases[i];
        cases[i] = cases[r];
        cases[r] = temp;
    }

}

string getName(void) //GETS THE NAME OF THE PERSON AND OUTPUTS IT TO CONSOL AS WELL AS PLAYERS.TXT
{

    string name;
    cout << "Please enter in your name." << endl;
    cin >> name;

    return name;
}


void playgame(ofstream &outputFile, int cases[], string name)// THIS IS THE MEAT OF THE PROGRAM WHERE IT RUNS THROUGH THE GAME
{

 int choice = 0;
 char decision = 'y';
 int count = 0;


while(count < 3 && decision == 'Y' || count < 3 && decision == 'y')
     {
        cout << "\nEnter a brief case number from 1 to 10" << endl;
        choice = getValidNum( LOW,  SIZE);
        cout << "The case that you have chosen contains $" << cases[choice] << endl;
        cout << "\nWould you like to try for a different case?" << endl;
        cout << "Enter in 'N' for deal" << endl;
        cout << "enter in 'Y' for no deal" << endl;
        cin >> decision;
        count++;
     }

cout << "Congratulations " << name << " you have won $" << cases[choice] << endl;
outputFile << "Congratulations " << name << " you have won $" << cases[choice] << endl;

}

int getValidNum(int low, int high)//so the user can only enter numbers 1 to 10
{
    int n;
    bool success;

    do
    {
        cout << "Please enter a number (" << low << " to " << high << "): ";
        success = cin >> n;
        cin.clear();          // to clear the error flag
        cin.ignore(80, '\n'); // to discard the unwanted input from the input buffer
    }while(!success || n < low || n > high);

    return n -1;
}


void endGame(void)//END PROGRAM MESSAGE
{
    cout << "The game is over." << endl;
}


/**

*****RULES OF THE GAME*****

There are 10 briefcases with different amounts of money in them.
We have 3 cases that contain no money.

We also have one case with $1, one with $10, one with $100, one - $1,000, one -
$10,000, one - 100,000, and finally one with 1 million dollars.

Different amounts are randomly assigned to cases. You are allowed to open up to
3 cases.

After the case is open - you are shown its content. You will be asked Deal or No
Deal?

If you choose Deal - you gets to keep the money in the recently opened case and
the game is over.
If you choose No Deal - then you can open another case.

After 3 cases have been opened, you will get the most recent case.
Then the game will be over.

*****RULES OF THE GAME*****

Please enter in your name.
Davie Truong

Enter a brief case number from 1 to 10
Please enter a number (1 to 10): Please enter a number (1 to 10): 1
The case that you have chosen contains $1

Would you like to try for a different case?
Enter in 'N' for deal
enter in 'Y' for no deal
y

Enter a brief case number from 1 to 10
Please enter a number (1 to 10): 2
The case that you have chosen contains $0

Would you like to try for a different case?
Enter in 'N' for deal
enter in 'Y' for no deal
y

Enter a brief case number from 1 to 10
Please enter a number (1 to 10): 3
The case that you have chosen contains $1000

Would you like to try for a different case?
Enter in 'N' for deal
enter in 'Y' for no deal
y
Congratulations Davie you have won $1000
Does another player want to play? Enter 'Y' for YES or 'N' for NO
n
The game is over.

Process returned 0 (0x0)   execution time : 70.690 s
Press any key to continue.

*/






/**

*****RULES OF THE GAME*****

There are 10 briefcases with different amounts of money in them.
We have 3 cases that contain no money.

We also have one case with $1, one with $10, one with $100, one - $1,000, one -
$10,000, one - 100,000, and finally one with 1 million dollars.

Different amounts are randomly assigned to cases. You are allowed to open up to
3 cases.

After the case is open - you are shown its content. You will be asked Deal or No
Deal?

If you choose Deal - you gets to keep the money in the recently opened case and
the game is over.
If you choose No Deal - then you can open another case.

After 3 cases have been opened, you will get the most recent case.
Then the game will be over.

*****RULES OF THE GAME*****

Please enter in your name.
davie

Enter a brief case number from 1 to 10
Please enter a number (1 to 10): 1
The case that you have chosen contains $1000000

Would you like to try for a different case?
Enter in 'N' for deal
enter in 'Y' for no deal
n
Congratulations davie you have won $1000000
Does another player want to play? Enter 'Y' for YES or 'N' for NO
y
Please enter in your name.

*/
