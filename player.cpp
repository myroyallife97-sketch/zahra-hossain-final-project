#include <iostream>
#include "player.h"

using namespace std;

Player::Player() {
    name = "Unknown";
    role = "none";
    health = 10;
    //battery = 10; my teammate had an idea to let the player carry a flashlight throughout the game, but due to lack of communication we didnt use it
    currentLocation = 0;
}

void Player::setName(const string& newName) {
    name = newName;
}

void Player::setRole(const string& newRole) {
    role = newRole;
}

void Player::setHealth(int newHealth) {
    if (newHealth < 0) {
        health = 0;
    }
    else {
        health = newHealth;
    }
}

/*void Player::setBattery(int newBattery) {
    if (newBattery < 0) {
        battery = 0;
    }
    else if (newBattery > 10) {
        battery = 10;
    }
    else {
        battery = newBattery;
    }
}
*/

void Player::setCurrentLocation(int newLocation) {
    currentLocation = newLocation;
}

string Player::getName() const {
    return name;
}

string Player::getRole() const {
    return role;
}

int Player::getHealth() const {
    return health;
}

/*int Player::getBattery() const {
    return battery;
}*/

int Player::getCurrentLocation() const {
    return currentLocation;
}

void Player::changeHealth(int amount) {
    setHealth(health + amount);
}

/*void Player::changeBattery(int amount) {
    setBattery(battery + amount);
}*/

void Player::addItem(const string& item) {
    inventory.push_back(item);
}

void Player::removeItem(const string& item) {
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory.at(i) == item) {
            inventory.erase(inventory.begin() + i);
            return;
        }
    }
}

bool Player::hasItem(const string& item) const {
    for (int i = 0; i < inventory.size(); ++i) {
        if (inventory.at(i) == item) {
            return true;
        }
    }
    return false;
}

void Player::showStats() const {
    cout << "Player: " << name << endl;
    cout << "Role: " << role << endl;
    cout << "Health: " << health << endl;
    //cout << "Battery: " << battery << endl;
    cout << "Current Location: " << currentLocation << endl;
}

void Player::showInventory() const {
    cout << "Inventory: " << endl;

    if (inventory.size() == 0) {
        cout << "Empty" << endl;
        return;
    }

    for (int i = 0; i < inventory.size(); ++i) {
        cout << "- " << inventory.at(i) << endl;
    }
}