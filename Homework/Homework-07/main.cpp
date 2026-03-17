#include <iostream>
#include <bitset>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <string>

class MotorStatus {
private:
    uint8_t motorState; // Each bit represents the status of a motor (on/off)
    uint8_t overheatingMotors = 0; // Motors that are overheating
    int turnCount;

    // Function to randomly initialize motors (on/off) and overheat one motor
    void initialize() {
        std::srand(time(0));
        do {
            motorState = static_cast<uint8_t>(std::rand() % 256);
        } while (motorState == 0); // Ensure at least one motor is ON
        turnCount = 0;
        updateOverheating();
        displayStatus();
    }

    // Incrementally overheat motors with each turn, ensuring the motor is ON and not already overheating
    void updateOverheating() {
        if ((motorState & static_cast<uint8_t>(~overheatingMotors)) == 0) {
            // All ON motors are already overheating (or no motors ON).
            turnCount++;
            return;
        } else {
            int newMotor = 0;
            do {
                newMotor = std::rand() % 8; // Pick a random motor 0-7
            } while (((static_cast<uint8_t>(1u << newMotor) & motorState) == 0) ||
                     ((static_cast<uint8_t>(1u << newMotor) & overheatingMotors) != 0));

            overheatingMotors |= static_cast<uint8_t>(1u << newMotor);
            turnCount++;
        }
    }

    void displayStatus() {
        // Optional hidden version for easier gameplay debugging:
        // std::cout << "Motor State (ON/OFF): " << std::bitset<8>(motorState) << std::endl;
        // std::cout << "Overheating Motors: " << std::bitset<8>(overheatingMotors) << std::endl;

        std::cout << "\n--- Motor Status ---\n";
        std::cout << "There are overheating motors.\n";
        std::cout << "Turn Count: " << turnCount << std::endl;
    }

public:
    MotorStatus() {
        initialize();
    }

    // =====================================
    // =====YOU MAY EDIT THIS FUNCTION======
    // =====================================
    bool turnOff(uint8_t guess) {
        // Correct only if guess exactly matches overheating motors
        bool correct = (guess == overheatingMotors);

        // Turn off only guessed motors that are actually overheating
        uint8_t toTurnOff = static_cast<uint8_t>(guess & overheatingMotors);
        motorState = static_cast<uint8_t>(motorState & ~toTurnOff);
        overheatingMotors = static_cast<uint8_t>(overheatingMotors & ~toTurnOff);

        if (correct) {
            std::cout << "Correct! You shut down the overheating motor(s).\n";
            displayStatus();
            return true;
        } else {
            std::cout << "Wrong guess! Another motor is now overheating.\n";
            updateOverheating();
            displayStatus();
            return false;
        }
    }

    // Helper functions for main()
    void showStatus() {
        displayStatus();
    }

    uint8_t getMotorState() const {
        return motorState;
    }

    int getTurnCount() const {
        return turnCount;
    }
};

int checkInput(const std::string& s) {
    int value = 0;
    bool ok = true;

    // Parse binary
    if (s.size() == 8 && s.find_first_not_of("01") == std::string::npos) {
        for (char c : s) {
            value = (value << 1) | (c - '0');
        }
        return value;
    }
    // Parse hex (0x..)
    else if (s.size() >= 3 && (s.rfind("0x", 0) == 0 || s.rfind("0X", 0) == 0)) {
        try {
            value = std::stoul(s, nullptr, 16);
            if (value > 255) {
                ok = false;
            }
        } catch (...) {
            ok = false;
        }
        if (ok) {
            return value;
        }
    }

    std::cout << "Invalid input. Use 8-bit binary (00101000) or hex (0x28).\n\n";
    return -1;
}

int main() {
    MotorStatus motorStatus;
    uint8_t guess = 0;
    bool won = false;

    std::cout << "Welcome to Motor Meltdown.\n";
    std::cout << "A new game to make you question your life choices.\n\n";

    std::cout << "Commands:\n";
    std::cout << "  status              - check game status\n";
    std::cout << "  set <value>         - set current guess\n";
    std::cout << "  or <value>          - guess |= value\n";
    std::cout << "  and <value>         - guess &= value\n";
    std::cout << "  xor <value>         - guess ^= value\n";
    std::cout << "  not                 - guess = ~guess\n";
    std::cout << "  clear               - guess = 0\n";
    std::cout << "  show                - display current guess\n";
    std::cout << "  submit              - submit current guess\n";
    std::cout << "  q                   - quit\n\n";

    std::cout << "Values may be:\n";
    std::cout << "  8-bit binary like 00101000\n";
    std::cout << "  hex like 0x28\n\n";

    while (!won) {
        std::cout << "\nCurrent guess: " << std::bitset<8>(guess) << "\n";
        std::cout << "> ";

        std::string cmd;
        std::cin >> cmd;
        if (!std::cin) break;

        if (cmd == "q" || cmd == "Q") {
            break;
        } 
        else if (cmd == "status") {
            motorStatus.showStatus();
        } 
        else if (cmd == "show") {
            std::cout << "Current guess: " << std::bitset<8>(guess) << "\n";
        } 
        else if (cmd == "clear") {
            guess = 0;
            std::cout << "Guess cleared: " << std::bitset<8>(guess) << "\n";
        } 
        else if (cmd == "not") {
            guess = static_cast<uint8_t>(~guess);
            std::cout << "Guess updated: " << std::bitset<8>(guess) << "\n";
        } 
        else if (cmd == "submit") {
            won = motorStatus.turnOff(guess);
            if (won) {
                std::cout << "\nYou survived Motor Meltdown.\n";
            }
        } 
        else if (cmd == "set" || cmd == "or" || cmd == "and" || cmd == "xor") {
            std::string valueStr;
            std::cin >> valueStr;
            int value = checkInput(valueStr);

            if (value == -1) {
                continue;
            }

            uint8_t val = static_cast<uint8_t>(value);

            if (cmd == "set") {
                guess = val;
            } else if (cmd == "or") {
                guess = static_cast<uint8_t>(guess | val);
            } else if (cmd == "and") {
                guess = static_cast<uint8_t>(guess & val);
            } else if (cmd == "xor") {
                guess = static_cast<uint8_t>(guess ^ val);
            }

            std::cout << "Guess updated: " << std::bitset<8>(guess) << "\n";
        } 
        else {
            std::cout << "Unknown command.\n";
        }
    }

    return 0;
}