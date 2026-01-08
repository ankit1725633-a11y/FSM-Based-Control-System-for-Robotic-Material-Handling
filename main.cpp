#include <iostream>
#include <string>

using namespace std;

// Using an enum class for better type safety in C++
enum class State {
    IDLE,
    SCANNING,
    SORTING,
    EMERGENCY
};

class SorterRobot {
private:
    State currentState;

public:
    SorterRobot() : currentState(State::IDLE) {}

    void handleInput() {
        int input;
        
        switch (currentState) {
            case State::IDLE:
                cout << "\n[STATE: IDLE] Robot waiting... Enter 1 to detect package: ";
                cin >> input;
                if (input == 1) currentState = State::SCANNING;
                break;

            case State::SCANNING:
                cout << "[STATE: SCANNING] Reading package... Enter 2 (Success) or 3 (Emergency): ";
                cin >> input;
                if (input == 2) currentState = State::SORTING;
                else if (input == 3) currentState = State::EMERGENCY;
                break;

            case State::SORTING:
                cout << "[STATE: SORTING] Moving robotic arm. Package sorted! Returning to IDLE." << endl;
                currentState = State::IDLE;
                break;

            case State::EMERGENCY:
                cout << "[STATE: EMERGENCY] Obstacle detected! System Halted. Enter 1 to Reset: ";
                cin >> input;
                if (input == 1) {
                    cout << "Reseting systems..." << endl;
                    currentState = State::IDLE;
                }
                break;
        }
    }

    bool isRunning(int lastInput) {
        return lastInput != 0;
    }
};

int main() {
    SorterRobot addverbBot;
    int control = -1;

    cout << "--- Addverb Smart Sorter (C++ OOP Version) ---" << endl;
    cout << "Controls: 1=Next, 2=Confirm, 3=Error, 0=Shutdown" << endl;

    while (control != 0) {
        addverbBot.handleInput();
        // Simple check to allow exiting
        if (cin.fail()) break; 
    }

    cout << "Robot shutting down safely..." << endl;
    return 0;
}