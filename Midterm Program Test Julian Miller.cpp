// Pick a number game.  
// Computer tells you higher or lower depending on guess.
// Goal of game is to select the correct number before guesses runs out.
//

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    int guesses, userNumber, randNumber;
    const int MIN_NUMBER = 7, MAX_NUMBER = 93;
    unsigned seed;

    // Get user input
    cout << "How many guesses would you like: ";
    cin >> guesses;

    cout << "Pick a number between 1 and 100: ";
    cin >> userNumber;

    // Set the seed to current time to allow for random generation.
    seed = time(0);
    srand(seed);

    randNumber = rand() % (MAX_NUMBER - MIN_NUMBER + 1) + MIN_NUMBER;
    
    // start the do-while program loop.
    do
    {
        do
        {
            // Check if user is higher, lower, or guesses correctly
            if (userNumber > randNumber)
            {
                cout << "lower\n";
                guesses--;
                cout << "Enter new number: ";
                cin >> userNumber;
            }
            else if (userNumber < randNumber)
            {
                cout << "higher\n";
                guesses--;
                cout << "Enter new number: ";
                cin >> userNumber;
            }
            else if (userNumber == randNumber)
            {
                cout << "You got it!! The answer was " << randNumber << endl;
                guesses = 0;
            }

        } while (guesses > 1);      // while user still has guesses left.

        // Give user a MAJOR hint.
        if (guesses == 1)
        {
            cout << "This is your last chance! I wont tell you the answer is " << randNumber << endl;
            cout << "Enter your last number: ";
            cin >> userNumber;
            if (userNumber != randNumber)
            {
                cout << "I seriously cannot believe you blew it!" << endl;
                guesses = 0;        // End program in disgust!!
            }
        }

    } while (guesses !=0);

    return 0;
}

