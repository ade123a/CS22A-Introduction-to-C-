#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;


void signature(void);
void showgamerules(void);
string getName(void);
int getRandom(void);
int getGuess(void);
int printSorry(void);
int printCongrats(void);
void endgame(void);
void show_end_prgrm_msg(void);
void lowHint(void);
void highHint(void);
int playGame(void);

int main()
{
    string name;
    bool done;
    int r;
    int n;
    int p;
    char playerchange;
    char option;

    signature();
    showgamerules();


    do
    {
        getName();

        do
        {

        playGame();

            cout << "\n\nWould you like to play again?" << endl;
            cout << "Please enter y for yes or anything else for no"<< endl;
            cin >> option;

            }while (option == 'y' || option == 'Y');

        cout << "\n\nWould someone else like to play?" << endl;
        cout << "Please enter y for yes or anything else for no" <<endl;
        cin >> playerchange;

        }while(playerchange == 'y' || playerchange == 'Y');

        endgame();
        show_end_prgrm_msg();

    return 0;
}


void signature(void)
{
    cout << "Davie Truong\n";
    cout << "C++ fall 2014\n";
    cout << "De Anza \n\n\n\n";
}

string getName(void)
{
    string name;
    cout << "\nWhat is your name? \n";
    cin.ignore();
    getline(cin,name);
    cout<< "\n\nTime to guess. Have fun :o " << name << endl << endl;
    return name;
}

int playGame(void)
{
    int r = getRandom();
    cout << r;
    int n;
    int p;
    bool done;
    string name;

        done=false;
        n=5;
        while(n > 0 && done == false)
        {
           p=getGuess();

            if (r == p)
            {
                printCongrats();
                done=true;
            }
            else
            {
                if (n==1)
                {
                    printSorry();
                }
                else
                {
                    if (p < r)
                    {
                        lowHint();
                    }
                    else
                    {
                        highHint();

                    }

                }
            }


            n--;
        }
}

int getRandom(void)
{
    int r;
    srand(time(NULL));
    r=rand()%21+10;

    return r;
}
void lowHint(void)
{
    cout << "\nyour guess is LOW try again" << endl;
}

void highHint(void)
{
    cout << "\nyour guess is HIGH try again" << endl;

}

int printSorry(void)
{
    int r = getRandom();
    cout << "\nSORRY THE RANDOM NUMBER WAS " << r << endl;
}

int getGuess(void)
{
    int p;
    cout << "\nWhat is your guess? \n";
    cin >> p;
    return p;
}

int printCongrats(void)
{
    string name;
    cout << "Congratulations " << name << " This was too easy.  \n";
}

void showgamerules(void)
{
    cout << "RULES OF THE GAME\n";
    cout << "You will have 5 chances to guess a random number between 10 and 30 \n\n";
}

void endgame(void)
{
    cout << "\nGame over\n";
}

void show_end_prgrm_msg(void)
{
    cout << "\nThis is the END OF THE PROGRAM!\n";
}

