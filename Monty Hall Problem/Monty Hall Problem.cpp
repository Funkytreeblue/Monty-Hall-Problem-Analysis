/**
 * Author:      J. Cormier
 *
 * Description: User inputs a number of games
 *              to be played. The winning door,
 *              the player door choice, and the 
 *              door being revealed are chosen 
 *              at random. Program evaluates both
 *              always switching and always staying
 *
 * Output:      Number of games
 *              Wins
 *              Loses
 *              Win rate
 **/

#include <iostream>
#include <ctime>

using namespace std;

int main()
{
    string action = "switch";
    int games;

    // seed rand function with time
    int now = time(0);
    srand(now);

    cout << "The Monty Hall Problem\n";
    cout << "Select number of games to be played: \n";
    cin >> games;

    // loops twice. loop 1 = always switch, loop 2 = always stay;
    for (int k = 0; k < 2; k++)
    {
        int wins = 0;
        int loses = 0;

        for (int j = 0; j < games; j++)
        {
            int doors[3];
            int good_door = rand() % 3;
            int door_choice = rand() % 3;

            // hide prize behind door
            for (int i = 0; i < (sizeof(doors) / sizeof(int)); i++)
            {
                if (i == good_door)
                {
                    doors[i] = 1;
                }
                else
                {
                    doors[i] = 0;
                }
            }

            // revealed door must not be the good door or the door chosen by player
            int revealed_door = rand() % 3;
            while (revealed_door == good_door || revealed_door == door_choice)
            {
                revealed_door = rand() % 3;
            }
            
            // always switch
            if (action == "switch")
            {
                for (int i = 0; i < (sizeof(doors) / sizeof(int)); i++)
                {
                    if (i != door_choice && i != revealed_door)
                    {
                        door_choice = i;
                        break;
                    }
                }

                if (doors[door_choice] == 1)
                {
                    wins += 1;
                }
                else
                {
                    loses += 1;
                }
            }
            // always stay
            else if (action == "stay")
            {
                if (doors[door_choice] == 1)
                {
                    wins += 1;
                }
                else
                {
                    loses += 1;
                }
            }
        }
        
        // calculate win rate
        double win_rate = ((double)wins / (double)games) * 100;

        // display results
        cout << "===========================================\n\n";
        cout << "Action: Always " << action << "\n\n";
        cout << "Games = " << games << "\n";
        cout << "Wins = " << wins << "\n";
        cout << "Loses = " << loses << "\n";
        printf("Win rate = %.1f", win_rate);
        cout << "%\n\n";

        // switch action to stay for second loop
        action = "stay";    
    }

    cout << "===========================================\n";

    // pause program to view results
    cout << "Press enter to close...";
    string x;
    cin.clear();
    cin.ignore();
    x = cin.get();
}
