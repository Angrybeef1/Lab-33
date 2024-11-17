//COMSC 210 | LAb 32 | Robert Stonemetz

#include "Car.h"
#include <deque>
#include <iostream>

using namespace std;

const int INITIAL_QUEUE_SIZE = 2;
const double PAY_PROBABILITY = 0.55;

void printQueue(const deque<Car>& queue){
    cout << "Que:\n";
    if (queue.empty()){
        cout << "\n";
        return;
    }

    for (const Car& car : queue) {
        cout << "     ";
        Car tempCar = car;
        tempCar.print();
    }
}

int main () {
    srand(time(0));

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
