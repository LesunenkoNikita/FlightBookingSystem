#include "CLI.h"
#include "Booking.h"
#include "Flight.h"
#include "Ticket.h"
#include "FileReader.h"
#include <iostream>
#include <string>
using namespace std;

void CLI::allCommands() {
    cout << "check - check available seats by flight number" << endl;
    cout << "book - book a ticket for the flight" << endl;
    cout << "return - return ticket with refund" << endl;
}

void CLI::checkFreePlaces() {
    cout << "Please, enter the number of the flight:" << endl;
    string flightNumber;
    cin >> flightNumber;
    vector<Flight> flights;
    flights = fileReader.getFlights();
    for (Flight flight : flights) {
        if (flight.getFlightNumber() == flightNumber) {
            for (int row = 0; row < flight.getSeats().size(); ++row) {
                for (int col = 0; col < flight.getSeats()[row].size(); ++col) {
                    if (flight.getSeats()[row][col] == 'f') {
                        char seatLetter = 'A' + col;
                        std::cout << row + 1 << seatLetter << " " << flight.getRowPrice(row) << "$, ";
                    }
                }
            }
            cout << endl;
            break;
        }
    }
}

void CLI::bookTicket() {
    cout << "Please, enter the date of the flight you want to book a ticket for:" << endl;
    string date;
    cin >> date;
    cout << "Please, enter the number of the flight:" << endl;
    string flightNumber;
    cin >> flightNumber;
    cout << "Please, enter the seat:" << endl;
    string seat;
    cin >> seat;
    cout << "Please, enter your username:" << endl;
    string username;
    cin >> username;
    Ticket ticket = booking.book(date, flightNumber, seat, username);
    int row = stoi(seat.substr(0, seat.size()-1));
    int seatNumber = seat.back() - 'A' + 1;
    fileReader.book(row, seatNumber, ticket.getFlightNumber());
    cout << "Confirmed with ID " << ticket.getId() << endl;
}

void CLI::returnTicket() {
    cout << "Please, enter the ID of a ticket you want to return:" << endl;
    int id;
    cin >> id;
    vector<string> info = booking.returnTicket(id);
    int row = stoi(info[1].substr(0, info[1].size()-1));
    int seatNumber = info[1].back() - 'A' + 1;
    int price = fileReader.unBook(info, row, seatNumber);
    cout << "Confirmed with " << price << "$ refund." << endl;
}

void CLI::run() {
    string path;
    cout << "Please, input a path to a file with flights. If the file is located in the project folder, just write ../filename.txt" << endl;
    cin >> path;
    fileReader.readFromFile(path);
    CLI::allCommands();
    while (1)
    {
        string command;
        cin >> command;
        if (command == "check") {
            checkFreePlaces();
        }
        else if (command == "book") {
            bookTicket();
        }
        else if (command == "return") {
            returnTicket();
        }
    }
}
