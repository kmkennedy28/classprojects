#include <iostream>
#include <random>
using namespace std;

//function declarations
int compturn(int objects, int max);
int userturn(int max);

int main()
{
    char turn; //tracks turns
    int objects = 0; //number of objects
    int maxobjects = 0; //maxium objects allowed
    bool uturn = true; //user turn on true, computer turn on false
    int remove = 0; //number of objects to be removed
        
    //input user or computer first
    cout << "Would you like to go first(y for yes and other input for no)? ";
    cin >> turn;

    //set first turn
    if (turn == 'y') {
        uturn = true;
    }
    else {
        uturn = false;
    }

    //input number of objects to start with
    cout << "Enter the initial number of objects. ";
    cin >> objects;
    maxobjects = objects; //set max objects as the total number of objects
    cout << endl;
    
    //loops game until no objects remain
    while (objects > 0) {
        //during the computer turn
        if (uturn == false) { 
            remove = compturn(objects, maxobjects); //remove computer's chosen number of objects
            objects -= remove;
            cout << "It is the computer's turn. The computer removes " << remove << " objects." << endl;
            maxobjects = remove * 2; //update max objects
            if (objects == 0) { //end game if no objects remain
                break;
            }
            cout << "The number of objects remains: " << objects << endl << endl;

            uturn = true; //chance turns
        }
        if (uturn == true) {  //during user's turn
            remove = userturn(maxobjects); //get users number of objects to remove
            objects -= remove; 
            
            maxobjects = remove * 2;
            if (objects == 0) {
                break;
            }
            cout << "The number of objects remains: " << objects << endl << endl;
            uturn = false;
        }
    }

    if (uturn == true) { //if the user wins
        cout << "You win. Congratulations!";
    }
    else if (uturn == false) { //if the computer wins
        cout << "The computer wins.";
    }

}

//function decides the computers turn
int compturn(int objects, int max) {
    if (objects < max) { //if it can remove all the objects, do
        return objects;
    }
    else {
        int remove = -1;
        while (remove < 0 || remove > max) {
            remove = rand() % max;
        }
        return remove; //re randomize numbers until a valid choice
    }

}

//get users choice
int userturn(int max) {
    int remove;
    cout << "It is your turn. ";
    do {
        //get user choice
        cout << "Enter the number of objects to remove (1-" << max << "): ";
        cin >> remove;
        if (remove > max || remove < 0) { //validate choice
            cout << "Invalid move. ";
        }
    } while (remove > max || remove < 0);

    cout << "Move accepted. "; //return valid choice
    return remove;

}

/*
Would you like to go first(y for yes and other input for no)? y
Enter the initial number of objects. 15

It is your turn. Enter the number of objects to remove (1-15): 2
Move accepted. The number of objects remains: 13

It is the computer's turn. The computer removes 1 objects.
The number of objects remains: 12

It is your turn. Enter the number of objects to remove (1-2): 3
Invalid move. Enter the number of objects to remove (1-2): 2
Move accepted. The number of objects remains: 10

It is the computer's turn. The computer removes 3 objects.
The number of objects remains: 7

It is your turn. Enter the number of objects to remove (1-6): 2
Move accepted. The number of objects remains: 5

It is the computer's turn. The computer removes 2 objects.
The number of objects remains: 3

It is your turn. Enter the number of objects to remove (1-4): 3
Move accepted. You win. Congratulations!
*/