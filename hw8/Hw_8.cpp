/**
  ARRAYS and FUNCTIONS: SORTING and SEARCHING
  Project: Midterm Scores – Sort, Search, Average
*/

// Davie Truong

#include <iostream>
#include <fstream>

using namespace std;

const int SIZE = 50;

int  searchList(int array[], int size, int target);
void selectionSort(int idList[], int size);
void read(int idList, double avgList, int &noStu);
double calcClassAvg(double avgList[], int noStu);
void write(int idList, double avgList, int noStu);


int main()
{
    int noStu = 0;
    int idList[50];
    int size = 10;
    double avgList[50];
    read(idList, avgList, noStu);
    double classAvg = calcClassAvg(avgList, noStu);

    /*
    int list[100] = {50, 30, 80, 10, 30, 40, 90, 30, 80, 30};
    int size = 10;
    int location;
    //int target = 80;
    int target = 88;

    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    location = searchList(list, size, target);
    if (location != -1)
        cout << target << " FOUND at location: " << location << endl;
    else
        cout << target << " NOT found!" << endl;

    selectionSort(list, size);
    for (int i = 0; i < size; i++)
    {
        cout << list[i] << " ";
    }
    cout << endl;

    return 0;
    */
}

void read(int idList[], double avgList[], int &noStu) //THIS FUNCTION READS THE SCORES FROM THE FILE AND CALCULATES THE CLASS AVG AS WELL AS THE STUDENT AVG
{
    ifstream inputFile;
    int id = 5;
    double score1 = 0, score2 = 0;
    inputFile.open("midterm_scores.txt");


    while (inputFile >> id >> score1 >> score2 && noStu < SIZE)// reads the file and assigns the numbers to a variable
    {

        idList[noStu] = id; // puts the contents of the variable into the array
        avgList[noStu]= (score1 + score2) / 2.0; // calculates the student average
        noStu++;
    }
}

double calcClassAvg(double avgList[], int noStu) // calculates the class avg
{
    int temp = 0;
    double classAvg;
    for(int i=0; i < noStu; i++)
        {
            temp += avgList[];
        }
    classAvg = temp / noStu;
    return classAvg;
}

// WRITE DOCUMENTATION
int searchList(int array[], int size, int target)
{
    int index = 0;   // Used as a subscript to search array
    int pos   = -1;  // To record position of search value: -1 means not found

    while (index < size && pos == -1)
    {
        if (array[index] == target) // If the value is found
        {
            pos = index; // Record the value's subscript
        }
        index++; // Go to the next element
    }
    return pos; // Return the position, or -1
}

// WRITE DOCUMENTATION
void selectionSort(int array[], int parallelArray[], int size)
{

    for (int startScan = 0; startScan < size - 1; startScan++)
    {
        // look for smallest
        int maxIndex = startScan;
        for(int index = startScan + 1; index < size; index++)
        {
            if (array[index] > array[maxIndex])
                maxIndex = index;
        }
        // swap score
        int hold = array[maxIndex];
        array[maxIndex] = array[startScan];
        array[startScan] = hold;
        // swap id
        int hold2 = parallelArray[maxIndex];
        parallelArray[maxIndex] = parallelArray[startScan];
        parallelArray[startScan] = hold2;
    }
    return;
}

void write(int idList, double avgList, int noStu)
{
    ofstream outputFile
    outputFile.open("sorted.txt");

}
