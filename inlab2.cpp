#include <iostream>
using namespace std;

//create the functions
double averagescore(int* scores, int numscores);
void bubbleSort(int arr[], int n);


int main()
{
    int numscores; //number of scores to intake
    int score; //new score to add

    //take in user input number of scores
    cout << "Please enter the number of test scores: ";
    cin >> numscores;

    //dynamic array for the scores
    int* scores = new int[numscores];

    //loop for each score
    for (int i = 1; i <= numscores; i++) {
        //input validate the score is positive
        do {
            cout << "Enter test score " << i << ": ";
            cin >> score;
            if (score < 0) {
                cout << "Invalid input (negative) ";
            }
        } while (score < 0);
        //add the input score to the array
        scores[i - 1] = score;
    }

    //print the scores ascending order
    cout << endl << "The test scores ascending order:" << endl;
    cout << "================================" << endl;

    //print each score
    for (int i = 0; i < numscores; i++) {
        cout << scores[i] << endl;
    }

    //average the scores in the array
    cout << endl << "The average score is " << averagescore(scores, numscores) << endl << endl;

    //print the scores without the lowest one
    cout << "The test scores (dropping lowest):" << endl;
    cout << "==================================" << endl;

    //sort highest to lowest
    bubbleSort(scores, numscores);

    //loop but stop at the lowest score
    for (int i = 0; i < numscores; i++) {
        cout << scores[i] << endl;
    }

    delete[] scores;

}

//function to return the average of the scores
double averagescore(int* scores, int numscores) {
    //add all scores to sum
    int sum = 0;
    for (int i = 0; i < numscores; i++) {
        sum += scores[i];
    }
    //divide the total into the number of scores
    return (sum / numscores);
}

//function to sort array
//takes in the dynamic array & the number of scores
void bubbleSort(int arr[], int n) {
    //loop through 0-number of scores
    for (int i = 0; i < n - 1; i++) {
        //loop through one less 
        for (int j = 0; j < n - i - 1; j++) {
            //if the last element is greater
            if (arr[j] > arr[j + 1]) {
                //swap the elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

