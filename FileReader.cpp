#include "FileReader.h"
#include <fstream>
#include <iostream>

#include "Flight.h"
#include <sstream>
using namespace std;

vector<Flight> FileReader::getFlights() const
{
    return flights;
}
void FileReader::book(int row, int seat, string flightNumber) {
    for (Flight &flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            flight.book(row, seat);
            break;
        }
    }
}
int FileReader::unBook(vector<string> info, int row, int seat) {
    for (Flight &flight : flights) {
        if (flight.getFlightNumber() == info[0]) {
            flight.unBook(row, seat);
            return flight.getRowPrice(row);
            break;
        }
    }
}


void FileReader::readFromFile(string path) {
    ifstream file(path);
    string line;
    getline(file, line);
    int rowsAmount = stoi(line);
    for (int i = 0; i < rowsAmount; ++i)
    {
        getline(file, line);
        istringstream iss(line);
        string date;
        string flightNumber;
        int seatsPerRow;
        iss >> date >> flightNumber >> seatsPerRow;
        vector<int> prices;
        string strPart;
        int planeRowsAmount;
        for (int i = 0; i < 2; i++)
        {
            iss >> strPart;
            int dashPos = strPart.find('-');
            int startRow = stoi(strPart.substr(0, dashPos));
            int endRow = stoi(strPart.substr(dashPos + 1, strPart.size()-dashPos-1));
            iss >> strPart;
            int dollarPos = strPart.find('$');
            int price = stoi(strPart.substr(0, dollarPos));
            for (int row = startRow; row <= endRow; row++)
            {
                prices.push_back(price);
            }
            if (i == 1) {
                planeRowsAmount = endRow;
            }
        }
        flights.emplace_back(flightNumber, date, planeRowsAmount, seatsPerRow, prices);
    }
}
