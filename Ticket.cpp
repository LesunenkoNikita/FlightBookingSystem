#include "Ticket.h"
using namespace std;
#include <string>

Ticket::Ticket(string date, string flightNumber, string seat, string username, int id): flightDate(date), flightNumber(flightNumber), seat(seat), username(username), ticketId(id){}

string Ticket::getDate() const {
    return flightDate;
}
string Ticket::getFlightNumber() const
{
    return flightNumber;
}
string Ticket::getSeat() const {
    return seat;
}
string Ticket::getUsername() const {
    return username;
}
int Ticket::getId() const {
    return ticketId;
}