#include <iostream>
#include <cstdlib> // for rand() and srand()
#include <ctime>   // for time()

using namespace std;

void game(int &attempt_counter, int &gamelosing_counter,
          int &gamewin_counter, string histogram[],
          int &max_score);

void viewStatistics(int attempt_counter, int gamelosing_counter,
                    int gamewin_counter, string histogram[],
                    int max_score);

void resetStatistics(int &attempt_counter, int &gamelosing_counter,
                     int &gamewin_counter, string histogram[],
                     int &max_score);

int main()
{

    srand(time(0));
    int choice;
    int gamelosing_counter = 0;
    int attempt_counter = 0;
    int gamewin_counter = 0;
    int max_score = 11;
    string histogram[3];

    do
    {
        cout << "=======GUESS GAME=========\n"
             << "1. Play New Game\n"
             << "2. View Statistics\n"
             << "3. Reset Statistics\n"
             << "4. Exit\n\n"
             << "Enter choice: ";
        cin >> choice;
        cin.ignore();
        switch (choice)
        {
        case 1:
        {
            game(attempt_counter, gamelosing_counter,
                 gamewin_counter, histogram,
                 max_score);
            break;
        }
        case 2:
        {
            viewStatistics(attempt_counter, gamelosing_counter,
                           gamewin_counter, histogram,
                           max_score);
            break;
        }
        case 3:
        {
            resetStatistics(attempt_counter, gamelosing_counter,
                            gamewin_counter, histogram,
                            max_score);
            break;
        }
        case 4:
        {
            cout << "congratulations you have exited";
            break;
        }
        }
    } while (choice < 4);
}

// ===========================FUNCTIONS=================================

void game(int &attempt_counter, int &gamelosing_counter,
          int &gamewin_counter, string histogram[], int &max_score)
{
    int num;
    int random_num;
    int guess_attempts = 0;

    random_num = rand() % 100 + 1;

    do
    {
        cout << "Guess the number (1-100): ";
        cin >> num;

        attempt_counter++;
        guess_attempts++;

        if (random_num > num)
            cout << "Too Low!";
        else if (random_num < num)
            cout << "Too High! ";
        else
        {
            cout << "Correct! You guessed it in " << attempt_counter << " attempts!\n";
            gamewin_counter++;

            if (guess_attempts <= 3)
                histogram[0] += "#";
            else if (guess_attempts < 7)

                histogram[1] += "#";
            else
                histogram[2] += "#";

            if (max_score > guess_attempts)
                max_score = guess_attempts;
        }

        if (guess_attempts == 10 && random_num != num)
            gamelosing_counter++;

    } while ((random_num != num) && (guess_attempts != 10));
    cout << "--- Game Over ---\n";
}

// ================= STATS =================

void viewStatistics(int attempt_counter, int gamelosing_counter,
                    int gamewin_counter, string histogram[],
                    int max_score)
{
    int total_games = gamelosing_counter + gamewin_counter;

    cout << "=== STATISTICS ===\n"
         << "Games Played     : " << (total_games) << endl
         << "Win Rate         : " << 100.0 * gamewin_counter / total_games << "%" << endl
         << "Best Score       :" << max_score << " attempts\n\n"
         << "Guess Distribution: \n"
         << "1-3 attempts : " << histogram[0]
         << "\n"
         << "4-6 attempts : " << histogram[1]
         << "\n"
         << "7-10 attempts: " << histogram[2] << "\n";
}

// ================= RESET =================

void resetStatistics(int &attempt_counter, int &gamelosing_counter,
                     int &gamewin_counter, string histogram[],
                     int &max_score)
{

    gamelosing_counter = 0;
    attempt_counter = 0;
    gamewin_counter = 0;
    max_score = 11;
    for (int i = 0; i < 3; i++)
    {
        histogram[i] = "";
    }

    cout << "All statistics have been reset successfully!\n";
}
