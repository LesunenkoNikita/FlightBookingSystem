#include "Booking.h"
#include "Flight.h"
using namespace std;
#include <vector>
#include <string>
#include "Ticket.h"

Ticket Booking::book(string date, string flightNumber, string seat, string username) {
    tickets.emplace_back(date, flightNumber, seat, username, idNumber);
    idNumber++;
    return tickets.back();
}

vector<string> Booking::returnTicket(int ticketID) {
    vector<string> info;
    int idx = 0;
    for (Ticket ticket : tickets) {
        if (ticket.getId() == ticketID) {
            info.push_back(ticket.getFlightNumber());
            info.push_back(ticket.getSeat());
            tickets.erase(tickets.begin() + idx);
        }
        break;
        idx++;
    }
    return info;
}

vector<Ticket> Booking::getTickets() {
    return tickets;
}
