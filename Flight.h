#ifndef FLIGHT_H
#define FLIGHT_H
using namespace std;
#include <vector>
#include <string>



class Flight {
public:
    Flight(string number, string date, int rowsAmount, int seatsAmount, vector<int>& prices);
    string getFlightNumber() const;
    string getFlightDate() const;
    int getRowPrice(int row) const;
    vector<vector<char>> getSeats() const;
    void book(int row, int seat);
    void unBook(int row, int seat);
private:
    vector<vector<char>> seats;
    vector<int> rowPrices;
    string flightNumber;
    string flightDate;
};



#endif //FLIGHT_H
