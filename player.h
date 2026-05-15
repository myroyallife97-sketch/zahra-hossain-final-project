#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <vector>

// Player class stores all the player's changing stats/info throughout the game
// like their name, role, health, inventory, etc etc
class Player {

private:

    // player's chosen name
    std::string name;

    // chosen role (Knight, Scholar, or Peasant)
    std::string role;

    // leftover variable from the earlier Shepard Hall concept
    // mainly tracks the player's phone/laptop battery level
    //int battery;

    // player's health -- changes depending on injuries, encounters, healing, etc
    int health;

    // stores the player's current location id
    int currentLocation;

    // inventory system that stores collected items
    std::vector<std::string> inventory;

public:

    // default constructor
    Player();

    // setter functions -- used to update/change values
    void setName(const std::string& newName);
    void setRole(const std::string& newRole);
    //void setBattery(int newBattery);
    void setHealth(int newHealth);
    void setCurrentLocation(int newLocation);

    // getter functions -- safely returns/accesses private variables
    std::string getName() const;
    std::string getRole() const;
    //int getBattery() const;
    int getHealth() const;
    int getCurrentLocation() const;

    // changes the player's health by adding/subtracting an amount
    void changeHealth(int amount);

    // changes the battery percentage
    //void changeBattery(int amount);

    // inventory management functions
    void addItem(const std::string& item);
    void removeItem(const std::string& item);

    // checks whether the player has a certain item or not
    bool hasItem(const std::string& item) const;

    // displays player stats
    void showStats() const;

    // displays inventory contents
    void showInventory() const;
};

#endif