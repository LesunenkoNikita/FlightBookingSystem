#ifndef TICKET_H
#define TICKET_H
using namespace std;
#include <string>


class Ticket {
public:
    Ticket(string date, string flightNumber, string seat, string username, int id);
    string getDate() const;
    string getFlightNumber() const;
    string getSeat() const;
    string getUsername() const;
    int getId() const;
private:
    string flightDate;
    string flightNumber;
    string seat;
    string username;
    int ticketId;
};



#endif //TICKET_H
