//
//  main.c
//  Race Simulaor
//
//  Created by Parsa Fakouri on 13/07/2024.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structures section
struct Race {
    int numberOfLaps;
    int currentLap;
    char* firstPlaceDrivername;
    char* firstPlaceRaceCarColor;
};

struct RaceCar {
    char* driverName;
    char* raceCarColor;
    int totalLapTime;
};

// Function declarations
void printIntro(void);
void printCountDown(void);
void printFirstPlaceAfterLap(struct Race race);
void printCongratulations(struct Race race);
int calculateTimeToCompleteLap(void);
void updateRaceCar(struct RaceCar* raceCar);
void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2);
void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2);

// Print functions section
void printIntro(void) {
    printf("Welcome to our main event digital race fans! I hope everybody has their snacks because we are about to begin!\n");
}

void printCountDown(void) {
    printf("Racers Ready! In...\n 5\n 4\n 3\n 2\n 1\n Race!\n");
}

void printFirstPlaceAfterLap(struct Race race) {
    printf("After lap %d, the first place is held by %s in the %s car!\n", race.currentLap, race.firstPlaceDrivername, race.firstPlaceRaceCarColor);
}

void printCongratulations(struct Race race) {
    printf("Let's all congratulate %s in the %s car!\n", race.firstPlaceDrivername, race.firstPlaceRaceCarColor);
}

// Logic functions section
int calculateTimeToCompleteLap(void) {
    int speed = (rand() % 3) + 1;
    int acceleration = (rand() % 3) + 1;
    int nerves = (rand() % 3) + 1;
    return speed + acceleration + nerves;
}

void updateRaceCar(struct RaceCar* raceCar) {
    int lapTime = calculateTimeToCompleteLap();
    raceCar->totalLapTime += lapTime;
}

void updateFirstPlace(struct Race* race, struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
    if (raceCar1->totalLapTime <= raceCar2->totalLapTime) {
        race->firstPlaceDrivername = raceCar1->driverName;
        race->firstPlaceRaceCarColor = raceCar1->raceCarColor;
    } else {
        race->firstPlaceDrivername = raceCar2->driverName;
        race->firstPlaceRaceCarColor = raceCar2->raceCarColor;
    }
}

void startRace(struct RaceCar* raceCar1, struct RaceCar* raceCar2) {
    struct Race race = {5, 1, "", ""};

    // Simulate race and update race car total time
    for (int i = 0; i < race.numberOfLaps; i++) {
        race.currentLap = i + 1;
        updateRaceCar(raceCar1);
        updateRaceCar(raceCar2);
        updateFirstPlace(&race, raceCar1, raceCar2);
        printFirstPlaceAfterLap(race);
    }

    printCongratulations(race);
}

int main(void) {
    srand(time(0));

    // Declare and initialize RaceCar types
    struct RaceCar raceCar1 = {"Lewis Hamilton", "Silver", 0};
    struct RaceCar raceCar2 = {"Max Verstappen", "Red", 0};

    // Print intro message and begin the countdown
    printIntro();
    printCountDown();

    // Start the race simulation
    startRace(&raceCar1, &raceCar2);

    return 0;
}


