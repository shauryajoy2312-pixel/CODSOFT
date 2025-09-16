#include <iostream>
// Take the help of chatGPT to generate random numbers 
#include <cstdlib>  
#include <ctime>     
using namespace std;

int main() {
    
    srand(time(0));

    int secretNumber = rand() % 100 + 1; 
    int guess;
    int attempts = 0;

    cout<<"Welcome to the number guessing game : \n";
    
    do {
        cout << "\nEnter your guess: ";
        cin >> guess;
        attempts++;

        if (guess > secretNumber) {
            cout << "Too high! Try something smaller " << endl;
        } else if (guess < secretNumber) {
            cout << "Too low! Try a bit higher" << endl;
        } else {
            cout << "Congratulations! You guessed it right in " 
                 << attempts << " attempts!" << endl;
        }

    } while (guess != secretNumber);

    return 0;
}