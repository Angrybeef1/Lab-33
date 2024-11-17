Objective
Write a program that will simulate a line of cars lined up to pay their toll at a toll booth. We will start with a certain number of cars in the line, and repeatedly perform these line operations until the line is empty:

55% probability that the car at the head of the line pays its toll and leaves the toll booth
45% probability that another car joins the line for the toll booth
 

Starter class
Here is Car.h, a Car class with three private member variables (make, year, transponder).

Car-1.hDownload Car-1.h

The constructor will randomly generate a car for you. It selects a random element from the vehicle manufacturer list, generates a 4-digit random number as the transponder number (range: 1000-9999), and randomly generates the year (1999-2024). 

The class has its standard setters and getters, as well as a basic print() function.

Make sure this instruction is at the top of your main.cpp file to link to the Car.h file:

#include "Car.h"

 

Requirements
Use an std::deque. This means our program structure will be a deque of Cars.

Use a constant and initialize it to 2 to determine the initial size of the deque when the simulation starts (representing how many cars are already in line to pay the toll when the simulation starts).

Use the Car class to create Car objects, which are placed in the std::deque representing the toll booth lane.

Do not alter the Car class.

Run the simulation until the queue is empty.

After each time period, display the queue using the .print() method in the Car class.

 

Sample Output
This simulation ran 6 cycles until the queue was empty; your results will vary.

Initial queue:
    [2000 Volkswagen (2408)]
    [2018 Skoda (8214)]

Time: 1 Operation: Joined lane: [2005 Volvo (6662)]
Queue:
    [2000 Volkswagen (2408)]
    [2018 Skoda (8214)]
    [2005 Volvo (6662)]

Time: 2 Operation: Car paid: [2000 Volkswagen (2408)]
Queue:
    [2018 Skoda (8214)]
    [2005 Volvo (6662)]

Time: 3 Operation: Joined lane: [2002 Lexus (6325)]
Queue:
    [2018 Skoda (8214)]
    [2005 Volvo (6662)]
    [2002 Lexus (6325)]

Time: 4 Operation: Car paid: [2018 Skoda (8214)]
Queue:
    [2005 Volvo (6662)]
    [2002 Lexus (6325)]

Time: 5 Operation: Car paid: [2005 Volvo (6662)]
Queue:
    [2002 Lexus (6325)]

Time: 6 Operation: Car paid: [2002 Lexus (6325)]
Queue:
