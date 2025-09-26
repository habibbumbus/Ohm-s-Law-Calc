#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
using namespace std;

// Ohm’s Law & Circuit Calculator
// - Compute V, I, R, P from pairs



void clearLine() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Read an integer within [lo, hi], with prompt. Re-prompts on invalid input.
int readIntInRange(const string& prompt, int lo, int hi) {
    while (true) {
        cout << prompt;
        int x;
        if (cin >> x) {
            if (x >= lo && x <= hi) {
                clearLine();
                return x;
            } else {
                cout << "Please enter an integer from " << lo << " to " << hi << ".\n";
            }
        } else {
            cout << "Invalid input. Please enter an integer between 0 and 4.\n";
            clearLine();
        }
    }
}

// Read a double with validation.
// requirePositive=true -> must be > 0
// allowZero=true -> 0 allowed if !requirePositive
double readDouble(const string& prompt, bool requirePositive = true, bool allowZero = false) {
    while (true) {
        cout << prompt;
        double x;
        if (cin >> x) {
            clearLine();
            if (requirePositive) {
                if (x > 0.0) return x;
                cout << "Value must be > 0.\n";
            } else {
                if (x > 0.0) return x;
                if (allowZero && fabs(x) < 1e-15) return 0.0;
                if (!allowZero && fabs(x) < 1e-15) {
                    cout << "Zero is not allowed here.\n";
                } else {
                    // negative allowed
                    return x;
                }
            }
        } else {
            cout << "Invalid input. Please enter a number (e.g., 12.5).\n";
            clearLine();
        }
    }
}

// ----------- Computation helpers --------------------------------------------

// Prints a line of dashes
void hr() {
    cout << "------------------------------------------------------------\n";
}

// Compute and print voltage given I and R
void computeVoltage() {
    hr();
    cout << "Compute Voltage (V = I * R)\n";
    double I = readDouble("Enter current I (amps, > 0): ");
    double R = readDouble("Enter resistance R (ohms, > 0): ");
    double V = I * R;
    double P = V * I; // power as extra info
    cout << fixed << setprecision(6);
    cout << "Voltage V = " << V << " V\n";
    cout << "Power   P = " << P << " W\n";
}

// Compute and print current given V and R
void computeCurrent() {
    hr();
    cout << "Compute Current (I = V / R)\n";
    double V = readDouble("Enter voltage V (volts, > 0): ");
    double R = readDouble("Enter resistance R (ohms, > 0): ");
    double I = V / R;
    double P = V * I;
    cout << fixed << setprecision(6);
    cout << "Current I = " << I << " A\n";
    cout << "Power   P = " << P << " W\n";
}

// Compute and print resistance given V and I
void computeResistance() {
    hr();
    cout << "Compute Resistance (R = V / I)\n";
    double V = readDouble("Enter voltage V (volts, > 0): ");
    double I = readDouble("Enter current I (amps, > 0): ");
    double R = V / I;
    double P = V * I;
    cout << fixed << setprecision(6);
    cout << "Resistance R = " << R << " ohms\n";
    cout << "Power     P = " << P << " W\n";
}

// Power from chosen pair
void computePower() {
    hr();
    cout << "Compute Power P\n";
    cout << "Choose method:\n";
    cout << "  1) P = V * I\n";
    cout << "  2) P = I^2 * R\n";
    cout << "  3) P = V^2 / R\n";
    int c = readIntInRange("Enter choice (1-3): ", 1, 3);

    cout << fixed << setprecision(6);
    if (c == 1) {
        double V = readDouble("Enter voltage V (volts, > 0): ");
        double I = readDouble("Enter current I (amps, > 0): ");
        cout << "Power P = " << V * I << " W\n";
    } else if (c == 2) {
        double I = readDouble("Enter current I (amps, > 0): ");
        double R = readDouble("Enter resistance R (ohms, > 0): ");
        cout << "Power P = " << (I * I) * R << " W\n";
    } else {
        double V = readDouble("Enter voltage V (volts, > 0): ");
        double R = readDouble("Enter resistance R (ohms, > 0): ");
        cout << "Power P = " << (V * V) / R << " W\n";
    }
}


//  Menu 

void printMenu() {
    hr();
    cout << "Ohm's Law & Circuit Calculator\n";
    cout << "Choose an option:\n";
    cout << "  1) Calculate Voltage (V = I * R)\n";
    cout << "  2) Calculate Current (I = V / R)\n";
    cout << "  3) Calculate Resistance (R = V / I)\n";
    cout << "  4) Calculate Power (choose formula)\n";
    cout << "  0) Quit program\n";
}

int main() {
    cout << fixed << setprecision(6);

    while (true) {
        printMenu();
        int choice = readIntInRange("Enter choice: ", 0, 4);

        switch (choice) {
            case 1: computeVoltage(); break;
            case 2: computeCurrent(); break;
            case 3: computeResistance(); break;
            case 4: computePower(); break;
            case 0:
                cout << "Goodbye!\n";
                return 0;
            default:
                // unreachable due to input validation
                break;
        }
    }
}
