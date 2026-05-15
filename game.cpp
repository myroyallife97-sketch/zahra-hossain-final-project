#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
/* this cstdlib is a really really cool library I found in my research on libraries that may make this project a little easier!!
source(s): https://en.cppreference.com/cpp/header/cstdlib, https://www.tutorialspoint.com/cpp_standard_library/cpp_cstdlib.htm
this library will especially help with random number generation which we'll use for that minigame later,
AND the exit(0) function which will let us end the game immediately when the player's health runs out etc.!
*/
#include <ctime>
/* ctime was briefly mentioned in class i believe, and I came across it once again in my research.
source(s): https://en.cppreference.com/cpp/header/ctime, https://www.tutorialspoint.com/cpp_standard_library/cpp_ctime.htm
the time() function will be used along with the cstdlib rand function to generate more random numbers for the minigame rather than the
kind of "random" but not really random at all numbers that we get without this library
*/
#include "Game.h"
#include "location.h"

using namespace std;

// CONSTRUCTOR
Game::Game() {
    player.setName("");
    player.setRole("");
    player.setHealth(100); // initializing
}

void Game::play() {
    srand(time(0));

    // creates all Location objects so our map exists as a structured set of locations,
    // even though the story itself is controlled through the Game functions below
    vector<Location> allLocations = createAllLocations();

    showIntro();
    classroom314(); // just call to call this one bc from then on its like a chain reaction
}

// get user input to be used in story choices
string Game::getChoice() {
    string choice;
    cout << "\n> ";
    cin >> choice;
    return choice;
}

// add item to vector inventory
void Game::addItem(string item) {
    if (!player.hasItem(item)) {
        player.addItem(item);
        cout << "\n[Inventory updated: " << item << " added]\n";
    }
}

// checks the inventory for a specific item
bool Game::hasItem(string item) {
    return player.hasItem(item);
}

// lowers health and checks for death mueheh
void Game::loseHealth(int amount) {
    player.changeHealth(-amount);

    if (player.getHealth() < 0) {
        player.setHealth(0); // if health gets to a negative number we just set it to 0
    }

    cout << "\n[Health lost: " << amount << "]\n";
    cout << "[Current health: " << player.getHealth() << "]\n"; //printing health updates

    if (player.getHealth() <= 0) {
        cout << "\nYour vision begins to blur...\n";
        cout << "\n The ringing in your ears grow louder, and you feel yourself slipping away from consciousness.\n";
        cout << "\n-------------------------------------------------------------------------\n";
        cout << "\nWith a startling gasp, you jolt awake to find yourself right back in room 314.\n";
        cout <<"\n'What the HELL', you think to yourself, amazed by your imagination and ability to dream so clear. \n";
        cout <<"\n.... because that's what it was right? A dream? It must be. You look to your right, and your stomach drops\n";
        cout << "\nThe note beside your keyboard now says: TRY AGAIN.\n";

        exit(0);
    }
}

// raise health
void Game::healPlayer(int amount) {
    player.changeHealth(amount);

    if (player.getHealth() > 100) {
        player.setHealth(100);
    }

    cout << "\n[Health restored: " << amount << "]\n";
    cout << "[Current health: " << player.getHealth() << "]\n";
}

// print health + inventory --status
void Game::showStatus() {
    cout << "\n--------- STATUS ----------\n";
    cout << "Name: " << player.getName() << endl;
    cout << "Role: " << player.getRole() << endl;
    cout << "Health: " << player.getHealth() << endl;

    player.showInventory();

    cout << "\n-------------------------------\n";
}

// now we get into the actual story!!! yayyyy
void Game::showIntro() {

    cout << "-------------------------------------\n";
    cout << "   AFTER HOURS AT SHEPARD HALL       \n";
    cout << "-------------------------------------\n\n"; // double \n to skip more lines


    cout << "Stretching your arms above your head, you let out a contented sigh, satisfied with your work, and finally shut your laptop.\n";
    cout << "\nYour eyes widen as you look at the time on your phone: 11:07 PM. You had completely lost track of time as you worked hard on your final \nprojects, and were suddenly in a great rush to get home.\n";
    cout <<"\nYou realize you've never stayed on campus this late, and take a moment to observe your surroundings.\n";
    cout <<"\nThe bright white lights of the classroom feel harsh as they flicker; the hum of the radiators and the lack of human noise make you feel slightly uneasy and panicky, and you hurry to pack up your belongings.\n";
    cout << "\nAs you place your laptop in your bag, you notice a small piece of paper fall to the ground. Curious, you pick it up and inspect it.\n";
    cout << "\nA note, written in shaky handwriting reads:\n";
    cout << "\"Do not go to the basement unless the lights fail first.\"\n\n";

    cout << "The lights flicker.\n\n";
    cout << "You feel a chill run down your spine.\n";

    cout << "What is your name?\n";
    cout << "> ";
    string name;
    cin >> name;
    player.setName(name);

    cout << "\nWelcome, " << player.getName() << ".\n";
}

// first location
void Game::classroom314() {

    cout << "\nLOCATION: Classroom 314\n";

    cout << "The room feels colder than it did a minute ago, and your hands feel shaky as they hold the note.\n";
    cout << "The hallway outside is dark and silent.\n";

    cout << "Do you go into the hallway or stay in the room?\n";
    cout << "Choices: hallway / room / status\n";

    string choice = getChoice();

    if (choice == "hallway") {

        northHall();

    }
    else if (choice == "room") {

        cout << "\nYou stay still, reading the note over and over.\n";
        cout << "Suddenly, the monitor in front of you turns on by itself with a loud buzzing sound, scaring the shit out of you.\n";
        cout << "It shows a blinking message:\n";
        cout << "\n   LOOK BEHIND YOU.   \n";
        cout << "\n With a nervous pit in your stomach, you slowly turn around, only to find the once shut door of classroom 314 to be wide open.\nWith slow, hesitant steps, you step out into the hallway";

        northHall();

    }
    else if (choice == "status") {

        showStatus();
        classroom314();

    }
    else if (choice == "hesitate") {

        cout << "\nYou hesitate too long.\n";
        cout << "The lights fail, and the room is no longer empty.\n";
        cout << "A sharp whisper echoes through the darkness\n";
        cout << "\n 'GO' \n";
        cout << "\n Your feet act faster than your head, and before you know it, you're sprinting out the door into the hall.\n";

        northHall();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        classroom314();
    }
}

// Second location/scene
void Game::northHall() {

    cout << "\nLOCATION: North Hall\n";


    cout << "The hallway is cold and silent.\n";
    cout << "From below, you hear something moving in the stairwell.\n";
    cout << "A torn map is taped crookedly to the wall.\n";

    //addItem("Torn Map");
    //cout << "\n[ITEM ADDED: Torn map]\n"; we add it before so this made Torn Map show up twice in my test run
    // instead:
    if (!hasItem("Torn Map")) {
    addItem("Torn Map");
    cout << "\n[ITEM ADDED: Torn map]\n";
}

    cout << "\nDo you follow the sound, run back, or check your status?\n";
    cout << "Choices: follow / back / status\n";

    string choice = getChoice();

    if (choice == "follow") {

        cout << "\nYou step toward the stairs, and the lights go out completely.\n";

        systemsLab();

    }
    else if (choice == "back") {

        cout << "\nYou turn to run, but your classroom door is already closed.\n";
        cout << "Something scratches on the other side.\n";
        cout << "\nTerror sets in and you decide to keep running down the hall, eventually turning into a computer room and banging your way through the door\n";

        systemsLab();

    }
    else if (choice == "status") {

        showStatus();
        northHall();

    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        northHall();
    }
}

// third location / scene
void Game::systemsLab() {

    cout << "\nLOCATION: Systems Lab\n";
    
    cout << "You stumble into the computer lab.\n";
    cout << "Rows of dark computers line the room.\n";
    cout << "One monitor glows even though no one is logged in, radiating that same dreadful buzzing sound.\n";
    cout << "The screen says: INPUT REQUIRED.\n";

    cout << "\nDo you type on the computer or leave the lab?\n";
    cout << "Choices: type / leave / status\n";

    string choice = getChoice();

    if (choice == "type") {
        cout << "\nYou type: HELP ME\n";
        cout << "The printer suddenly wakes up and spits out a silver key.\n";
        addItem("Silver Key");
        cout << "With hesitant hands, you take the key and tuck it in your pocket, and head back out to the hallway.\n";
        cout << "\n[ITEM ADDED: Silver key]\n";
        facultyCorridor();
    }
    else if (choice == "status") {
        showStatus();
        systemsLab();
    }
    else if (choice == "leave") {
        cout << "\nYou leave the glowing monitor behind.\n";
        facultyCorridor();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        systemsLab();
    }
}

// fourth location / scene
void Game::facultyCorridor() {

    cout << "\nLOCATION: Faculty Corridor\n";
    cout << "Office doors line both sides of the corridor.\n";
    cout << "Nameplates glimmer under the emergency lights.\n";
    cout << "One door is slightly open, and something inside whispers your name.\n";

    cout << "\nDo you enter the office or keep walking?\n";
    cout << "Choices: enter / walk / status\n";

    string choice = getChoice();

    if (choice == "enter") {
        cout << "\nYou step into the office.\n";
        cout << "The room is empty, but the chair slowly turns toward you.\n";
        cout << "A shadow slips across the wall and vanishes under the door.\n";
        cout << "\nYou feel a breath fan across the back of your neck, causing you to jolt back and hit your head on a shelf, \nintensifying your nausea and panic,making you see stars.\n";
        loseHealth(10); // might be risky depending on how i decide to make the story go later on
        cout <<"\nDazed and in pain, you stumble out of the office back into the hallway, slowly regaining your composure.\n";

        readingRoom();
    }
    else if (choice == "status") {
        showStatus();
        facultyCorridor();
    }
    else if (choice == "walk") {
        cout << "\nYou keep walking, refusing to acknowledge the whisper, convincing yourself it's just your imagination.\n";
        readingRoom();
    }
    else {
        cout << "\nInvalid choice. Try again.\n"; // im adding this to every function because our user input is case sensitive, but if we didnt have this,
        // even if the player typed something completely random, the story would keep moving with how i had it before. But I reconstructed the way that the if else statements work so that 
        //that won't happen anymore.
        facultyCorridor();
    }
}

void Game::readingRoom() {

    cout << "\nLOCATION: The Reading Room\n";

    // basic story idea here: Lore scene
    // The player should learn that Shepard Hall has a hidden connection to another world.

    cout << "The Reading Room is colder than the hallway.\n";
    cout << "A few books are scattered on the table closest to the door.\n";
    cout << "One book catches your attention with its black cover and rustic look. It is titled: THE DOOR BELOW.\n";

    cout << "\nDo you take the book or leave it alone?\n";
    cout << "Choices: take / leave / status\n";

    string choice = getChoice();

    if (choice == "take") {
        cout << "\nYou take the black book.\n";
        cout << "Its cover is warm, like it has been held by someone else moments ago.\n";
        cout <<"\n You decide to skim through the pages, and find a plethora of strange symbols and drawings, but one passage stands out.\n";
        cout << "\n the passage describes a hidden door in the basement of Shepard Hall that leads to another world, to a city by the name of Kingsport.\n";
        cout <<"\n You have a hard time processing what you are reading. \n Shepard Hall is a gateway between worlds? Is this book a fantasy story disguised as an absurdly realistic record? What is going on? \n Your thoughts keep spiraling until you tell yourself to get it together and breathe. \n With a newfound sense of curiosity and determination, you hold onto the book and walk out of the room with a clearer head, ready for what the night has in store for you.\n";
        if (!hasItem("Black Book")) {
            addItem("Black Book");
            cout << "[ITEM ADDED: Black book]\n";
        }
        stacksAnnex();
    }
    else if (choice == "status") {
        showStatus();
        readingRoom();
    }
    else if (choice == "leave") {
        cout << "\nYou leave the book behind, but the title stays in your mind.\n";
        stacksAnnex();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        readingRoom();
    }
}

// fifth location / scene
void Game::stacksAnnex() {

    cout << "\nLOCATION: Stacks Annex\n";

    cout << "The bookshelves seem too tall for the room.\n";
    cout << "As you walk between them, the shelves seem to shift behind you, creating an unsettling feeling.\n";
    cout << "\nYou turn a corner and look behind you, but the shelves all remain in the same positions they were in when you walked in.\n";
    cout << "\nA brass lantern hangs from a hook in front of you, already lit.\n";

    cout << "\nDo you take the lantern?\n";
    cout << "Choices: take / leave / status\n";

    string choice = getChoice();

    if (choice == "take") {
        cout << "'It is dark in here', you think to yourself, and grab the lantern.\n";
        cout << "\nYou take the brass lantern. Its flame burns blue.\n";
        if (!hasItem("Brass Lantern")) {
            addItem("Brass Lantern");
            cout << "[ITEM ADDED: Brass lantern]\n";
        }
        studyRoomC();
    }
    else if (choice == "status") {
        showStatus();
        stacksAnnex();
    }
    else if (choice == "leave") {
        cout << "\nYou leave the lantern behind and continue through the dark shelves, eventually finding your way out of that strange room.\n";
        studyRoomC();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        stacksAnnex();
    }
}
// sixth location / scene
void Game::studyRoomC() {

    cout << "\nLOCATION: Study Room C\n";

    cout << "Study Room C is eerily silent.\n";
    cout << "The hum of fluorescent lights, the distant noise of traffic outside,\n";
    cout << "Every sound; the humming of the radiator, your footsteps, and even the sound of your shaky breath seem to be swallowed by the room.\n\n";

    cout << "Only one light remains on.\n";
    cout << "It flickers above a whiteboard covered in smeared writing.\n\n";   // adding more whitespace and skipped lines here to make it more dramatic hehe

    cout << "Most of the words are smudged andimpossible to read, as if someone tried desperately to erase them in a hurry.\n";
    cout << "But one sentence remains untouched:\n\n";

    cout << "\"DOWN IS THE ONLY WAY OUT.\"\n\n";

    cout << "Below the message, an arrow points toward the east stairwell.\n";
    cout << "The marker ink still looks wet.\n";

    cout << "\nDo you go to the stairwell?\n";
    cout << "Choices: stairwell / status\n";

    string choice = getChoice();

    if (choice == "status") {
        showStatus();
        studyRoomC();
    }
    else if (choice == "stairwell") {
        cout << "\nYou grip the door handle and step toward the stairwell.\n";
        eastStairwell();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        studyRoomC();
    }
}

// seventh location / scene
// this is when we start transitioning into the surreal/ portal scenes!
void Game::eastStairwell() {

    cout << "\nLOCATION: East Stairwell\n\n";
    cout << "The east stairwell is somehow even darker than the rest of the building.\n";
    cout << "The lights glow a dull red instead of white, creating an atmosphere of absolute unease.\n\n";

    cout << "You take a deep breath and begin walking down the stairs.\n";
    cout << "Every time you think you have reached the end, more staircases spawn.\n\n";

    cout << "'Shepard Hall should not go this deep.', you think to yourself.\n At this point, the distance you have traveled down is starting to make you dizzy as you consider how far down you truly are.\n";
    cout << "\nThis dizziness is increased tenfold when you look back up, and realize that to your horror, the upper floors are gone.\n";

    cout << "\nChoices: keep going down (TYPE: down) / stop / status\n";

    string choice = getChoice();

    if (choice == "status") {
        showStatus();
        eastStairwell();
    }
    else if (choice == "stop") {
        cout << "\nYou stop on the stairs.\n";
        cout << "For a moment, everything is silent.\n";
        cout << "Then you hear footsteps below you, AND THEY SEEM TO BE CLIMBING UP!.\n\n";

        cout << "You force yourself to keep moving, putting your deeply unsettling fear aside.\n";
        basementLanding();
    }
    else if (choice == "down") {
        cout << "\nYou continue descending into the darkness.\n";
        basementLanding();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        eastStairwell();
    }
}

// eighth location /scene
void Game::basementLanding() {

    cout << "\nLOCATION: Basement Landing\n\n";
    // this one is just a short transition scene between the stairwell and maintenance passage.

    cout << "After what seems like an infinite time loop, the stairway finally ends at a narrow concrete landing.\n";
    cout <<"You almost cannot believe your eyes, thinking your brain might be playing a trick on you and the stairs will continue forevermore.";
    cout << "The air is full of an indescribable smell, something that lures you deeper yet also makes your nose burn; making you cringe and cover your face \nyet continue down the hall.\n";
    cout << "You reach a maintenance door that looks like something out of a medieval television show.\n";

    maintenancePassage();
}
// ninth location / scene
void Game::maintenancePassage() {

    cout << "\nLOCATION: Maintenance Passage\n\n";

    cout << "You enter the maintenance door and are met with a narrow and damp passage that gives you the heebie jeebies.\n";
    cout << "A burst of air rushes out from somewhere, startling you and causing you to jump.\nYou look up and realize it was just a pipe. 'Thank god', you think to yourself. \n\n";

    cout << "Ahead, the hallway splits into two directions.\n";
    cout << "One sign points toward Storage Room B.\n";
    cout << "The other reads ARCHIVE.\n";
    cout << "Something within you urges you to go to Storage Room B. Do you comply?\n";

    cout << "\nChoices: storage / archive / status\n";

    string choice = getChoice();

    if (choice == "storage") {
        storageRoomB();
    }
    else if (choice == "status") {
        showStatus();
        maintenancePassage();
    }
    else if (choice == "archive") {
        sealedArchive();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        maintenancePassage();
    }
}
// tenth location / scene
void Game::storageRoomB() {

    cout << "\nLOCATION: Storage Room B\n\n";
    // The player gets the Bone Dice for the dragon mini-game.
    // hehe DnD reference

    cout << "The room is filled with dusty old desks and boxes.\n";
    cout << "In the center sits a small wooden box.\n\n";

    cout << "Inside are two carved bone dice.\n";
    cout << "The symbols on them do not look like normal numbers.\n";

    addItem("Bone Dice");
    cout << "[ITEM ADDED: Bone dice]\n";

    cout << "\nYou pocket the strange dice and leave the room.\n";

    sealedArchive();
}

void Game::sealedArchive() {

    cout << "\nLOCATION: The Sealed Archive\n\n";
    // Major item/lore scene
    // I want to kinda add some complexity, so im gonna make it so iffff the player found the Silver Key earlier, they get the Bloodglass Shard.

    cout << "The heavy archive door groans open.\n";
    cout << "All of the doors you have come across thus far in this nonsensical basement have been strangely out of place, but this one easily takes the cake\n";
    cout << "The other doors were clearly old, rusted, and medieval looking. This one, however, looks brand new and almost royal.\n";
    cout << "Rows of locked cabinets line the walls.\n";
    cout << "Most are covered in symbols scratched directly into the metal.\n\n";

    if (hasItem("Silver Key")) {
        cout << "One cabinet begins rattling when you step closer.\n";
        cout << "The silver key grows warm in your pocket, as if it were yearning to unlock that lock.\n\n";

        cout << "You unlock the cabinet.\n";
        cout << "Inside rests a glowing shard of deep red glass.\n";

        if (!hasItem("Bloodglass Shard")) {
            addItem("Bloodglass Shard");
            cout <<"[ITEM ADDED: Bloodglass shard]\n";
        }
    }
    else {
        cout << "One cabinet glows faintly from within,\n";
        cout << "but its lock will not move no matter how hard you pull.\n\n";

        cout << "Whatever is inside, you cannot reach it without a key.\n";
    }

    lowerStair();
}

// eleventh location / scene -- transitions to the portal world scenes
void Game::lowerStair() {

    cout << "\nLOCATION: The Lower Stair\n\n";
    cout << "Beyond the archive waits YET ANOTHER another staircase.\n";
    cout << "This one is carved from a luxurious black stone rather than concrete.\n\n";

    blackDoor();
}

void Game::blackDoor() {

    cout << "\nLOCATION: The Black Door\n\n";
    // The player can hear the fantasy world before seeing it!

    cout << "At the bottom of the stairs stands a black iron door.\n\n";

    cout << "From the other side, you hear horse hooves.\n";
    cout << "Distant bells.\n";
    cout << "The roar of a crowd.\n";
    cout << "Something huge breathing in the distance.\n\n";

    cout << "This doesn't make any sense! None of this should exist beneath Shepard Hall.\n";
    cout << "Once again, you try to convince yourself that it's just your imagination, but the sounds are far too vivid to be a hallucination.\n";

    cout << "\nChoices: open / wait / status\n";

    string choice = getChoice();

    if (choice == "status") {
        showStatus();
        blackDoor();
        return;
    }
    else if (choice == "wait") {
        cout << "\nYou hesitate.\n";
        cout << "The handle slowly begins turning on its own.\n";
    }
    else if (choice == "open") {
        cout << "\nYou grip the handle and pull the door open.\n";
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        blackDoor(); // btw these invalid choice else statements call the function within itself so it resets and the user can re-enter their input.
        return;
    }

    thresholdChamber();
}
// PORTAL REVEAAALLLL
void Game::thresholdChamber() {

    cout << "\nLOCATION: Threshold Chamber\n\n";
    cout << "The room beyond the black door is impossibly large. You pinch yourself to make sure you're not dreaming.\n Your eyes are not decieving you, this is real life. The thought of this makes your breath catch in your throat.\n";
    cout << "The portal crackles with a red, pulsing, swirling light, inviting you in.\n";
    cout << "Do you enter, or close the door and pretend you never saw that?\n";
    cout << "Choices: enter / close\n";

    string choice = getChoice();
    if (choice == "enter"){
        theTear();
    }
    else if (choice == "close"){
        cout << "You quickly slam the door shut, refusing to believe what you just saw.\nHowever, the door begins to rumble and then suddenly throws itself open!\n";
        theTear();
    }
    else{
        cout << "\nInvalid choice. Try again.\n";
        blackDoor(); 
        return;
    }
}
// PLAYER ACTUALLY ENTERS PORTAL HERE
void Game::theTear() {

    cout << "\nLOCATION: The Tear\n\n";
    cout << "The red fracture pulses brighter as you step closer.\n";
    cout << "The air around it bends strangely, as if it has its own gravitational pull.\n";
    cout << "For a moment, you see reflections inside the tear:\n";
    cout << "towering castles, burning banners, horse-pulled carriages, a whole new world in a whole other time\n\n";
    cout << "You take one final breath and step forward, tightly closing your eyes and bracing for whatever is to come.\n";

    stonePassage();
}
// first scene in the portal world
void Game::stonePassage() {
   // the first scene where the player realizes their surroundings and that shepard hall is gone o
    cout << "\nLOCATION: Stone Passage\n\n";

    cout << "For a moment, your brain blanks out and your senses give out. Then, just as you reluctantly open your eyes and work hard to \ncatch your breath, your hard work is reversed and your heart skips a beat. \nThe world you are now surrounded by is nowehere comprehensively similar to the one you just left. It doesn't make any sense. \nYour heart skips a beat as you take in your surroundings.\n";
    cout << "You are standing in a narrow stone passageway, crowded with people dressed in medieval clothing. \nWomen wear long cotton dresses with headdresses and men wear tunics and cloaks. You rub your eyes in disbelief as a knight passese by you and gives you a curt nod.\nThe air is thick with the smell of smoke and filth, and you hear a distant bell ring proudly in the distance.\nBeneath you, you feel a deep rumble of along with a growl that makes you lose your balance.\n\n";
    cout << "The rumble grows louder and you begin to see the locals nudge each other and point up the the sky. You look up, and your jaw drops.\nA massive dragon with green and gray scales soars through the sky, glinting in the sunlight and letting out a deafening roar.\n";
    cout << "You let out a small shriek and your body acts before you can think through your actions. You find yourself running down the alley.\n";

    mirrorVault();
}

void Game::mirrorVault() {

    cout << "\nLOCATION: Mirror Vault\n\n";
    // im gonna keep the story printing here like more spaced out so its more dramatic

    cout << "As you keep running, your surrounding alley suddenly opens into a circular chamber.\n";
    cout << "Tall mirrors line the walls from floor to ceiling.\n\n";

    cout << "At first, each mirror reflects only darkness.\n";
    cout << "Then slowly, one by one, the reflections begin to move.\n\n";

    cout << "You step closer to the nearest mirror.\n";
    cout << "Your stomach drops as you realize you do not recognize the person staring back at you.\n";

    chooseRole(); // then it transitions to the function where they choose who they wann be

    cout << "\n Suddenly, the mirrors begin to fade back into darkness, interrupting your reverie.\n";
    cout << "Your surroundings now readjust to the stone passage from before.\n\n";

    portfallAlley();
}
// thsi function allows the player to choose their role in the new world
void Game::chooseRole() {

    cout << "\nChoose your role: Type 1,2 or 3.\n";
    cout << "1. Knight\n";
    cout << "2. Scholar\n";
    cout << "3. Peasant\n";

    string choice = getChoice();

    if (choice == "1") {

        player.setRole("Knight");

        cout << "Refusing to believe your reflection, you look down to confirm that you are indeed clad in iron armor.\nYour frame looks bigger, stronger, and more powerful. \nYou see a large iron sword strapped to your hip, and you turn your body to better inspect it in the mirror.\n";
        cout << "You feel a surge of courage as you continue to inspect yourself, slowly adjusting to this new version of you.";
        // and then i need to add some sort of transition scene within these if statements bc the previous function ends off with the mirror vault disappearing again.
        addItem("Iron Sword");
        cout << "\n[ITEM ADDED: Iron sword]\n";

    }
    else if (choice == "2") {

        player.setRole("Scholar");

        cout << "\nHeavy robes settle over your shoulders.\n";
        cout << "Silver chains and strange symbols hang across your chest.\n";
        // hehe for this part i just used google photos and searched up maesters from GoT for reference
        cout << "Ink stains your older,wiser looking hands.\n";
        cout << "In a pocket of your robes, you find a bundle of ancient-looking notes, \nfilled with strange symbols you feel strangely connected to, as if you have seen them before.\n ";
        cout << "You feel a surge of wisdom and knowledge you further inspect yourself in this new form.\n";
        cout << "[ITEM ADDED: Ancient notes]\n";
        addItem("Ancient Notes");
    }
    else if (choice == "3") {

        player.setRole("Peasant");

        cout << "\nYou look smaller, weaker, and are clad in simple, tattered clothes.\n";
        cout << "Your hands are calloused and dirty, as well as your face and hair.\n";
        cout << "You turn and inspect yourself further, trying to find something redeeming about this new form.\n";

        addItem("Worn Cloak");
        cout << "[ITEM ADDED: Worn Cloak]\n";
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        chooseRole();
    }
}
// now im gonna put in the first ASCII instance!
// ASCII art for the castle / Crimson Keep
void Game::castleArt() {
    // THIS IS A TEMPLATE I FOUND ONLINE AND SLIGHTLY EDITED FROM THIS WEBSITE: https://www.asciiart.eu/art/0c34e1155c410594
    //BY ARTIST: UNKNOWN
    cout <<"                                  |>>>\n";
    cout <<"                                  |    \n";
    cout <<"                    |>>>      _  _|_  _         |>>>\n";
    cout <<"                    |        |;| |;| |;|        |\n";
    cout <<"                _  _|_  _    \\.    .  /    _  _|_  _\n";
    cout <<"               |;|_|;|_|;|    \\:. ,  /    |;|_|;|_|;|\n";
    cout <<"               \\..      /    ||;   . |    \\.    .  /\n";
    cout <<"                \\.  ,  /     ||:  .  |     \\:  .  /\n";
    cout <<"                 ||:   |_   _ ||_ . _ | _   _||:   |\n";
    cout <<"                 ||:  .|||_||_||_||_||_|||:.  |\n";
    cout <<"                 ||:   ||.    .     .      . ||:  .|\n";
    cout <<"                 ||: . ||  THE CRIMSON KEEP  ||:   | /\n";
    cout <<"                 ||:   ||:     _______   .   ||:  |\\\n";
    cout <<"                 ||:   || .   |+++++++|    . ||:   |\n";
    cout <<"                 ||:   ||.    |+++++++| .    ||: . |\n";
    cout <<"              __ ||: . ||: ,  |+++++++|.  . _||_   |\n";
    cout <<"     ____--`~    '--~~__|.    |+++++__|----~    ~`---,              ___\n";
    cout <<"-~--~                   ~---__|,--~'                  ~~----_____-~'   `~----~~\n";
    // after i copy and pasted the art, I had to edit the spacing and add in the cout statements, which was a bit tedious, but my text editor helped by giving me the guidelines
}

// first city arrival point
void Game::portfallAlley() { // called within mirror vault; first scene after that

    cout << "\nLOCATION: Portfall Alley\n\n";

    cout << "You stumble out of the stone passage and into a narrow alley packed with noise, smoke, and movement.\n";
    cout << "For a few seconds, all you can do is stand there and breathe.\n";
    cout << "You're still in shock; in shock of your new form, in shock of your surroundings\n";
    cout << "In shock of the fact that home seems unreachable.\n";
    cout << "Everything around you is stone streets, wooden carts, shouting merchants, and people dressed like they stepped out of another century.\n\n";
    //double skip lines for drama before crimson keep reveal
    cout << "Above the rooftops, far in the distance, you see a massive red stone castle.\n";
    cout << "Its towers rise over the city like they are watching everything below, its flags wave proudly in the wind\n";

    castleArt();

    cout << "Your curiosity is unattainable, and you gather the courage to interact with someone to ask someone for details.\n";
    cout <<"You approach a kind-looking passerby, and ask about the castle.\n";
    cout << "'Drunk, are you,fool? That's the Crimson Keep you twat.'\n";
    cout << "'Fair enough', you think to yourself.\n"; // omfg i forgot this semicolon and was searching through my code for 10 minutes looking for the issue. its time for a break.
    cout << "If anyone in this world knows how to send you home, they might be there in that grand castle.\n\n";
    cout << "With a newfound sense of determination, you carry on towards the castle.\n";

    cout << "Choices: street / status\n";

    string choice = getChoice();

    if (choice == "status") {
        showStatus();
        portfallAlley();
    }
    else if (choice == "street") {
        brokenShieldCourt();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        portfallAlley();
    }
}

// second fantasy city location
void Game::brokenShieldCourt() {

    cout << "\nLOCATION: The Broken Shield Court\n\n";

    cout << "You step into a small courtyard where an old broken shield hangs from a rusted iron post.\n";
    cout << "A tired-looking woman selling bread notices your confused expression.\n\n";

    cout << "\"Lost, are you?\" she asks.\n";
    cout << "You nod. 'I'm hoping to make it to the Crimson Keep.'.\n\n";

    cout << "'The Crimson Keep,' she says. 'Learned folk live there. Best maesters in the realm.'\n";
    cout << "'If you've got questions no normal person can answer, you go uphill. If they let you in.'\n\n";

    cout << "She hands you a small piece of bread before turning away.\n";

    if (!hasItem("Bread")) {
        addItem("Bread");
        cout << "[ITEM ADDED: Bread]\n";
    }
    cout <<"You notice a lively market just down the way.\n";

    cout << "\nChoices: market / status\n";

    string choice = getChoice();

    if (choice == "status") {
        showStatus();
        brokenShieldCourt();
    }
    else if (choice == "market") {
        kingsportMarket();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        brokenShieldCourt();
    }
}

// third fantasy city location
void Game::kingsportMarket() {

    cout << "\nLOCATION: Kingsport Market\n\n";

    cout << "The market is overwhelming.\n";
    cout << "Merchants shout over one another, children run between carts, and the air smells like smoke, fish, spices, and wet stone.\n";
    cout << "You keep your eyes on the Crimson Keep whenever you can see it between the rooftops.\n\n";

    cout << "As you traverse through the stalls, you notice a table full of small objects.\n";
    cout << "Among cracked cups and old coins, you notice a small pouch of copper pieces.\n";

    cout << "\nDo you take the coin pouch or leave it?\n";
    cout << "Choices: take / leave / status\n";

    string choice = getChoice();

    if (choice == "take") {
        cout << "\nYou take the pouch quickly and tuck it away before anyone notices.\n";
        if (!hasItem("Copper Coins")) {
            addItem("Copper Coins");
            cout << "[ITEM ADDED: Copper coins]\n";
        }
        fishmongersRow();
    }
    else if (choice == "status") {
        showStatus();
        kingsportMarket();
    }
    else if (choice == "leave") {
        cout << "\nYou decide not to touch anything. In a world this unfamiliar, stealing from a market might be a terrible idea.\n";
        fishmongersRow();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        kingsportMarket();
    }
}

// fourth fantasy city location
void Game::fishmongersRow() {

    cout << "\nLOCATION: Fishmonger's Row\n\n";

    cout << "As you keep walking, you pass into a narrow street lined with fish stalls.\n";
    cout << "The smell hits you immediately, sharp and salty enough to make your eyes water.\n";
    cout << "A group of workers argue near a cart, and you hear the words 'Mud Gate' and 'King's Road' more than once.\n\n";

    cout << "You move closer and listen.\n";
    cout << "One worker says the Mud Gate leads toward the road uphill, but the streets between here and there are not safe today.\n";
    cout << "Another mentions something about a dragon being seen over the lower district.\n\n";

    cout << "Choices: ask / sneak / status\n";

    string choice = getChoice();

    if (choice == "ask") {
        cout << "\nYou ask one of the workers how to reach the Crimson Keep.\n";
        cout << "He looks you up and down, scoffs, then points down a crooked side street.\n";
        cout << "\"Ratspoke Lane. Then the Mud Gate. Then uphill, if the Gods are in your favor.\"\n";
        ratspokeLane();
    }
    else if (choice == "status") {
        showStatus();
        fishmongersRow();
    }
    else if (choice == "sneak") {
        cout << "\nYou stay quiet and follow the direction everyone keeps pointing toward.\n";
        ratspokeLane();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        fishmongersRow();
    }
}

// fifth fantasy city location
void Game::ratspokeLane() {

    cout << "\nLOCATION: Ratspoke Lane\n\n";

    cout << "Ratspoke Lane is thinner, darker, and much less welcoming than the market.\n";
    cout << "Laundry hangs overhead like torn banners, and the stones beneath your feet are slick with mud.\n";
    cout << "You hear movement behind stacked crates.\n\n";

    cout << "A small boy steps out and blocks your path.\n";
    cout << "'Toll,' he says, holding out his hand like this is completely normal.\n\n";

    cout << "Choices: pay / refuse / status\n";

    string choice = getChoice();

    if (choice == "pay") {
        if (hasItem("Copper Coins")) {
            cout << "\nYou hand him a copper coin.\n";
            cout << "He grins, steps aside, and points you toward the Mud Gate.\n";
            mudGate();
        }
        else {
            cout << "\nYou reach for coins you do not have.\n";
            cout << "He sighs dramatically and says, 'Fine. You look confused enough already. Go.'\n";
            mudGate();
        }
    }
    else if (choice == "status") {
        showStatus();
        ratspokeLane();
    }
    else if (choice == "refuse") {
        cout << "\nYou refuse.\n";
        cout << "The boy whistles, and two older kids appear from the shadows.\n";
        cout << "You push past them and run, but one of them bangs your shoulder with a wooden stick.\n";
        loseHealth(10);
        mudGate();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        ratspokeLane();
    }
}

// sixth fantasy city location DRAGON INTRODUCED AAAAH
void Game::mudGate() {

    cout << "\nLOCATION: The Mud Gate\n\n";

    cout << "The Mud Gate is crowded with carts, guards, farmers, and travelers trying to enter or leave the lower city.\n";
    cout << "Beyond it, the road begins to slope upward toward the Crimson Keep.\n";
    cout << "For the first time since entering this world, the path ahead seems clear.\n\n";

    cout << "Just as a smile begins to form on your face....\n";
    
    cout << "A deeeep rumble shakes the ground.\n\n";
    cout << "A dark shadow passes over the gate.\n\n";
    cout << "Someone screams, \"Dragon!\"\n\n";

    cout << "Choices: hide / run / status\n";

    string choice = getChoice();

    if (choice == "status") {
        showStatus();
        mudGate();
    }
    else if (choice == "hide" || choice == "run") {
        dragonGame(); // either running or hiding both lead the player to the minigame
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        mudGate();
    }
}
// second instance of ASCII ART! this is the dragon for the mini-game
void Game:: dragonArt(){
    // THIS AGAIN IS ART BY AN ARTIST NAMED SHANAKA DIAS THAT I FOUND ON THE ASCII ART ARCHIVES: https://www.asciiart.eu/art/1833b5c2ffc7fafc
    // i used this source: https://stackoverflow.com/questions/4352801/rendering-an-ascii-art-string-with-newline-characters-and-backslashes
    // to figure out how to print backslashes and newline characters within the art.
    // it wsa confusing me on the castle art too, but i just decided to edit the art and replace those backslashes
    // however with the dragon art its much harder to avoid so i decided to do some research
    cout << "\n";
    cout << "          /                            )\n";
    cout << "         (                             |\\\\\n";
    cout << "        /|                              \\\\\n";
    cout << "       //                                \\\\\n";
    cout << "      ///                                 \\|\n";
    cout << "     /( \\\\                                  )\\\\\n";
    cout << "     \\\\\\\\  \\\\_                               //)\n";
    cout << "      \\\\\\\\  :\\\\__                           ///\n";
    cout << "       \\\\\\\\     )                         // \\\\\n";
    cout << "        \\\\\\\\:  /                         // |/\n";
    cout << "         \\\\\\\\ / \\\\                       //  \\\\\n";
    cout << "          /)   \\\\   ___..-'           (|  \\\\_|\n";
    cout << "         //     /   _.'              \\\\ \\\\  \\\\\n";
    cout << "        /|       \\\\ \\\\________          \\\\ | /\n";
    cout << "       (| _ _  __/          '-.       ) /.'\n";
    cout << "        \\\\\\\\ .  '-.__            \\\\_    / / \\\\\n";
    cout << "         \\\\\\\\_'.     > --._ '.     \\\\  / / /\n";
    cout << "          \\\\ \\\\      \\\\     \\\\  \\\\     .' /.'\n";
    cout << "           \\\\ \\\\  '._ /     \\\\ )    / .' |\n";
    cout << "            \\\\ \\\\_     \\\\_   |    .'_/ __/\n";
    cout << "             \\\\  \\\\      \\\\_ |   / /  _/ \\\\_\n";
    cout << "              \\\\  \\\\       / _.' /  /     \\\\\n";
    cout << "              \\\\   |     /.'   / .'       '-,_\n";
    cout << "               \\\\   \\\\  .'   _.'_/             \\\\\n";
    cout << "  /\\\\    /\\\\      ) ___(    /_.'           \\\\    |\n";
    cout << " | _\\\\__// \\\\    (.'      _/               |    |\n";
    cout << " \\\\/_  __  /--'`    ,                   __/    /\n";
    cout << " (_ ) /b)  \\\\  '.   :            \\\\___.-'_/ \\\\__/\n";
    cout << " /:/:  ,     ) :        (      /_.'__/-'|_ _ /\n";
    cout << "/:/: __/\\\\ >  __,_.----.__\\\\    /        (/(/(/\n";
    cout << "(_(,_/V .'/--'    _/  __/ |   /\n";
    cout << "VvvV  //`    _.-' _.'     \\\\   \\\\\n";
    cout << "  n_n//     (((/->/        |   /\n";
    cout << "  '--'         ~='          \\\\  |\n";
    cout << "                             | |,,,\n";
    cout << "                snd          \\\\  \\\\  /\n";
    cout << "                              '.__)\n\n";
    // this was definitely quite the hastle to edit and get the spacing right, but it was worth it!
}
// game within a game -- MINIGAME TIMEEEE
void Game::dragonGame() {

    cout << "\n--------DRAGON ENCOUNTER--------\n\n";

    dragonArt();

    cout << "The dragon drops from the clouds and lands beyond the Mud Gate with enough force to shake the road.\n";
    
    cout << "The impact forces you through the air and you land on your back with a thud.\n";
    loseHealth(15);

    cout << "People scatter in every direction.\n";
    cout << "Smoke curls from the great beast's mouth as its huge eyes sweep across the crowd.\n\n";

    cout << "Your hand rushes to retrieve the Bone Dice in your pocket.\n";
    cout << "The symbols carved into them begin to glow.\n\n";

    if (!hasItem("Bone Dice")) {
        cout << "But then your stomach drops.\n";
        cout << "You never picked up the Bone Dice from Storage Room B.\n";
        cout << "You have nothing magical to help you face the dragon.\n";
        cout << "You have no choice but to run as fast as you can, but the heat catches you from behind.\n";

        loseHealth(40);

        cout << "\nYou fall to your knees, ducking from the impact. All you feel is terror, and scorching heat\n";
        cout << "You somehow manage to crawl your way to Kingsroad.\n\n";

        kingsRoad();

        return;
    }

    cout << "You throw the Bone Dice onto the ground.\n";
    cout << "They clatter across the stones, glowing brighter with every bounce.\n\n";

    int dieOne = rand() % 6 + 1; // here is where the csdtlib and ctime libraries comes into play with the rand function
    int dieTwo = rand() % 6 + 1;
    int total = dieOne + dieTwo;

    if (player.getRole() == "Scholar") { // using the player's choice of role to affect their performance
        cout << "The symbols on the Bone Dice suddenly make sense to you.\n";
        cout << "You whisper the markings under your breath, guiding the magic before the dice stop moving.\n";
        total = total + 2; // magic knowledge adds to roll, better chances at survival
    }
    else if (player.getRole() == "Knight") {
        cout << "You instinctively draw your Iron Sword, knowing it probably cannot kill the dragon, but refusing to stand defenseless.\n";
    }
    else if (player.getRole() == "Peasant") {
        cout << "You know you cannot overpower this beast, so your eyes search desperately for gaps in the crowd and shadows to escape through.\n";
        total = total + 1; // lil pity add bc i feel so sad for the peasant
    }

    cout << "You rolled a " << dieOne << " and a " << dieTwo << ".\n";
    cout << "Total roll: " << total << "\n\n";

    if (total >= 10) { // best roll
        cout << "The dice flash with blinding blue light.\n";
        cout << "A burst of magical force erupts from the stones and slams into the dragon's chest.\n";

        if (player.getRole() == "Knight") {
            cout << "You rush forward with your Iron Sword and strike at the dragon's armored leg, not enough to slay it, but enough to make it stumble back.\n";
        }

        cout << "The dragon roars, furious but shaken, and launches itself back into the sky.\n";
        cout << "The crowd stares at you like you just became part of a legend.\n";
        cout << "You notice one of the great beast's green scales on the ground, and pick it up as a token of your victory.\n";

        if (!hasItem("Dragon Scale")) {
            addItem("Dragon Scale");
            cout << "[ITEM ADDED: Dragon scale]\n";
        }

        kingsRoad();
    }
    else if (total >= 6) { // not that great roll
        cout << "The dice emits a weak blue glow.\n";
        cout << "A wall of sparks bursts between you and the dragon, giving you just enough time to escape.\n";

        if (player.getRole() == "Knight") {
            cout << "You swing your Iron Sword to shield yourself, but the dragon's fire warps the blade until it is useless.\n";
            player.removeItem("Iron Sword");
            cout << "[INVENTORY UPDATED: Iron Sword lost]\n";
        }

        cout << "The dragon's fire fans over the road behind you, and the heat burns your arm as you run.\n";

        loseHealth(30);

        kingsRoad();
    }
    else { // worst roll
        cout << "The dice land badly.\n";
        cout << "For one horrifying second, nothing happens.\n";
        cout << "Then, the dragon lowers its head and breathes fire across the gate.\n";

        if (player.getRole() == "Knight") {
            cout << "You raise your Iron Sword on instinct, but the fire hits too fast. The blade cracks, blackens, and falls from your hand.\n";
            player.removeItem("Iron Sword");
            cout << "[INVENTORY UPDATED: Iron Sword lost]\n";
        }
        else if (player.getRole() == "Peasant") {
            cout << "You take advantage of your small form, and dive beneath a broken cart, using the chaos of the crowd to avoid the worst of the flames.\n";
        }

        if (player.getRole() == "Peasant") {
            loseHealth(40);
        }
        else {
            loseHealth(60);
        }

        cout << "\nYou barely escape through the smoke, coughing and stumbling toward the road uphill.\n";

        kingsRoad();
    }
}
// next location
void Game::kingsRoad() {

    cout << "\nLOCATION: The King's Road\n\n";

    cout << "The King's Road climbs sharply away from the lower city.\n";
    cout << "The journey uphill is rough; you crawl your way up, trying to stabilize your breathing.\n";
    cout << "Behind you, the Mud Gate is still full of smoke, you hear people screaming in pain and fear.\n";
    cout << "Ahead, the Crimson Keep looks closer now, though still impossibly high above the city.\n\n";

    cout << "The road is lined with torches, stone walls, and armed guards watching everyone who passes.\n";
    cout << "You steady yourself and keep walking.\n\n";
    cout << "Do you want to find somewhere to rest, or keep walking towards Lantern Square up ahead?\n";

    cout << "Choices: square / rest / status\n";

    string choice = getChoice();

    if (choice == "rest") {
        cout << "\nYou stop beside a low stone wall and try to regain some of your strength and bring yourself back down to Earth.\n";

        if (hasItem("Bread")) {
            cout << "You remember the bread from the woman in the courtyard. \nYou eagerly take a bite. It's stale, but it helps calm your shaking hands.\n";
            healPlayer(10);
        }
        else {
            cout << "You have nothing to eat, so you simply breathe until your panic settles.\n";
        }
        cout << "Feeling a bit calmer now, you rise and continue treading up Kingsroad.\n";
        lanternSquare();
    }
    else if (choice == "status") {
        showStatus();
        kingsRoad();
    }
    else if (choice == "square") {
        lanternSquare();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        kingsRoad();
    }
}

// eighth fantasy city location
void Game::lanternSquare() {

    cout << "\nLOCATION: Lantern Square\n\n";

    cout << "Lantern Square glows with hundreds of hanging lights.\n";
    cout << "For a moment, the warm glow reminds you of home.\n";
    cout << "The thought makes your chest ache.\n\n";

    cout << "In the center of the square, a fountain has been carved into the shape of a winged lion.\n"; // Lannister reference hehe
    cout << "A guard stands near it, watching the road toward the keep.\n\n";

    cout << "Choices: ask / avoid / status\n";

    string choice = getChoice();

    if (choice == "ask") {
        cout << "\nYou ask the guard how to reach the Crimson Keep from here.\n";
        
        //thus far, the player's choice of role hasn't really had much impact besides the mini game, so im gonna bring it in here.
        if (player.getRole() == "Knight") {
            cout << "The guard notices your armor and straightens a little.\n";
            cout << "\"Outer Keep Gate is past the Ash Steps,\" he says. \"Walk like you belong there.\"\n";
        }
        else if (player.getRole() == "Scholar") {
            cout << "The guard notices your robes and points toward a quieter road.\n";
            cout << "\"Scholars' Row first. The scribes may know who you need to speak with.\"\n";
        }
        else {
            cout << "The guard barely looks at you.\n";
            cout << "\"Servants and common folk use the side paths. Old Well District, then the Ash Steps.\"\n";
        }
        
        cout << "You realize something that makes your stomach flip for a moment.\nSomething about the guard's demeanor made it seem like he knew why you were here. \nHe seemed like he knew you didn't belong here, in this world.\n";

        oldWellDistrict();
    }
    else if (choice == "status") {
        showStatus();
        lanternSquare();
    }
    else if (choice == "avoid") {
        cout << "\nYou avoid the guard and slip through the edge of the square.\n";
        oldWellDistrict();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        lanternSquare();
    }
}

// ninth fantasy city location
void Game::oldWellDistrict() {

    cout << "\nLOCATION: The Old Well District\n\n";

    cout << "The Old Well District is quieter than the market but somehow more unsettling.\n";
    cout << "Old houses lean over narrow paths, and most windows are dark.\n";
    cout << "At the center of the district sits a dry stone well.\n\n";

    cout << "A voice from behind the well says, \"The Keep does not open for fear. It opens for proof.\"\n";
    cout << "An old man steps from the shadows and looks directly at you.\n";
    cout << "\"Find a maester. Tell them you came through the tear below stone. They will understand.\"\n\n";

    cout << "He presses a folded scrap of parchment into your hand.\n";

    if (!hasItem("Maester Note")) {
        addItem("Maester Note");
        cout << "[ITEM ADDED: Maester note]\n";
    }
    cout << "'Oh my god', you think to yourself. YOU WEREN'T CRAZY! That guard knew you didn't belong and so did this man!\n";

    cout << "Choices: steps / status\n";

    string choice = getChoice();

    if (choice == "status") {
        showStatus();
        oldWellDistrict();
    }
    else if (choice == "steps") {
        cout << "You continue towards the stairs ahead.\n";
        ashSteps();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        oldWellDistrict();
    }
}

// tenth fantasy city location
void Game::ashSteps() {

    cout << "\nLOCATION: The Ash Steps\n\n";

    cout << "The Ash Steps rise steeply toward the upper city.\n"; // im picturing the stairs that Cersei has to walk down in the shame ding ding shame scene
    cout << "Your body is still exhausted, and each step feels laborious.\nBut with each step, you are closer and closer to getting the answers you need.\n";
    cout << "With this determination in mind, you take a deep breath and continue up the Ash Steps.\n\n";

    cout << "At the top of the stairs, the city changes.\n";
    cout << "The streets widen, the buildings become cleaner, and the people speak in lower, sharper voices.\n";
    cout << "You have reached the scholar and noble district.\n\n";

    cout << "Choices: scholars / status\n";

    string choice = getChoice();

    if (choice == "status") {
        showStatus();
        ashSteps();
    }
    else if (choice == "scholars") {
        scholarsRow();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        ashSteps();
    }
}
// first location / transition into the scholar/castle locations
void Game::scholarsRow() {

    cout << "\nLOCATION: Scholars' Row\n\n";

    cout << "Scholars' Row is lined with narrow stone buildings, each marked by hanging signs painted with quills, moons, stars, and open books.\n";
    cout << "It feels like a whole new world up here; compared to the chaos of the lower city, this place almost feels peaceful.\n\n";

    cout << "A group of robed scholars hurry past you, carrying stacks of parchment and muttering about omens, portals, and dragonfire.\n";
    cout << "One of them drops a small brass token without noticing.\n\n";

    cout << "Do you pick up the brass token?\n";
    cout << "Choices: take / leave / status\n";

    string choice = getChoice();

    if (choice == "take") {

        cout << "\nYou pick up the token and turn it over in your hand.\n";
        cout << "One side shows a tower. The other shows a dragon in flight.\n";

        if (!hasItem("Brass Token")) {
            addItem("Brass Token");
            cout << "[ITEM ADDED: Brass token]\n";
        }

        rookeryWalk();
    }
    else if (choice == "status") {

        showStatus();
        scholarsRow();
    }
    else if (choice == "leave") {

        cout << "\nYou leave the token where it fell and continue forward.\n";

        rookeryWalk();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        scholarsRow();
    }
}

// this one's kinda just a transition location, but the player gains an inventory item
void Game::rookeryWalk() {

    cout << "\nLOCATION: The Rookery Walk\n\n";

    cout << "Black ravens circle overhead as messengers rush between towers carrying sealed scrolls.\n";
    cout << "One hurried messenger drops a folded parchment near your feet before disappearing into the crowd.\n";

    if (!hasItem("Sealed Scroll")) {
        addItem("Sealed Scroll");
        cout << "[ITEM ADDED: Sealed scroll]\n";
    }

    herbQuarter();
}

// PLAYER GETS SOME HEALING HERE!
void Game::herbQuarter() {

    cout << "\nLOCATION: The Herb Quarter\n\n";

    cout << "As you continute walking, the air begins to smell of herbs, smoke, and medicine.\n";
    cout << "Healers move between crowded benches treating burns, cuts, and fevers.\n";

    cout << "\nA kind, gentle-looking healer notices your injuries and insists on helping you.\n";

    if (player.getRole() == "Scholar") {

        cout << "She notices your robes and treats you more carefully and respectfully than the others,\nearning you a sneer from a clearly drunk man next to you getting treated for a cut on his leg.\n";
        healPlayer(25);
    }
    else {

        healPlayer(15);
    }

    scribesHouse();
}

// castle approach location
void Game::scribesHouse() {

    cout << "\nLOCATION: The Scribe's House\n\n";

    cout << "The Scribe's House is cramped, warm, and filled with shelves of rolled parchment.\nIt reminds you of the shops from Harry Potter\n";
    cout << "A thin man with ink-stained fingers looks up as you enter.\n";
    cout << "'State your business,' he says, already sounding annoyed.\n\n";

    cout << "You explain that you came through the tear beneath stone and need to reach a maester in the Crimson Keep.\n";
    cout << "His expression changes. He looks at you with intent, softened eyes.\n\n";

    cout << "'The tear beneath stone, you say?'.\n'That phrase is not used by fools,' he says quietly. 'Do you have proof?'\n\n";

    cout << "Choices: note / scroll / beg / status\n";

    string choice = getChoice();

    if (choice == "note") {

        if (hasItem("Maester Note")) {

            cout << "\nYou show him the note from the old man near the well.\n";
            cout << "The scribe reads it twice, then seals it with red wax.\n";
            cout << "\"Take this to the Outer Keep Gate. It may get you inside.\"\n";

            if (!hasItem("Wax-Sealed Pass")) {
                addItem("Wax-Sealed Pass");
                cout << "[ITEM ADDED: Wax-sealed pass]\n";
            }
        }
        else {

            cout << "\nYou search your belongings, but you do not have the Maester Note.\n";
            cout << "The scribe frowns. 'Then you have only a strange story.'\n";
        }

        outerKeepGate();
    }
    else if (choice == "scroll") {

        if (hasItem("Sealed Scroll")) {

            cout << "\nYou show him the sealed scroll from the messenger.\n";
            cout << "The scribe examines the seal and nods slowly.\n";
            cout << "'This will do. I can mark you as a temporary courier.'\n";

            if (!hasItem("Courier Mark")) {
                addItem("Courier Mark");
                cout << "[ITEM ADDED: Courier mark]\n";
            }
        }
        else {

            cout << "\nYou do not have any sealed scroll to show him.\n";
            cout << "The scribe looks deeply unimpressed.\n";
        }

        outerKeepGate();
    }
    else if (choice == "status") {

        showStatus();
        scribesHouse();
    }
    else if (choice == "beg") {

        cout << "\nYou try to explain everything at once: Shepard Hall, the stairwell, the tear, the dragon, the impossible city.\n";
        cout << "The scribe stares at you in silence.\n";
        cout << "'Desperation is not proof,' he says, but after a pause, he points toward the gate anyway.\n";

        outerKeepGate();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        scribesHouse();
    }
}

// castle approach location
void Game::outerKeepGate() {

    cout << "\nLOCATION: Outer Keep Gate\n\n";

    cout << "The Outer Keep Gate towers over you, built from deep red stone and black iron.\n";
    cout << "Two guards stand before it with spears crossed.\n\n";

    cout << "'State your purpose,' one guard demands.\n\n";
    cout << "Do you want to show your proof, use your role to convince them, or force your way through?\n";

    cout << "Choices: pass / role / force / status\n";

    string choice = getChoice();

    if (choice == "pass") {

        if (hasItem("Wax-Sealed Pass") || hasItem("Courier Mark")) {

            cout << "\nYou present your proof.\n";
            cout << "The guard studies it, then nods to the other guard.\n";
            cout << "'Let them through. Quickly.'\n";

            crimsonYard();
        }
        else {

            cout << "You reach for proof, but you do not have anything convincing.\n";
            cout << "'No pass. No entry.'\n";

            if (player.getRole() == "Peasant") {

                cout << "You notice a servant path along the side wall and quietly slip through while the guards argue with someone else.\n";
                crimsonYard();
            }
            else {

                loseHealth(10);

                cout << "The guards shove you backward before eventually getting distracted by another traveler.\n";
                cout << "You manage to slip through during the confusion.\n";

                crimsonYard();
            }
        }
    }
    else if (choice == "role") {

        if (player.getRole() == "Knight") {

            cout << "\nYou straighten your posture and rest your hand on your sword holster.\n";
            cout << "The guards exchange looks before stepping aside.\n";

            crimsonYard();
        }
        else if (player.getRole() == "Scholar") {

            cout << "\nYou mention urgent magical research involving the portal.\n";
            cout << "The guards clearly do not understand most of what you say, but they let you pass anyway.\n";

            crimsonYard();
        }
        else {

            cout << "\nYou blend into a passing group of servants carrying supplies through the side entrance.\n";

            crimsonYard();
        }
    }
    else if (choice == "force") {

        cout << "\nYou attempt to force your way through the gate.\n";

        if (player.getRole() == "Knight") {

            cout << "Your armor absorbs most of the impact as the guards drive you back.\n";
            loseHealth(10);
        }
        else {

            cout << "A guard slams the shaft of his spear into your side.\n";
            loseHealth(25);
        }

        cout << "Holding your side in pain, amidst the chaos, you still manage to slip into the Keep grounds.\n";

        crimsonYard();
    }
    else if (choice == "status") {

        showStatus();
        outerKeepGate();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        outerKeepGate();
    }
}

// shortened transition location
void Game::crimsonYard() {

    cout << "\nLOCATION: The Crimson Yard\n\n";

    cout << "The Crimson Yard is crowded with guards, servants, and nobles moving between towering red stone walls.\n";
    cout << "Above you, the higher towers of the Keep disappear into smoke and torchlight.\n";

    cout << "\nA massive doorway ahead leads deeper into the castle.\n";

    hallOfPetitioners();
}

// castle location
void Game::hallOfPetitioners() {

    cout << "\nLOCATION: Hall of Petitioners\n\n";

    cout << "The Hall of Petitioners is packed with people waiting to be heard by someone important.\n";
    cout << "Farmers, merchants, wounded soldiers, and nervous nobles stand in separate clusters.\n";
    cout << "At the far end of the hall, a narrow stairway leads upward toward the Royal Archives.\n\n";

    cout << "A tired clerk blocks the stairway.\n";
    cout << "'No one goes upstairs without a reason,' she says.\n\n";

    cout << "Choices: explain / show / sneak / status\n";

    string choice = getChoice();

    if (choice == "explain") {

        cout << "\nYou explain that you came through a magical tear and need a maester's help to return home.\n";

        if (player.getRole() == "Scholar") {

            cout << "'You scholars always bring the strangest problems,' she mutters before stepping aside.\n";
        }
        else {

            cout << "'That sounds insane,' she says, 'but it also sounds important.'\n";
        }

        royalArchives();
    }
    else if (choice == "show") {
        cout << "You search your inventory for a moment, trying to find some compelling evidence.\n";
        if (hasItem("Dragon Scale")) {

            cout << "You show her the Dragon Scale.\n";
            cout << "The clerk immediately steps aside.\n";

            royalArchives();
        }
        else if (hasItem("Bloodglass Shard")) {

            cout << "You reveal the Bloodglass Shard.\n";
            cout << "Its faint red glow makes the clerk visibly nervous, and she steps aside.\n";

            royalArchives();
        }
        else {
            cout << "After an uncomfortable silence, the clerk sees the desperation in your eyes and lets you through anyway.\n";

            royalArchives();
        }
    }
    else if (choice == "sneak") {

        if (player.getRole() == "Peasant") {

            cout << "\nYou quietly slip behind a group of servants carrying supplies upstairs.\n";

            royalArchives();
        }
        else {

            cout << "\nYou try sneaking past the clerk.\n";
            cout << "She immediately notices and smacks your shoulder with her writing board.\n";

            loseHealth(5);

            royalArchives();
        }
    }
    else if (choice == "status") {

        showStatus();
        hallOfPetitioners();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        hallOfPetitioners();
    }
}
// leading player to exit!!
void Game::royalArchives() {

    cout << "\nLOCATION: The Royal Archives\n\n";

    cout << "The Royal Archives room is extremely cold, as if the room were a freezer preserving its contents.\n";
    cout << "Tall shelves stretch upward into shadow, packed with scrolls, books, and sealed records.\n";
    cout << "For the first time since leaving Shepard Hall, the silence feels familiar. You feel like home may be close\n\n";

    cout << "A candle burns alone on a reading table.\n";
    cout << "Beside it sits a book with a red glass symbol pressed into the cover.\n\n";

    cout << "Choices: read / search / status\n";

    string choice = getChoice();

    if (choice == "read") {

        cout << "\nYou open the red-marked book.\n";
        cout << "The pages describe doors between worlds, opened by bloodglass, fear, and desperate need.\n";

        if (player.getRole() == "Scholar") {

            cout << "The symbols are difficult, but not impossible. Somehow, your scholar's mind understands pieces of the pattern, even though they should be unfamiliar to you.\n";
            if (!hasItem("Portal Lore")) {
                addItem("Portal Lore");
                cout << "[ITEM ADDED: Portal lore]\n";
            }
        }
        else {

            cout << "Most of the writing just makes your head hurt, but one phrase stands out: THE SAGE TOWER KEEPS THE KEY.\n";
        }

        sageTower();
    }
    else if (choice == "search") {

        cout << "\nYou search through nearby scrolls until you find a brittle map of the Keep.\n";
        cout << "A small tower near the inner wall is circled in red ink: SAGE TOWER.\n";

        if (!hasItem("Keep Map")) { // these if statements before adding an inventory item are so that if status is called or the user enters a non-valid response and the text resets, the user doesn't get duplicate items.
            addItem("Keep Map");
            cout << "[ITEM ADDED: Keep map]\n";
        }

        sageTower();
    }
    else if (choice == "status") {

        showStatus();
        royalArchives();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        royalArchives();
    }
}

//MAJOR SCENE getting super close to end locations!
void Game::sageTower() {

    cout << "\nLOCATION: The Sage Tower\n\n";

    cout << "The Sage Tower rises above the inner wall of the Keep.\n";
    cout << "Its spiral staircase is narrow, steep, and lit by blue torches that do not give off heat.\n";
    cout << "At the top, an old maester waits beside a circular window.\n\n";

    cout << "'You are far from your world, traveler.' he says before you even get the chance to speak.\n";
    cout << "'And if you wish to return, you must tell me what you carried through the tear.'\n\n";

    cout << "Choices: shard / book / dice / status\n";

    string choice = getChoice();

    if (choice == "shard") {

        if (hasItem("Bloodglass Shard")) {

            cout << "\nYou show him the Bloodglass Shard from the Sealed Archive.\n";
            cout << "The maester's face grows serious.\n";
            cout << "'The doorway did not simply open for you. It marked you.'\n";

            innerChamber();
        }
        else {

            cout << "\nYou reach for the Bloodglass Shard, but you do not have it.\n";
            cout << "The maester studies you with concern.\n";
            cout << "'Then we must rely on memory instead of proof. Dangerous, but not impossible.'\n";

            innerChamber();
        }
    }
    else if (choice == "book") {

        if (hasItem("Black Book")) {

            cout << "\nYou show him the black book from Shepard Hall.\n";
            cout << "He runs his hand over the cover and whispers, 'The Door Below. So it survived.'\n";

            innerChamber();
        }
        else {

            cout << "\nYou mention the book you saw in Shepard Hall, but admit you did not take it.\n";
            cout << "Then you left behind one of the only witnesses,child,' he says, though not unkindly.\n";

            innerChamber();
        }
    }
    else if (choice == "dice") {

        if (hasItem("Bone Dice")) {

            cout << "\nYou show him the Bone Dice.\n";
            cout << "The symbols glow again, softer this time.\n";
            cout << "'Old magic,' the maester says. 'Unstable, but useful.'\n";

            innerChamber();
        }
        else {

            cout << "\nYou tell him about the dice, but you never picked them up.\n";
            cout << "'Then the path home will have fewer chances,'he says quietly.\n";

            innerChamber();
        }
    }
    else if (choice == "status") {

        showStatus();
        sageTower();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        sageTower();
    }
}

// first exit location
void Game::innerChamber() {

    cout << "\nLOCATION: The Inner Chamber\n\n";

    cout << "The maester leads you down a hidden stair behind the tower wall.\n";
    cout << "The air changes as you descend, growing heavier and heavier with every step.\n";
    cout << "At the bottom waits a round chamber carved from black stone, just like the impossible stair beneath Shepard Hall.\n\n";

    cout << "In the center of the room, a red circular pattern is carved into the floor.\n";
    cout << "In the middle of this pattern lies a missing piece.\n\n";

    if (hasItem("Bloodglass Shard")) {

        cout << "The Bloodglass Shard in your inventory begins to pulse with red light.\n";
        cout << "The maester nods. 'That shard is part of the gate. Place it in the center.'\n";
    }
    else {
        cout << "The maester frowns. 'Without bloodglass, the gate may open violently. But it will still open.'\n";
    }

    cout << "\nChoices: place / wait / status\n";

    string choice = getChoice();

    if (choice == "place") {

        if (hasItem("Bloodglass Shard")) {

            cout << "\nYou place the Bloodglass Shard into the center of the pattern.\n";
            cout << "The floor lights up with red lines, each one racing outward like veins of fire, tracing the edges of the pattern.\n";
        }
        else {

            cout << "\nYou reach toward the empty center of the pattern, but you have no shard to place there.\n";
            cout << "The chamber violently shakes, reacting to your presence alone. You tumble back.\n";
            loseHealth(10);
        }

        hiddenVault();
    }
    else if (choice == "status") {

        showStatus();
        innerChamber();
    }
    else if (choice == "wait") {

        cout << "\nYou wait, afraid to touch anything.\n";
        cout << "However, the chamber does not wait with you.\n";
        cout << "The carved lines ignite on their own, triggered by whatever magic followed you from Shepard Hall.\n";

        hiddenVault();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        innerChamber();
    }
}
// aaaalmost there
void Game::hiddenVault() {

    cout << "\nLOCATION: The Hidden Vault\n\n";

    cout << "A section of the chamber wall sinks into the floor, revealing a narrow passage lit by red crystal light.\n";
    cout << "The maester goes pale. With a trembly voice, he says,\n";
    cout << "'It can't be. This vault was sealed before I was born.'\n\n";

    cout << "Inside, the walls are covered in carvings of two worlds: one of castles and dragons, and one of tall buildings, classrooms, gothic architecture.\n";
    cout << "Your breath catches when you recognize the shape of Shepard Hall carved into the stone.\n\n";

    cout << "At the far end of the vault, a metal gate stands closed.\n";
    cout << "Behind it, red light pulses like a heartbeat. A steady buzzing and pulsing sound emits from the room.\n\n";
    
    cout << "Do you want to go to the gate or stay in the passage and inspect the carvings?\n";
    cout << "Choices: gate / carvings / status\n";

    string choice = getChoice();

    if (choice == "carvings") {

        cout << "\nYou study the carvings more closely.\n";
        cout << "They show people crossing between worlds again and again, but not all of them return unchanged.\n";

        if (player.getRole() == "Scholar" || hasItem("Portal Lore")) {

            cout << "You understand enough to realize the gate needs a living memory of home to guide it.\n";
            if (!hasItem("Memory Key")) {
                addItem("Memory Key");
                cout << "[ITEM ADDED: Memory key]\n";
            }
        }
        else {

            cout << "Most of the symbols are impossible to understand, but one image is clear: someone walking toward a doorway alone.\n";
        }

        gateRoom();
    }
    else if (choice == "status") {

        showStatus();
        hiddenVault();
    }
    else if (choice == "gate") {

        cout << "\nYou move toward the metal gate, mesmerized by the red pulsing light.\n";

        gateRoom();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        hiddenVault();
    }
}

// ending reveal location
void Game::gateRoom() {

    cout << "\nLOCATION: The Gate Room\n\n";

    cout << "The metal gate opens with a sound like old chains dragging across stone.\n";
    cout << "Beyond it is a room filled with broken mirrors, cracked red glass, and burned-out torches.\n";
    cout << "The maester steps carefully beside you.\n\n";

    cout << "'This was not built only to send people home.'\n";
    cout << "'It was built to choose what part of them returns.'\n\n";

    cout << "A pedestal stands in the center of the room.\n";
    cout << "On it rests a bowl of dark red glass.\n\n";

    cout << "Choices: touch / ask / status\n";

    string choice = getChoice();

    if (choice == "ask") {

        cout << "You ask what he means.\n";
        cout << "The maester looks toward the broken mirrors.\n";
        cout << "'The gate gave you a role because this world needed to understand you. But your home may not.'\n";
        cout << "'To return, you must choose yourself again.'\n";

        bloodglassChamber();
    }
    else if (choice == "status") {

        showStatus();
        gateRoom();
    }
    else if (choice == "touch") {

        cout << "You touch the glass bowl.\n";
        cout << "A shock runs through your hand, and every mirror in the room lights up at once.\n";

        bloodglassChamber();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        gateRoom();
    }
}

// PLAYER GETS SENT BACK HOME
void Game::bloodglassChamber() {

    cout << "\nLOCATION: The Bloodglass Chamber\n\n";

    cout << "The mirrors show different versions of you.\n";
    cout << "In one, you still sit in Classroom 314 with your laptop open.\n";
    cout << "In another, you remain here forever beneath the Crimson Keep.\n";
    cout << "In another, you walk through Kingsport as if you were a local.\n\n";

    cout << "The maester's voice sounds distant now.\n";
    cout << "'The return threshold will open only once. Carry what proves you are still yourself.'\n\n";
    cout << "Do you think of memories of home, use one of your items, or rush into the mirror?\n";
    cout << "Choices: memory / item / rush / status\n";

    string choice = getChoice();

    if (choice == "memory") {

        cout << "\nYou close your eyes and think of Shepard Hall: the classroom lights, the note, the hallway, the impossible stair.\n";
        cout << "The mirrors shake as your memories morph the doorway into shape.\n";

        if (!hasItem("Home Memory")) {
            addItem("Home Memory"); // i'll use this later
            cout << "[ITEM ADDED: Home memory]\n";
        }

        returnThreshold();
    }
    else if (choice == "item") {

        if (hasItem("Black Book") || hasItem("Bloodglass Shard") || hasItem("Memory Key")) {

            cout << "\nYou hold up one of the objects that carried you through this nightmare.\n";
            cout << "The bloodglass recognizes it, and the mirrors begin folding inward like pages in a book.\n";

            returnThreshold();
        }
        else {

            cout << "\nYou search for something powerful enough to anchor the portal, but nothing is within reach.\n";
            cout << "The mirrors flicker uncertainly.\n";
            loseHealth(10);

            returnThreshold();
        }
    }
    else if (choice == "status") {

        showStatus();
        bloodglassChamber();
    }
    else if (choice == "rush") {

        cout << "\nPanic overtakes you.\n";
        cout << "You run toward the brightest mirror before the maester can stop you.\n";
        cout << "The glass ripples like water, then swallows you whole.\n";

        returnThreshold();
    }
    else {
        cout << "\nInvalid choice. Try again.\n";
        bloodglassChamber();
    }
}

// SHES BAAAACK
void Game::returnThreshold() {

    cout << "\nLOCATION: The Return Threshold\n\n";

    cout << "The world tears open around you.\n";
    cout << "For one impossible second, you see both places at once: the Crimson Keep burning with torchlight and Shepard Hall glowing under fluorescent bulbs.\n";
    cout << "The maester shouts something, but his voice is already fading.\n\n";

    if (player.getHealth() <= 20) {

        cout << "You are too injured to keep your footing.\n";
        cout << "The threshold pulls you through violently, tearing the fantasy world away in flashes of red and black.\n\n";

        cout << "You wake on the floor of Classroom 314, gasping for breath.\n";
        cout << "Your laptop is still open.\n";
        cout << "The note beside it now reads: YOU GOT LUCKY.\n\n";

        cout << "ENDING: Barely Home\n";
    }
    else if (hasItem("Memory Key") || hasItem("Home Memory")) {

        cout << "You focus on who you were before the mirror changed you.\n";
        cout << "The role, the fear, the castle, the dragon, all of it pulls at you, but you hold onto the memory of home.\n\n";

        cout << "With a flash of red light, you collapse back into Classroom 314.\n";
        cout << "The classroom is silent.\n";
        cout << "Outside the window, the city lights of Harlem glow.\n";
        cout << "But in your hand, something small and red glows faintly.\n\n\n";

        cout << "ENDING: Returned With Proof\n";
    }
    else if (hasItem("Dragon Scale")) {

        cout << "The dragon scale burns hot in your inventory as the portal closes around you.\n";
        cout << "For a moment, the roar of the dragon follows you through the tear.\n\n";

        cout << "You wake in Shepard Hall with smoke in your lungs and a green scale clenched in your hand.\n";
        cout << "You are home, but you know the other world was real.\n\n";

        cout << "ENDING: Dragonmarked\n";
    }
    else {

        cout << "You step into the threshold without knowing whether it will recognize you.\n";
        cout << "The world folds inward, and everything disappears.\n\n";

        cout << "You wake in Classroom 314.\n";
        cout << "For a moment, you think it was all a dream.\n";
        cout << "Then you notice the note beside your keyboard.\n";
        cout << "It now reads: SOME DOORS OPEN TWICE.\n\n";

        cout << "ENDING: The Door Remembers\n";
    }

    cout << "\nThank you for playing!\n";
    cout << "Final status:\n";
    showStatus();

    exit(0);
}