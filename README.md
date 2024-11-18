Objective
We will add functionality to Lab 32's code set:

Add multiple lanes into the management system to simulate an entire plaza of toll booths
Add the capability for a car at the rear of a lane to switch lanes
 

GitHub for this lab
Use the same repo as Lab 32. Starting with your completed code from Lab 32, create a new GitHub branch for Lab 33.

Submit the same URL for this lab as Lab 32.

 

Requirements
These are the additional requirements for this lab. These assume you have completed Lab 32 and have a working tool booth simulation.

Add More Lanes
There are now 4 toll booth lanes at play. Use an array to hold the lanes. The array will be of type deque<Car>. When the simulation starts, pre-populate the lanes with 1-3 cars like before.Each time period will now have operations happening on all lines.

 

Add Switching Lanes
Any car at the end of any queue can switch lanes to a random lane that's not their original lane.

 

Probabilities
The three possible operations and their probabilities are:

46% probability that the car at the head of the queue pays its toll and leaves the queue
39% probability that another car joins the queue
15% probability that the rear car will shift lanes
All these probability values need to be stored as constants defined in your program, never in hard-coding.

If a lane is currently empty but there is still more time in the simulation, those probabilities will be just 50/50 if a new car enters the queue or not. Of course another car might shift lanes into it, but that's a different lane's business.

 

Termination Criteria
Run the simulation for 20 time periods.

 

Sample Output
See my notes in highlighter.

Initial queue:
Lane 1:
    [2000 Skoda (7707)]
    [2022 Hyundai (8832)]
Lane 2:
    [2022 Jaguar (4162)]
    [2007 Jaguar (4798)]
Lane 3:
    [2023 Peugeot (5786)]
    [2002 Nissan (6884)]
Lane 4:
    [2018 Mazda (2218)]
    [2001 Volvo (5556)]

Time: 1
Lane: 1 Paid: [2000 Skoda (7707)]   <-- first list what operations happened in all the lanes
Lane: 2 Paid: [2022 Jaguar (4162)]
Lane: 3 Paid: [2023 Peugeot (5786)]
Lane: 4 Joined: [2008 Jaguar (4051)]
Lane 1 Queue:                       <-- then print each lane's queue
        [2022 Hyundai (8832)]
Lane 2 Queue: 
        [2007 Jaguar (4798)]
Lane 3 Queue: 
        [2002 Nissan (6884)]
Lane 4 Queue: 
        [2018 Mazda (2218)]
        [2001 Volvo (5556)]
        [2008 Jaguar (4051)]

Time: 2
Lane: 1 Joined: [1990 Ford (4997)]
Lane: 2 Joined: [1996 Renault (9551)]
Lane: 3 Joined: [2020 Toyota (8607)]
Lane: 4 Joined: [2001 Peugeot (7976)]
Lane 1 Queue: 
        [2022 Hyundai (8832)]
        [1990 Ford (4997)]
Lane 2 Queue: 
        [2007 Jaguar (4798)]
        [1996 Renault (9551)]
Lane 3 Queue: 
        [2002 Nissan (6884)]
        [2020 Toyota (8607)]
Lane 4 Queue: 
        [2018 Mazda (2218)]
        [2001 Volvo (5556)]
        [2008 Jaguar (4051)]
        [2001 Peugeot (7976)]

Time: 3
Lane: 1 Paid: [2022 Hyundai (8832)]
Lane: 2 Paid: [2007 Jaguar (4798)]
Lane: 3 Switched: [2020 Toyota (8607)]
Lane: 4 Switched: [2001 Peugeot (7976)]
Lane 1 Queue: 
        [1990 Ford (4997)]
        [2020 Toyota (8607)]   <-- was in lane 3 but switched
Lane 2 Queue: 
        [1996 Renault (9551)]
        [2001 Peugeot (7976)]  <-- was in lane 4 but switched
Lane 3 Queue: 
        [2002 Nissan (6884)]
Lane 4 Queue: 
        [2018 Mazda (2218)]
        [2001 Volvo (5556)]
        [2008 Jaguar (4051)]

Time: 4
Lane: 1 Paid: [1990 Ford (4997)]
Lane: 2 Switched: [2001 Peugeot (7976)]
Lane: 3 Paid: [2002 Nissan (6884)]
Lane: 4 Switched: [2008 Jaguar (4051)]
Lane 1 Queue: 
        [2020 Toyota (8607)]
Lane 2 Queue: 
        [1996 Renault (9551)]
Lane 3 Queue: 
        [2001 Peugeot (7976)]
        [2008 Jaguar (4051)]
Lane 4 Queue: 
        [2018 Mazda (2218)]
        [2001 Volvo (5556)]

Time: 5
Lane: 1 Paid: [2020 Toyota (8607)]
Lane: 2 Joined: [1991 Nissan (3548)]
Lane: 3 Paid: [2001 Peugeot (7976)]
Lane: 4 Joined: [2011 Hyundai (3770)]
Lane 1 Queue: empty    <-- show an empty queue
Lane 2 Queue: 
        [1996 Renault (9551)]
        [1991 Nissan (3548)]
Lane 3 Queue: 
        [2008 Jaguar (4051)]
Lane 4 Queue: 
        [2018 Mazda (2218)]
        [2001 Volvo (5556)]
        [2011 Hyundai (3770)]
