//COMSC 210 | LAb 33 | Robert Stonemetz

#include "Car.h"
#include <deque>
#include <iostream>
#include <array>

using namespace std;

//constant variables
const int INITIAL_MIN_CARS = 1;
const int INITIAL_MAX_CARS = 3;
const double PAY_PROBABILITY = 0.55;
const int NUM_LANES = 4;

// prints the current state of the lanes

void printQueue(const array<deque<Car>, NUM_LANES>& lanes){
    cout << "Lanes Status:\n";

    for(int i = 0; i<NUM_LANES; i++){
        cout << "Lane : << i + 1 << :\n";
        if (lanes[i].empty()){
            cout << " empty\n";
        }else{
            for (const Car& car : lanes[i]) {
                cout << "     ";
                Car tempCar = car;
                tempCar.print();
            }
        }
    }
}
    /*if (queue.empty()){
        cout << "\n";
        return;
    }

    for (const Car& car : queue) {
        cout << "     ";
        Car tempCar = car;
        tempCar.print();
    }
}*/

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
    }

    deque<Car> tollQueue;
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
    }

    return 0;
}
