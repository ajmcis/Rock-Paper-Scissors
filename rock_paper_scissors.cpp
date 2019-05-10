/**********************************
* Alex Mack                       *
* 4/5/2019 @ 8:53 AM              *
* C++ Rock Paper Scissors Game    *
***********************************/
#include <iostream>
#include <cstring>   // Needed for strcmp function
#include <cctype>    // Needed for toupper function
#include <ctime>     // Needed for time function
#include <cstdlib>   // Needed for srand and rand functions
using namespace std;

// Global variables
const int NUM_ITEMS = 3;    // Number of items
const int LENGTH = 9;       // Length of characters

void displayItems(char [][LENGTH], int);
char askTieBreaker();

int main()
{
    // Holds items for the game
    char items[NUM_ITEMS][LENGTH] = {"rock", "paper", "scissors"};
    int cpu;  // CPU's item selections
    char p1;   // Player 1's item selections
    char tiebreaker;  // Holds option for yes or no

    cout << "\tRock Paper Scissors\n\n";
    cout << "Player 1 vs CPU\n\n";

    // Random number generator
    srand(time(0));
   
    do
    {
       cout << "\nIt's the CPU's turn\n";

       cpu = rand() % (NUM_ITEMS - 1);
       
       cout << "Your turn Player 1\n\n";
       cout << "\tItem Menu\n";
       cout << "---------------------------------\n";
       cout << "Press the R key to select Rock\n";
       cout << "Press the P key to select Paper\n";
       cout << "Press the S key to select Scissors\n";
       cout << "Press the Q key to quit\n";
       cout << "Select an item: ";
       cin.get(p1);

       // Validate item choices
       while (toupper(p1) != 'R' && toupper(p1) != 'P'
              && toupper(p1) != 'S' && toupper(p1) != 'Q')
       {
             cout << "Please press the R, P, S, or Q keys: ";
             cin >> p1;      
       }

       switch(toupper(p1))
       {
           case 'R':  cout << "\nCPU: ";
                      displayItems(items, cpu);
                      cout << "Player 1: ";
                      displayItems(items, 0);
                      
                      if (strcmp(items[cpu], "paper") == 0)
                          cout << "You Lose!\n";
                      else if (strcmp(items[cpu], "scissors") == 0)
                               cout << "You Won!\n";
                      else
                         tiebreaker = askTieBreaker();
                      break;
           case 'P':  cout << "\nCPU: ";
                      displayItems(items, cpu);
                      cout << "Player 1: ";
                      displayItems(items, 1);

                      if (strcmp(items[cpu], "rock") == 0)
                          cout << "You Won!\n";
                      else if (strcmp(items[cpu], "scissors") == 0)
                               cout << "You Lost!\n";
                      else
                         tiebreaker = askTieBreaker();                        
                      break;
           case 'S':  cout << "\nCPU: ";
                      displayItems(items, cpu);
                      cout << "Player 1: ";
                      displayItems(items, 2);

                      if (strcmp(items[cpu], "paper") == 0)
                          cout << "You Won!\n";
                      else if (strcmp(items[cpu], "rock") == 0)
                               cout << "You Lost!\n";
                      else
                         tiebreaker = askTieBreaker();                        
                      break;

       }

        // Ignore the newline character
        cin.ignore();
    }while (toupper(p1) != 'Q' && toupper(tiebreaker) != 'N');

    cout << "\n" << static_cast<char>(169);
    cout << "Alex Mack 2019\n";
    cout << "Press enter to close the program...";
    cin.get();

    return 0;
}

// Displays the item selected by the player
void displayItems(char itms[][LENGTH], int itemNum)
{
    cout << itms[itemNum] << endl;

}

// Prompts the user to make a decision
// on weather to break a tied game
char askTieBreaker()
{
     char tiebrk;   // Holds option for yes or no

     cout << "You both tied.\n";
     cout << "Do want to break the tie (y/n)? ";
     cin >> tiebrk;

     return tiebrk;

}