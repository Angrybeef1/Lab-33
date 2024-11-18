//COMSC 210 | LAb 33 | Robert Stonemetz

#include "Car.h"
#include <deque>
#include <iostream>
#include <array>
#include <vector>
#include <string>

using namespace std;

//constant variablse split to separate Configuration 
const int INITIAL_MIN_CARS = 1;
const int INITIAL_MAX_CARS = 3;
const int NUM_LANES = 4;
const int SIMULATION_PERIODS = 10;

//constant variablse split to separate probability
const double PROB_PAY = 0.46;      
const double PROB_JOIN = 0.39;      
const double PROB_SWITCH = 0.15;    
const double PROB_NEW_CAR_EMPTY_LANE = 0.50;

// prints the current state of the lanes

void printQueue(const array<deque<Car>, NUM_LANES>& lanes) {
    for (int i = 0; i < NUM_LANES; i++) {
        cout << "Lane " << i + 1 << " Queue: ";
        if (lanes[i].empty()) {
            cout << "empty" << endl;
        } else {
            cout << endl;

            //prints cars for current lane
            for (const auto& car : lanes[i]) {
                cout << "\t";
                car.print();
                cout << endl;
            }
        }
    }
    cout << endl;
}

//processes the time period for each lane
void processLaneOperations(array<deque<Car>, NUM_LANES>& lanes, int currentLane, vector<string>& operations) {
    //handles empty lane
    if (lanes[currentLane].empty()) {
        double probability = (double)rand() / RAND_MAX;
        if (probability < PROB_NEW_CAR_EMPTY_LANE) {
            Car newCar;
            cout << "Lane " << currentLane + 1 << " Joined: ";
            newCar.print();
            cout << endl;
            lanes[currentLane].push_back(newCar);
        }
        return;
    }

    //generates random number for operation
    double probability = (double)rand() / RAND_MAX;
    
    //determnines probability of car paying 
    if (probability < PROB_PAY) {
        cout << "Lane " << currentLane + 1 << " Paid: ";
        lanes[currentLane].front().print();
        cout << endl;
        lanes[currentLane].pop_front();
    //if new car joins
    } else if (probability < PROB_PAY + PROB_JOIN) {
        Car newCar;
        cout << "Lane " << currentLane + 1 << " Joined: ";
        newCar.print();
        cout << endl;
        lanes[currentLane].push_back(newCar);
    // Last car switches lanes 
    } else if (probability < PROB_PAY + PROB_JOIN + PROB_SWITCH && !lanes[currentLane].empty()) {
        // Last car switches lanes
        vector<int> possibleLanes;
        //finds which lane the car switches too
        for (int i = 0; i < NUM_LANES; i++) {
            if (i != currentLane) {
                possibleLanes.push_back(i);
            }
        }
        
        if (!possibleLanes.empty()) {
            int destinationLane = possibleLanes[rand() % possibleLanes.size()];
            Car switchingCar = lanes[currentLane].back();
            cout << "Lane " << currentLane + 1 << " Switched: ";
            switchingCar.print();
            cout << endl;
            // Remove from current lane and add to destination lane
            lanes[currentLane].pop_back();
            lanes[destinationLane].push_back(switchingCar);
        }
    }
}


    
int main () {

    //initializes randomness 
    srand(time(0));

    //create the array of 4 deque

    array<deque<Car>, NUM_LANES>tollLanes;
    //prepopulate lanes with cars
    cout << "Initial queue: \n";
    for (int lane = 0; lane < NUM_LANES; lane++) {
        // Randomly determine initial number of cars for this lane
        int initialCars = rand() % (INITIAL_MAX_CARS - INITIAL_MIN_CARS + 1) + INITIAL_MIN_CARS;
        // Add the determined number of cars to the lane
        for (int i = 0; i < initialCars; i++) {
            tollLanes[lane].push_back(Car());
        }
        cout << "Lane " << lane + 1 << ":\n";
        for (const auto& car : tollLanes[lane]){
            cout << "    ";
            car.print();
            cout << endl;
        }
    }
    cout << endl;

    for (int time = 1; time <= SIMULATION_PERIODS; time++){
        cout << "Time: " << time << endl;

        //stores operations
        vector<string> operations;

        //process each lane
        for(int lane = 0; lane < NUM_LANES; lane++){
            processLaneOperations(tollLanes, lane, operations);
        }

        //prints operations
        for (const string& op : operations){
            cout << op << endl;
        }

        //prints current state
        printQueue(tollLanes);
    }

    /*// Display initial state of all lanes
    cout << "Initial state:\n";
    printLanes(tollLanes);
    cout << endl;

    int time = 1;
    bool lanesActive = true;

    //main similation
    while (lanesActive) {
        cout << "Time Period: " << time << "\n";
        cout << "----------------\n";

        // Process each lane in the current time period
        for (int lane = 0; lane < NUM_LANES; lane++) {
            if (!tollLanes[lane].empty()) {
                // Generate random probability for current operation
                double probability = (double)rand() / RAND_MAX;

                if (probability < PAY_PROBABILITY) {
                    // 55% chance: First car in lane pays and leaves
                    cout << "Lane " << lane + 1 << " - Car paid: ";
                    tollLanes[lane].front().print();
                    tollLanes[lane].pop_front();
                } else {
                    // 45% chance: New car joins the lane
                    Car newCar;
                    cout << "Lane " << lane + 1 << " - Car joined: ";
                    newCar.print();
                    tollLanes[lane].push_back(newCar);
                }
            } else {
                // If lane is empty, automatically add a new car
                Car newCar;
                cout << "Lane " << lane + 1 << " - Car joined empty lane: ";
                newCar.print();
                tollLanes[lane].push_back(newCar);
            }
        }

        // Display state of all lanes after this time period's operations
        cout << "\nAfter operations:\n";
        printLanes(tollLanes);
        cout << endl;


        lanesActive = false;
        for (const auto& lane : tollLanes) {
            if (!lane.empty()) {
                lanesActive = true;
                break;
            }
        }

        time++;
    }

    cout << "Simulation ended: All lanes empty\n";





    /*deque<Car> tollQueue;
    for (int i = 0; i < INITIAL_QUEUE_SIZE; i++){
        tollQueue.push_back(Car());
    }

    cout << "Initial queue:\n";
    printQueue(tollQueue);
    cout << endl;

    int time =1;

    while(!tollQueue.empty()){
        double probability = (double)rand() / RAND_MAX;

        if (probability < PAY_PROBABILITY && !tollQueue.empty()) {
            cout << "Time: " << time << " Operation: Car paid: ";
            tollQueue.front().print();
            tollQueue.pop_front();
        } else {
            Car newCar;
            cout << "Time: " << time << " Operation: Joined lane: ";
            newCar.print();
            tollQueue.push_back(newCar);
        }

        printQueue(tollQueue);
        cout << endl;
        time++;
    }*/

    return 0;
}
