#ifndef CLI_H
#define CLI_H
#include "FileReader.h"
#include "Booking.h"

class CLI {
public:
    void run();
private:
    FileReader fileReader;
    Booking booking;
    void allCommands();
    void checkFreePlaces();
    void bookTicket();
    void returnTicket();
};



#endif //CLI_H
