#include "Flight.h"

Flight::Flight(string number, string date, int rowsAmount, int seatsAmount, vector<int> &prices): rowPrices(prices), flightNumber(number), flightDate(date)
{
    seats = vector<vector<char>>(rowsAmount, vector<char>(seatsAmount, 'f'));
    rowPrices = prices;
}

string Flight::getFlightNumber() const {
    return flightNumber;
}
string Flight::getFlightDate() const {
    return flightDate;
}
int Flight::getRowPrice(int row) const {
    return rowPrices[row];
}
vector<vector<char>> Flight::getSeats() const {
    return seats;
}
void Flight::book(int row, int seat) {
    seats[row-1][seat-1] = 'b';
}
void Flight::unBook(int row, int seat) {
    seats[row-1][seat-1] = 'f';
}
