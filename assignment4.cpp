#include <iostream>
#include <iomanip>

using namespace std;

/*
 * Airplane Reservation System
 * Seat Layout (12 rows x 7 cols):
 *   Rows 0-1  : First Class    (14 seats)
 *   Rows 2-3  : Business Class (14 seats)
 *   Rows 4-11 : Economy Class  (56 seats)
 *
 * Seat Values:
 *   0 = Available
 *   1 = Booked
 */

// ---- Function decelerations ----
bool bookFirstClass(int Seats[][7], int rows, int cols, int noOfSeats, int choice);
bool bookBusinessClass(int Seats[][7], int rows, int cols, int noOfSeats, int choice);
bool bookEconomyClass(int Seats[][7], int rows, int cols, int noOfSeats, int choice);
int checkAvailableSeats(int Seats[][7], int rows, int cols, int choice);
void getFare();
void viewSeatingPlan(int Seats[][7], int rows, int cols);
bool systemReset(int Seats[][7], int rows, int cols);

// --------------------------------------------------------------------------------------------//

int main()
{
    // Initialize all seats to 0
    int Seats[12][7] = {0};

    int choice, rows = 12, cols = 7, noOfSeats;

    do
    {
        cout << setfill('-') << setw(40) << "\n"
             << "Welcome to Airplane Reservation System\n"
             << setfill('-') << setw(40) << "\n"
             << "1. Book First Class Seats\n"
             << "2. Book Business Class Seats\n"
             << "3. Book Economy Class Seats\n"
             << "4. View Airplane Seating Plan\n"
             << "5. View Fare(s)\n"
             << "6. System Reset\n"
             << "7. Exit from The Booking System\n\n"
             << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "Enter number of seats you want: ";
            cin >> noOfSeats;
            // Print user-friendly message instead of raw bool (0 or 1)
            if (bookFirstClass(Seats, rows, cols, noOfSeats, choice))
                cout << noOfSeats << " First Class seat(s) successfully booked!\n";
            else
                cout << "Booking failed. Not enough seats available.\n";
            break;

        case 2:
            cout << "Enter number of seats you want: ";
            cin >> noOfSeats;
            if (bookBusinessClass(Seats, rows, cols, noOfSeats, choice))
                cout << noOfSeats << " Business Class seat(s) successfully booked!\n";
            else
                cout << "Booking failed. Not enough seats available.\n";
            break;

        case 3:
            cout << "Enter number of seats you want: ";
            cin >> noOfSeats;
            if (bookEconomyClass(Seats, rows, cols, noOfSeats, choice))
                cout << noOfSeats << " Economy Class seat(s) successfully booked!\n";
            else
                cout << "Booking failed. Not enough seats available.\n";
            break;

        case 4:
            cout << "Displaying Seating Plan...\n";
            viewSeatingPlan(Seats, rows, cols);
            break;

        case 5:
            cout << "Showing Fare Details...\n";
            getFare();
            break;

        case 6:
            cout << "System Resetting...\n";
            systemReset(Seats, rows, cols);
            cout << "System Reset Complete. All seats are now available.\n";
            break;

        case 7:
            cout << "Exiting System. Goodbye!\n";
            break;

        default:
            cout << "Invalid choice! Please enter a number between 1 and 7.\n";
        }

        cout << endl;

    } while (choice != 7);

    return 0;
}

// --------------------------------------------------------------------------------------------//

bool bookFirstClass(int Seats[][7], int rows, int cols, int noOfSeats, int choice)
{
    /* Books seats in First Class (rows 0-1, 14 seats total)
     * Returns true if booking is successful, false otherwise */

    // Check how many seats are currently available in first class
    int availableSeats = checkAvailableSeats(Seats, rows, cols, choice);

    // If no seats available OR requested seats exceed available seats, abort
    if (availableSeats == 0 || noOfSeats > availableSeats)
    {
        cout << "Requested seats :" << noOfSeats << " exceed available seats :"
             << availableSeats << " in First Class.\n";
        return false;
    }

    int seatsBooked = 0; // Tracks how many seats have been booked this session

    // Iterate only over First Class rows (0 to 1)
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            // Book seat only if it is available (0) and we still need more seats
            if (Seats[i][j] == 0 && seatsBooked < noOfSeats)
            {
                Seats[i][j] = 1; // Mark seat as booked
                seatsBooked++;
            }
        }
    }

    // Return true only if all requested seats were successfully booked
    return seatsBooked == noOfSeats;
}

// --------------------------------------------------------------------------------------------//

bool bookBusinessClass(int Seats[][7], int rows, int cols, int noOfSeats, int choice)
{
    /* Books seats in Business Class (rows 2-3, 14 seats total)
     * Returns true if booking is successful, false otherwise */

    int availableSeats = checkAvailableSeats(Seats, rows, cols, choice);

    // If no seats available OR requested seats exceed available seats, abort
    if (availableSeats == 0 || noOfSeats > availableSeats)
    {
        cout << "Requested seats (" << noOfSeats << ") exceed available seats ("
             << availableSeats << ") in Business Class.\n";
        return false;
    }

    int seatsBooked = 0;

    // Iterate only over Business Class rows (2 to 3)
    for (int i = 2; i < 4; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (Seats[i][j] == 0 && seatsBooked < noOfSeats)
            {
                Seats[i][j] = 1;
                seatsBooked++;
            }
        }
    }

    return seatsBooked == noOfSeats;
}

// --------------------------------------------------------------------------------------------//

bool bookEconomyClass(int Seats[][7], int rows, int cols, int noOfSeats, int choice)
{
    /* Books seats in Economy Class (rows 4-11, 56 seats total)
     * Returns true if booking is successful, false otherwise */

    int availableSeats = checkAvailableSeats(Seats, rows, cols, choice);

    // If no seats available OR requested seats exceed available seats, abort
    if (availableSeats == 0 || noOfSeats > availableSeats)
    {
        cout << "Requested seats (" << noOfSeats << ") exceed available seats ("
             << availableSeats << ") in Economy Class.\n";
        return false;
    }

    int seatsBooked = 0;

    // Iterate only over Economy Class rows (4 to 11)
    for (int i = 4; i < 12; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (Seats[i][j] == 0 && seatsBooked < noOfSeats)
            {
                Seats[i][j] = 1;
                seatsBooked++;
            }
        }
    }

    return seatsBooked == noOfSeats;
}

// --------------------------------------------------------------------------------------------//

int checkAvailableSeats(int Seats[][7], int rows, int cols, int choice)
{
    /* Counts and returns the number of available seats in the selected class.
     * Returns 0 if the class is fully booked.
     * Used by booking functions to validate requests before booking. */

    int seatsPreBooked = 0; // Counts already booked seats (value == 1)

    switch (choice)
    {
    case 1: // First Class: rows 0-1 (max 14 seats)
    {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < cols; j++)
                if (Seats[i][j] == 1)
                    seatsPreBooked++;

        if (seatsPreBooked >= 14)
        {
            cout << "All First Class seats are booked.\n";
            return 0;
        }
        return (14 - seatsPreBooked); // Return remaining available seats
    }

    case 2: // Business Class: rows 2-3 (max 14 seats)
    {
        for (int i = 2; i < 4; i++)
            for (int j = 0; j < cols; j++)
                if (Seats[i][j] == 1)
                    seatsPreBooked++;

        if (seatsPreBooked >= 14)
        {
            cout << "All Business Class seats are booked.\n";
            return 0;
        }
        return (14 - seatsPreBooked);
    }

    case 3: // Economy Class: rows 4-11 (max 56 seats)
    {
        for (int i = 4; i < 12; i++)
            for (int j = 0; j < cols; j++)
                if (Seats[i][j] == 1)
                    seatsPreBooked++;

        if (seatsPreBooked >= 56)
        {
            cout << "All Economy Class seats are booked.\n";
            return 0;
        }
        return (56 - seatsPreBooked);
    }
    default:
        cout << "Invalid class choice in checkAvailableSeats.\n";
        return 0;
    }
}

// --------------------------------------------------------------------------------------------//

void getFare()
{
    /* Displays the fare for each class */
    cout << "First Class fare   : Rs. 18,000\n"
         << "Business Class fare: Rs. 14,000\n"
         << "Economy Class fare : Rs. 10,000\n";
}

// --------------------------------------------------------------------------------------------//

void viewSeatingPlan(int Seats[][7], int rows, int cols)
{
    /* Displays the full 12x7 seating matrix.
     * 0 = Available seat
     * 1 = Booked seat
     * Rows 0-1  : First Class
     * Rows 2-3  : Business Class
     * Rows 4-11 : Economy Class */

    cout << "\n--- Seating Plan (0=Available, 1=Booked) ---\n";
    cout << "       Col: 1 2 3 4 5 6 7\n";

    for (int i = 0; i < rows; i++)
    {
        // Label each row with its class for clarity used AI for this printing saved time
        if (i == 0)
            cout << "[ First Class  ] ";
        if (i == 1)
            cout << "                 ";
        if (i == 2)
            cout << "[Business Class] ";
        if (i == 3)
            cout << "                 ";
        if (i >= 4)
            cout << "[Economy Class ] ";

        cout << "Row " << setw(2) << i + 1 << ": ";
        for (int j = 0; j < cols; j++)
            cout << Seats[i][j] << " ";
        cout << "\n";
    }
    cout << "--------------------------------------------\n";
}

// --------------------------------------------------------------------------------------------//

bool systemReset(int Seats[][7], int rows, int cols)
{
    /* Resets all seats to 0 (available).
     * Returns true when reset is complete. */

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            Seats[i][j] = 0; // Mark every seat as available

    return true;
}