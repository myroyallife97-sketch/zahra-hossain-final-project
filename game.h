#ifndef GAME_H
#define GAME_H

#include <string>
#include <vector>
#include "player.h"

// main game class -this basically controls the ENTIRE flow of the game story progression, player choices, inventory/health logic, locations, etc etc
class Game {

private:

    // creates a Player object so the game can access the player's
    // name, role, health, inventory, and other changing stats
    Player player;

    // helper functions for inventory management
    void addItem(std::string item);
    bool hasItem(std::string item);

    // helper functions for health changes
    void loseHealth(int amount);
    void healPlayer(int amount);

public:

    // constructor
    Game();

    // starts/runs the game
    void play();

private:

    // intro + setup functions
    void showIntro();
    void chooseRole();

    // displays changing player stats like inventory + health
    void showStatus();

    // gets user input for choices throughout the game
    std::string getChoice();

    // ASCII art functions (required for project)
    void castleArt();
    void dragonArt();

    // Shepard Hall locations
    // each function acts as a location / decision point in the game
    void classroom314();
    void northHall();
    void systemsLab();
    void facultyCorridor();
    void readingRoom();
    void stacksAnnex();
    void studyRoomC();
    void eastStairwell();
    void basementLanding();
    void maintenancePassage();
    void storageRoomB();
    void sealedArchive();
    void lowerStair();
    void blackDoor();
    void thresholdChamber();

    // portal transition locations
    void theTear();
    void stonePassage();
    void mirrorVault();

    // fantasy city locations
    void portfallAlley();
    void brokenShieldCourt();
    void kingsportMarket();
    void fishmongersRow();
    void ratspokeLane();
    void mudGate();
    void kingsRoad();
    void lanternSquare();
    void oldWellDistrict();
    void ashSteps();

    // game within a game
    // dragon encounter that uses rand() with magical dice rolls
    void dragonGame();

    // castle / scholar route locations
    void scholarsRow();
    void rookeryWalk();
    void herbQuarter();
    void scribesHouse();
    void outerKeepGate();
    void crimsonYard();
    void hallOfPetitioners();
    void royalArchives();
    void sageTower();
    void innerChamber();

    // ending reveal + ending locations
    void hiddenVault();
    void gateRoom();
    void bloodglassChamber();
    void returnThreshold();
};

#endif