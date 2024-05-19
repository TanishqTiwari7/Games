

#include <iostream>
#include <ctime>
#include <string>

using namespace std;

int main()
{
  srand(time(NULL));

  // Use meaningful variable names
  int sections = 0;     // Number of sections on the wheel
  double choice;    // User's choice (1 or 2)
  int attempts = 1; // Number of times user entered an incorrect choice
  char playAgain;   // User's choice to play again

  do
  {
    // Welcome message
    cout << "\t\t\t***********************************************\n";
    cout << "\t\t\t******************** Welcome to the Game! ********************\n";
    cout << "\t\t\t****************** Let's play some dares! *******************\n";
    cout << "\t\t\t***********************************************\n\n\n";

    // Get user's choice: add custom dares (1) or use default (2)
    cout << "Enter 1 to add your own crazy dares or 2 to use default dares: ";
    cin >> choice;

    // Validate user input (1 or 2 only)
    while (choice != 1 && choice != 2)
    {
      cout << "Invalid choice. Please enter 1 or 2: ";
      cin >> choice;
      attempts++; // Increase attempt count for incorrect input
    }

    if (choice == 1)
    {
      // Get number of sections for custom dares wheel
      cout << "How many sections do you want on the wheel of dares? ";
      cin >> sections;

      // Clear input buffer (optional, might not be necessary here)
      cin.ignore();

      // Array to store custom dares
      string dares[sections];

      // Get user input for custom dares
      for (int i = 1; i <= sections; i++)
      {
        cout << "Enter dare no. " << i << ": ";
        getline(cin, dares[i - 1]); // Use getline for strings with spaces
      }

      // Generate random index for dare selection
      int randomDare = (rand() % sections);

      // Display randomly selected dare
      cout << "\nThe dare you got: " << dares[randomDare] << endl;
    }
    else
    {
      // Default case: use random number between 1 and sections
      // Generate random number between 1 and 10
      cout << "How many sections do you want on the wheel of dares? ";
      cin >> sections;
      sections = rand() % sections + 1; 
      cout << "Your random number is: " << sections << endl;
    }

    // Ask user to play again
    cout << "\n\nWant to play again? (Y/N): ";
    cin >> playAgain;

    // Clear input buffer (optional, might not be necessary here)
    cin.ignore();

    cout << "\n\n\n";

  } while (playAgain == 'y' || playAgain == 'Y');

  return 0;
}
