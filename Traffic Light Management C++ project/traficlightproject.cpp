#include <iostream>
#include <unistd.h>
using namespace std;

// Define constants for the traffic light states and crosswalk states
const string Red = "Stop";
const string Yellow = "Wait";
const string Green = "Go";
const int Closed = 0;
const int Open = 1;

// Define a structure to hold the traffic light state and crosswalk state
struct TrafficLight {
    string lightState;
    int crosswalkState;
};

// Function prototypes
void DisplayLightState(string);
void DisplayCrosswalkState(int);
string ChangeLight(string);
int ChangeCrosswalk(int, string);

int main() {
    // Initialize a TrafficLight structure with default states
    TrafficLight trafficLight = {Red, Closed};
    int redTime = 60;
    int yellowTime = 5;
    int greenTime = 60;



    // Infinite loop to simulate the traffic light cycle
    while (true) {
        DisplayLightState(trafficLight.lightState);
        DisplayCrosswalkState(trafficLight.crosswalkState);

        // Conditional statements to determine the sleep duration based on the light state
        if (trafficLight.lightState == Red) {
            cout << "Wait for " << redTime << " seconds..." << endl;
            sleep(redTime);
        } else if (trafficLight.lightState == Yellow) {
            cout << "Waiting for " << yellowTime << " seconds..." << endl;
            sleep(yellowTime);
        } else if (trafficLight.lightState == Green) {
            cout << "Waiting for " << greenTime << " seconds..." << endl;
            sleep(greenTime);
        }

        // Change the light and crosswalk states
        trafficLight.lightState = ChangeLight(trafficLight.lightState);
        trafficLight.crosswalkState = ChangeCrosswalk(trafficLight.crosswalkState, trafficLight.lightState);

        // do-while loop to simulate a brief pause after each light cycle
        int counter = 0;
        do {
            sleep(1);
            counter++;
        } while (counter < 1);
    }

    return 0;
}

// Function to display the current light state
void DisplayLightState(string lightState) {
    if (lightState == Red) {
        cout << "RED light" << endl;
        cout << "  STOP " << endl;
    } else if (lightState == Yellow) {
        cout << "YELLOW light" << endl;
        cout << "  WAIT " << endl;
    } else if (lightState == Green) {
        cout << "GREEN light" << endl;
        cout << "  GO " << endl;
    }
}

// Function to display the current crosswalk state
void DisplayCrosswalkState(int crosswalkState) {
    if (crosswalkState == Open) {
        cout << "Crosswalk open" << endl;
    } else if (crosswalkState == Closed) {
        cout << "Crosswalk closed" << endl;
    }
}

// Function to change the light state in a cyclic manner
string ChangeLight(string lightState) {
    if (lightState == Red) {
        return Yellow;
    } else if (lightState == Yellow) {
        return Green;
    } else if (lightState == Green) {
        return Red;
    }
    return Red;
}

// Function to change the crosswalk state based on the light state
int ChangeCrosswalk(int crosswalkState, string lightState) {
    if (crosswalkState == Closed && lightState == Green) {
        return Open;
    } else if (crosswalkState == Open) {
        return Closed;
    }
    return Closed;
}
