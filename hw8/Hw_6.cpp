/**
  Project: Star Search
  A particular talent competition has five judges, each of whom awards a score between
  0 and 10 to each performer. Fractional scores, such as 8.3, are allowed.
  A performer’s final score is determined by dropping the highest and the lowest score
  received, then averaging the three remaining scores. Write a program that calculates
  the score of each performer and determines the winner.
  Assume there’s only one winner!

  Input: Read data from an input file named performers.txt.
  Output: Write the number of participants, the name of the winner and winner’s score to
  the screen. Write to a file named results.txt the names of the performers and their
  final score.
*/

//  Davie Truong
// extend until Thursday

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void welcome(void);
bool getScores(ifstream &inputFile, double &score1, double &score2, double &score3, double &score4, double &score5, string &name);
double calcScore(double &score1, double &score2, double &score3, double &score4, double &score5);
double findLowest(double &score1, double &score2, double &score3, double &score4, double &score5);
double findHighest(double &score1, double &score2, double &score3, double &score4, double &score5);
void writeScore(ofstream &outputFile,string &name, double &finalScore);
void farewell(void);

int main()
{
   double score1, score2, score3, score4, score5, finalScore;
   double bestScore = 0;
   double count = 0;
   int decision;
   string name, bestName;
   ifstream inputFile;
   ofstream outputFile;
   // declare the variables needed in main()

   welcome();
    cout << "\nattempting to open performers.txt" << endl;
    inputFile.open("performers.txt");// open the input file + validation
    if (!inputFile)
        {
           cout << "performers.txt could not open" << endl;
           return 25;
        }
    cout << "successfully openned performers.txt" << endl << endl;
    cout << "*****************************" << endl << endl;


    ifstream test;
    bool flag;
    test.open("results.txt");
    if(test)
    {
        flag = true;
    }
    else flag = false;

    if(flag)
    {
        cout << "The file already exist do you want to overwrite it?" << endl;
        cout << "Enter 0 if you Do NOT want to overwrite it" << endl;
        cout << "Enter any other number if you DO want to overwrite it" << endl;

        cin >> decision;

        if (!decision)
        {
             return 0;
        }

    }

    test.close();

    outputFile.open("results.txt");// open the output file + validation

   while (getScores(inputFile, score1, score2, score3, score4, score5, name))
   {

     finalScore = calcScore(score1, score2, score3, score4, score5);
      // determine the winner so far
      if (finalScore > bestScore)
      {
             bestScore = finalScore;
             bestName = name;

      }





      writeScore(outputFile, name, finalScore);
        count++;

   }
   // close the input file
    inputFile.close();
   // close the output file
    outputFile.close();
   // display the number of participants
   cout << "\n\nThe number of participants is: " << count << endl;
   // display the winner and the winner's score
   cout << "The winner is: " << bestName << " " << "with the score of " << bestScore << endl << endl << endl;

   farewell();
   return 0;
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
void welcome(void)
{
    cout << "This is the welcome function" << endl;
    cout << "This program calculates the score of each performer and determines the winner" << endl;
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
bool getScores(ifstream &inputFile, double &score1, double &score2, double &score3, double &score4, double &score5, string &name)
{
    if (inputFile >> name >> score1 >> score2 >> score3 >> score4 >> score5)
        return true;

    return false;
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
double calcScore(double &score1, double &score2, double &score3, double &score4, double &score5)
{
    double highest;
    double lowest;
    lowest = findLowest(score1, score2, score3, score4, score5);
    highest = findHighest(score1, score2, score3, score4, score5);

    double finalScore = ((score1 + score2 + score3 + score4 + score5) - (lowest + highest)) / 3;

    return finalScore;
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
double findLowest(double &score1, double &score2, double &score3, double &score4, double &score5)
{
    double lowest;

    lowest = score1;
    if (score2 < lowest)
        lowest = score2;
    if (score3 < lowest)
        lowest = score3;
    if (score4 < lowest)
        lowest = score4;
    if (score5 < lowest)
        lowest = score5;

        return lowest;

}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
double findHighest(double &score1, double &score2, double &score3, double &score4, double &score5)
{
    double highest;

    highest=score1;
    if (score2 > highest)
        highest = score2;
    if (score3 > highest)
        highest = score3;
    if (score4 > highest)
        highest = score4;
    if (score5 > highest)
        highest = score5;

        return highest;
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
void writeScore(ofstream &outputFile,string &name, double &finalScore)
{
    outputFile << name << "\t" << finalScore << endl;
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
void farewell(void)
{
    cout << "This is the farewell function" << endl;
}
