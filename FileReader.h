#ifndef FILEREADER_H
#define FILEREADER_H
#include "Flight.h"
using namespace std;

class FileReader {
public:
    void readFromFile(string path);
    vector<Flight> getFlights() const;
    void book(int row, int seat, string flightNumber);
    int unBook(vector<string> info, int row, int seat);
private:
    vector<Flight> flights;
};



#endif //FILEREADER_H
