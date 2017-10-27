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

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void welcome(void);
bool getScores(ifstream &inputFile, double &score1, double &score2, double &score3, double &score4, double &score5, string &name);
void calcScore(double &score1, double &score2, double &score3, double &score4, double &score5);
void findLowest(double &score1, double &score2, double &score3, double &score4, double &score5);
void findHighest(double &score1, double &score2, double &score3, double &score4, double &score5);
void writeScore(ofstream &outputFile,double &score1, double &score2, double &score3, double &score4, double &score5,  string &name);
void farewell(void);

int main()
{
   double score1, score2, score3, score4, score5;
   string name;
   ifstream inputFile;
   ofstream outputFile;
   // declare the variables needed in main()

   welcome();
    cout << "attempting to open performers.txt" << endl;
    inputFile.open("performers.txt");// open the input file + validation
    if (!inputFile)
        {
           cout << "performers.txt could not open" << endl;
           return 25;
        }
    cout << "successfully openned performers.txt" << endl;
    outputFile.open("results.txt");// open the output file + validation

   while (getScores(inputFile, score1, score2, score3, score4, score5, name))
   {

      calcScore(score1, score2, score3, score4, score5);
      // determine the winner so far
      writeScore(outputFile, score1, score2, score3, score4, score5, name);
   }
   // close the input file
    inputFile.close();
   // close the output file
    outputFile.close();
   // display the number of participants
   // display the winner and the winner's score

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
void calcScore(double &score1, double &score2, double &score3, double &score4, double &score5)
{
    double highest;
    double lowest;
    findLowest(score1, score2, score3, score4, score5);
    findHighest(score1, score2, score3, score4, score5);

    double finalScore = ((score1 + score2 + score3 + score4 + score5) - (lowest + highest)) / 3;
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
void findLowest(double &score1, double &score2, double &score3, double &score4, double &score5)
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

}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
void findHighest(double &score1, double &score2, double &score3, double &score4, double &score5)
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
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
void writeScore(ofstream &outputFile,double &score1, double &score2, double &score3, double &score4, double &score5,  string &name)
{
    double finalScore;
    calcScore(score1, score2, score3, score4, score5);
    outputFile << name << " " << finalScore << endl;
}

// YOU MUST WRITE DOCUMENTATION FOR EACH FUNCTION
void farewell(void)
{
    cout << "This is the farewell function" << endl;
}
