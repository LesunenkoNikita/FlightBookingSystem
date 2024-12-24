cmake_minimum_required(VERSION 3.30)
project(FlightBookingSystem)

set(CMAKE_CXX_STANDARD 20)

add_executable(FlightBookingSystem main.cpp
        Flight.cpp
        Flight.h
        Ticket.cpp
        Ticket.h
        Booking.cpp
        Booking.h
        FileReader.cpp
        FileReader.h
        CLI.cpp
        CLI.h)
