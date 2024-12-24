#ifndef BOOKING_H
#define BOOKING_H
using namespace std;
#include <vector>
#include <string>
#include "Ticket.h"


class Booking {
public:
    Ticket book(string date, string flightNumber, string seat, string username);
    vector<Ticket> getTickets();
    vector<string> returnTicket(int ticketID);
private:
    vector<Ticket> tickets;
    int idNumber = 0;
};



#endif //BOOKING_H
