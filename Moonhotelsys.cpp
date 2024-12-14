#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Structure to represent a room
struct Room {
    string id;
    string type;
    bool available;
};

// Structure to represent a booking
struct Booking {
    string roomId;
    string guestName;
    unsigned int nights;
};

// Function to display available rooms
void displayAvailableRooms(const vector<Room>& rooms) {
    cout << "Available Rooms:\n";
    for (const auto& room : rooms) {
        if (room.available) {
            cout << "Room ID: " << room.id << " - Type: " << room.type << endl;
        }
    }
}

// Function to book a room
void bookRoom(vector<Room>& rooms, vector<Booking>& bookings) {
    string roomId;
    string guestName;
    unsigned int nights;

    cout << "Enter Room ID to Book: ";
    cin >> roomId;

    for (auto& room : rooms) {
        if (room.id == roomId && room.available) {
            room.available = false;
            cout << "Enter Guest Name: ";
            cin >> guestName;
            cout << "Enter Number of Nights: ";
            cin >> nights;
            bookings.push_back({ roomId, guestName, nights });
            cout << "Room booked successfully for " << guestName << "!\n";
            return;
        }
    }

    cout << "Room not available or does not exist.\n";
}

// Function to display booked rooms
void displayBookedRooms(const vector<Booking>& bookings) {
    cout << "Booked Rooms:\n";
    for (const auto& booking : bookings) {
        cout << "Room ID: " << booking.roomId << " - Guest Name: " << booking.guestName << " - Nights: " << booking.nights << endl;
    }
}

// Function to calculate bill amount
float calculateBill(const vector<Booking>& bookings) {
    float totalBill = 0.0;
    const float ratePerNight = 15000.0; // Example rate per night

    for (const auto& booking : bookings) {
        totalBill += booking.nights * ratePerNight;
    }

    return totalBill;
}

int main() {
    cout << "Welcome to Moon Hotel Management\n\n";

    // Receptionist login
    string username;
    string password;
    cout << "Enter Username: ";
    cin >> username;
    cout << "Enter Password: ";
    cin >> password;

    // Check if username and password are correct
    if (username == "staff" && password == "staff") {
        vector<Room> rooms = {
            {"01", "Single Room", true},
            {"02", "Double Room", true},
            {"03", "Twin Room", true},
            {"04","Deluxe Room",true}
        };

        vector<Booking> bookings;

        int choice;
        do {
            cout << "\nMENU:\n";
            cout << "1. Display Available Rooms\n";
            cout << "2. Book a Room\n";
            cout << "3. Display Booked Rooms\n";
            cout << "4. Display Total Bill\n";
            cout << "5. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1:
                displayAvailableRooms(rooms);
                break;
            case 2:
                bookRoom(rooms, bookings);
                break;
            case 3:
                displayBookedRooms(bookings);
                break;
            case 4:
                cout << "Total Bill: Rs " << calculateBill(bookings) << endl;
                break;
            case 5:
                cout << "Exiting program. Thank you!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 5);
    }
    else {
        cout << "Invalid username or password. Access denied.\n";
    }

    return 0;
}