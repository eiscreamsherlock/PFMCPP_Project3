/*
 Project 3 - Part 4 / 5
 video: Chapter 2 - Part 9
 Member initialization tasks

 Create a branch named Part4
 
 1) do this for each class in this project: 
    initialize some of your member variables either in-class or in the Constructor member initializer list.
    Show me that you understand how to use these language features.

 2) make some of your member functions use those initialized member variables via std::cout statements.
 
 3) click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 */

#include <iostream>
namespace Example 
{
struct UDT  
{
    int a; //a member variable that IS NOT initialized in-class
    float b { 2.f }; //a member variable that IS initialized in-class
    UDT() : a(0) { } // 'constructor-initializer-list' initializing the member that wasn't initialized in-class.
    void printAandB()  //the member function
    {
        std::cout << "UDT::printAandB() a:" << a << " b: " << b << std::endl;  //2) printing out something interesting
    }
};

int main()
{
    UDT foo; //instantiating a Foo in main()
    foo.printAandB(); //calling a member function of the instance that was instantiated.
    return 0;
}
}

//call Example::main()




struct Sword
{
    Sword();
    int lengthInCm, minSinceLastSharpen, crossguardWidth;
    float weightnGrams = 853.8f;
    std::string material;

    bool longOrShort();
    void stab();
    bool needSharpen();
};

Sword::Sword() :
lengthInCm(82), 
minSinceLastSharpen(1440),
crossguardWidth(35)
{
    material = "glorious nippon steel";
    std::cout << "Sword is being constructed with " << lengthInCm << " centimeters in length!\n";
}

bool Sword::longOrShort()
{
    if (lengthInCm < 40) return true;
    return false;
}

bool Sword::needSharpen()
{
    if (minSinceLastSharpen > 360) return true;
    return false;
}

void Sword::stab()
{
    std::cout << "I stab at thee!\t";
    std::cout << "\t->------ \n\n";   // <---- This is not a typo
}


struct FountainPen
{
    FountainPen();
    std::string inkColor = "black";
    float inkRemaining, nibWidthInMm, feedCapacity;
    int daysSinceLastClean;

    struct Nib
    {
        Nib();
        std::string style = "extra fine";
        bool  needsCleaning, isPolished; 
        float lengthInMm = 25;
        double mmDistanceBetweenTines = 0.001;

        void cleanNib(bool toClean);
        void polishNib(std::string nibStyle, bool isPolished);
        void changeNib(std::string newNib);
    };

    Nib currentInstalledNib;

    void writeCharacter(char userCharacter);
    void drawALine(int x_start, int y_start, int lengthOfLine);
    float getMmNibLength(Nib currentNib);
    float compareNibLength(Nib currentNib, Nib newNib);
    void definitelyNotAForLoop(int length);        // This is a helper function, not implementing in main()
};

FountainPen::FountainPen() :
inkRemaining(30.0f),
nibWidthInMm(10.5f),
feedCapacity(30.0f)
{
    daysSinceLastClean = 30;
    std::cout << "FountainPen is being constructed!\n";
}

FountainPen::Nib::Nib() :
needsCleaning(false),        // New nibs are hopefully clean by default
isPolished(false)            // but not necessarily polished
{
    std::cout << "Nib is being constructed!\n";
}

void FountainPen::Nib::cleanNib(bool needClean)
{
    if (needClean)
    {
        std::cout << "All clean!\n";
        needsCleaning = false;
    }
    else
    {
        std::cout << "Nothing to do, already clean!\n";
    }
}

void FountainPen::Nib::polishNib(std::string nStyle, bool alreadyPolished)
{
    if (alreadyPolished)
    {
        std::cout << "Already shiney and smooth.  Time to get writing!\n";
    }
    else
    {
        std::cout << "Let's get that " << nStyle << "nib ready for the page...\n";
        isPolished = true;
        std::cout << "All done!\n";
    }
}

void FountainPen::Nib::changeNib(std::string newNib)
{
    style = newNib;
}

void FountainPen::writeCharacter(char userChar)
{
    std::cout << userChar << std::endl;
}

void FountainPen::definitelyNotAForLoop(int length)
{
    if (length > 0)
    {
        definitelyNotAForLoop(length - 1);
        std::cout << "-";
    }
}

void FountainPen::drawALine(int x_start, int y_start, int lineLeng)
{
    std::cout << x_start << " x ";
    FountainPen::definitelyNotAForLoop(lineLeng);
    std::cout << " y " << y_start << "\n";
}

float FountainPen::getMmNibLength(Nib currentNib)
{
    return currentNib.lengthInMm;
}

float FountainPen::compareNibLength(Nib currentNib, Nib newNib)
{
    if (currentNib.lengthInMm < newNib.lengthInMm)
    {
        std::cout << "The new nib is longer.\n";
        return newNib.lengthInMm;
    }
    std::cout << "The current nib is longer.\n";
    return currentNib.lengthInMm;
}

struct GameBoy
{
    GameBoy();
    int screenSize;
    double screenBrightness = 75.0;
    std::string nameOfInsertedGame = "Pokemon Yellow";
    float volume, batteryConsumptionPercentage; 

    struct Cartridge
    {
        Cartridge();
        std::string name = "Battle Toads";
        std::string cartridgeColor = "grey";
        bool isRumblePackEnabled, isBattleToads, isClean;
        int maxMemory, memoryUsed;

        void saveGameStateToRAM();
        void cleanCartridgeHead(Cartridge cName);
        bool doYouHaveBattleToads();
    };

    Cartridge currentGame;

    void howBigIsScreen();
    float adjustVolume(float adjustAmount);
    double adjustBrightness(double adjustAmount);
    void insertNewCartridge(Cartridge newGame);

};

GameBoy::Cartridge::Cartridge() :
isRumblePackEnabled(false),
isBattleToads(false),
maxMemory(16),
memoryUsed(7)
{
    isClean = true;
    std::cout << "Cartridge is being constructed!\n";
}

GameBoy::GameBoy() :
volume(15.0f),
batteryConsumptionPercentage(80.0f)
{
    screenSize = 5;
    std::cout << "GameBoy is being constructed!\n";
}


float GameBoy::adjustVolume(float adjAmount)
{
    return volume += adjAmount;
}

double GameBoy::adjustBrightness(double adjAmount)
{
    return screenBrightness += adjAmount;
}

void GameBoy::insertNewCartridge(Cartridge nGame)
{
    currentGame = nGame;
}

void GameBoy::howBigIsScreen()
{
    std::cout << "This Gameboy has a " << screenSize << " sized screen.\n";
}

void GameBoy::Cartridge::saveGameStateToRAM()
{
    if (memoryUsed < maxMemory)
    {
        std::cout << "You have saved the game!\n";
        maxMemory += 1;
    }
    else
    {
        std::cout << "There is not space left for a new save...\n";
    }
    
}

void GameBoy::Cartridge::cleanCartridgeHead(Cartridge cN)
{
    if (cN.isClean)
    {
        std::cout << "Save your breath, this one's already clean!\n";
    }
    else
    {
        std::cout << "*wind noises...*\n";
        isClean = true;
        std::cout << cN.name << " is all clean!\n";
    }
}

bool GameBoy::Cartridge::doYouHaveBattleToads()
{
    if (isBattleToads) return true;
    
    return false;
}

struct Camera
{
    float batteryLevelPercentage;
    int screenDiagnoalSize, numOfPixels, numOfButtons, flashBrightnessEV;
    Camera();

    void emitFlash();
    float displayBatteryLvl();
    void captureImage();
};

Camera::Camera() :
screenDiagnoalSize(3),
numOfPixels(14),
numOfButtons(7),
flashBrightnessEV(9)
{
    batteryLevelPercentage = 100.0f;
    std::cout << "A " << numOfPixels << " Megapixel Camera is being constructed!\n";
}

void Camera::emitFlash()
{
    std::cout << "FLASHING " << flashBrightnessEV << " times!\n";
}

float Camera::displayBatteryLvl()
{
    std::cout << batteryLevelPercentage << "% battery remaining.\n";
    return batteryLevelPercentage;
}

void Camera::captureImage()
{
    std::cout << ">= 1,000 words.\n";
}

struct Receiver
{
    Receiver();
    float mainVolume, trebleVolume, bassVolume;
    int numOfInputChannels, currentInputChannel, numOfOutputChannels, currentOutputChannel;

    int changeOutputChannelGroup(int target);
    void addInputChannel();
    float changeVolume(float changeAmount);
    void displayNumOfChannels();
};

Receiver::Receiver() :
mainVolume(35.0),
trebleVolume(5.0f),
bassVolume(5.0f),
numOfInputChannels(2),
currentInputChannel(1),
numOfOutputChannels(4),
currentOutputChannel(1)
{
    std::cout << "Receiver is being constructed!\n";
}

void Receiver::displayNumOfChannels()
{
    std::cout << "This receiver is connected to " << numOfInputChannels << " input channels.\n";
}

int Receiver::changeOutputChannelGroup(int t)
{
    if (t > numOfOutputChannels)
    {
        std::cout << "Invalid channel selection.";
        return 1;
    }
    currentOutputChannel = t;
    return 0;
}

void Receiver::addInputChannel()
{
    numOfInputChannels += 1;
}

float Receiver::changeVolume(float chgAmnt)
{
    mainVolume += chgAmnt;
    return mainVolume;
}

struct Speakers
{
    Speakers();
    int numOfSpeakers, speakerWattage;
    float tweeterDiameter, wooferDiameter, midDriverDiameter, volume;

    void addSpeakers(int spkrsToAdd);
    float changeVolume(float changeAmount);
    void bypassSpeakerDriver();
};

Speakers::Speakers():
tweeterDiameter(2.0f),
wooferDiameter(5.5f),
midDriverDiameter(3.3f),
volume(10.0f)
{
    numOfSpeakers = 2;
    speakerWattage = 35;
    std::cout << "Speakers is being constructed!\n";
}

void Speakers::addSpeakers(int numSpkrs)
{
    numOfSpeakers += numSpkrs;
    std::cout << "There are now " << numOfSpeakers << " speakers connected.\n";
}

float Speakers::changeVolume(float chngAmnt)
{
    volume += chngAmnt;
    return volume;
}

void Speakers::bypassSpeakerDriver()
{
    numOfSpeakers = 0;
}


struct Turntable
{
    Turntable();
    int playbackSpeed, playDirection, totalRunTime;
    float pitchAdjustPercent, needLocation;

    void rotateForward();
    float moveNeedle(float moveAmount);    // returns new location
    float changePitchAdjust(float changeAmount);
};

Turntable::Turntable(): 
playbackSpeed(45),
playDirection(1),
totalRunTime(0), 
pitchAdjustPercent(0.0f),
needLocation(1.0f)
{
    std::cout << "Turntable is being constructed!\n";
}

void Turntable::rotateForward()
{
    if (playDirection != 1)
        playDirection = 1;
}

float Turntable::moveNeedle(float mvAmnt)
{
    needLocation += mvAmnt;
    return needLocation;
}
float Turntable::changePitchAdjust(float chngAmnt)
{
    pitchAdjustPercent += chngAmnt;
    return pitchAdjustPercent;
}

struct Radio
{
    Radio();
    int fmChannel, amChannel, satChannel, activeChannelPreset;
    std::string currentWaveType;    // I think this should be an enum, but we haven't covered that yet.
    float broadcastSignalStrengthPercent = 100.0f;

    int changeFmChannel(int targetChannel);
    void changeChannelPreset(int preset);
    std::string changeWaveListenedType(std::string targetWave);    // should prob only accept a wave types enum
};

Radio::Radio() :
fmChannel(971),
amChannel(540), 
satChannel(55),
activeChannelPreset(1)
{
    currentWaveType = "fm";
    std::cout << "Radio is being constructed!\n";
}

int Radio::changeFmChannel(int trgtChnl)
{
    if (fmChannel != trgtChnl )
    {
        fmChannel = trgtChnl;
    }
    return fmChannel;    // returning the channel to confirm the change to whatever calls this.
}
void Radio::changeChannelPreset(int pres)
{
    activeChannelPreset = pres;
}

std::string Radio::changeWaveListenedType(std::string trgtWave)
{
    if (trgtWave != currentWaveType )
    {
        currentWaveType = trgtWave;
    }
    return currentWaveType;
}

struct CdChanger
{
    CdChanger();
    int numDiscsInChanger, maxNumDiscsInChanger, currTrackNumber, currentDiscNumber;
    std::string currentTrackName;
    std::string currentDisc;

    struct Disc
    {
        Disc();
        std::string albumName, firstTrack;
        int numOfTracks = 12;            // I know this limits all discs to 12 tracks.
        std::string trackList[12] {};    // but I don't know how to do a dynamic-sized array in C++ yet

        void displayAlbumName();
    };

    Disc activeDisk;

    void playCD(int newCdNumber, Disc discToPlay);
    void changeTrack (int newTrackNumber, Disc currentDisc);
    void pausePlayback();
};

CdChanger::Disc::Disc()
{
    albumName = "Songs from the Aqualounge";
    firstTrack = "Temporary High";
    std::cout << "Disc is being constructed!\n";
}

void CdChanger::Disc::displayAlbumName()
{
    std::cout << "This album is called: " << albumName << std::endl;
}

CdChanger::CdChanger() :
numDiscsInChanger(0),
maxNumDiscsInChanger(32),
currTrackNumber(1),
currentDiscNumber(1)
{
    currentTrackName = "Sister Christian";
    currentDisc = "Midnight Madness";
    std::cout << "CdChanger is being constructed!\n";
}

void CdChanger::playCD(int newCdNum, Disc disc)
{
    currentDisc = disc.albumName;
    currentDiscNumber = newCdNum;
    currentTrackName = disc.firstTrack;
    currTrackNumber = 1;
}
void CdChanger::changeTrack (int newTrackNum, Disc currDisc)
{
    currTrackNumber = newTrackNum;
    currentTrackName = currDisc.trackList[newTrackNum];
}
void CdChanger::pausePlayback()
{
    std::cout << "*SOUND OF SILENCE*\n";
}

struct HomeStereo
{
    HomeStereo();
    Receiver receiver;
    Speakers speakers;
    Turntable turntable;
    Radio radio;
    CdChanger cdChanger;

    void insertNewDisc(CdChanger::Disc newDisc);
    void changeFmChannel(int newFmChannel, Radio radio);
    void playInReverse(Turntable attachedTurntable);
    void whatsInCdPlayer();
};

HomeStereo::HomeStereo()
{
    std::cout << "HomeStereo is being constructed!\n";
}

void HomeStereo::whatsInCdPlayer()
{
    std::cout << "Looks like we've got " << cdChanger.activeDisk.albumName << " queued up.  Rockin!\n";
}

void HomeStereo::insertNewDisc(CdChanger::Disc newDisc)
{
    cdChanger.numDiscsInChanger += 1;
    cdChanger.playCD(cdChanger.numDiscsInChanger, newDisc);
}
void HomeStereo::changeFmChannel(int newFmChnl, Radio rad)
{
    rad.changeFmChannel(newFmChnl);
}
void HomeStereo::playInReverse(Turntable atchdTable)
{
    atchdTable.playDirection = -1;
}







int main()
{
    Example::main();

    //add your code below this line:
    std::cout << "...just making some room here.\n\n\n";
    Sword excalibur;
    excalibur.lengthInCm = 45;
    std::cout << "----------------\n";
    
    FountainPen platinum;
    std::cout << "----------------\n";
    
    FountainPen::Nib flexyGold;
    flexyGold.style = "gold flexible";
    std::cout << "----------------\n";
    
    FountainPen::Nib music;
    music.style = "music";
    std::cout << "----------------\n";
    
    GameBoy gbColor;
    std::cout << "----------------\n";
    
    GameBoy::Cartridge goldenSun;
    goldenSun.name = "Golden Sun";
    std::cout << "----------------\n";
    
    GameBoy::Cartridge marioBros3;
    marioBros3.name = "Mario Bros 3";
    std::cout << "----------------\n";
    
    Camera leica;
    std::cout << "----------------\n";
    
    Receiver harmonKardon;
    std::cout << "----------------\n";
    
    Speakers jbl;
    std::cout << "----------------\n";
    
    Turntable audioTechnica;
    std::cout << "----------------\n";
    
    Radio rca;
    std::cout << "----------------\n";
    
    CdChanger phillips;
    std::cout << "----------------\n";

    CdChanger::Disc vanHalen;
    vanHalen.albumName = "Van Halen";
    std::cout << "----------------\n";
    
    CdChanger::Disc rideTheLightning;
    rideTheLightning.albumName = "Ride The Lightning";
    std::cout << "----------------\n";
    
    HomeStereo bose;
    std::cout << "----------------\n";
    
    excalibur.longOrShort();
    excalibur.stab();
    excalibur.needSharpen();

    platinum.writeCharacter('q');
    platinum.drawALine(1, 5, 15);
    platinum.getMmNibLength(flexyGold);
    platinum.compareNibLength(platinum.currentInstalledNib, music);
    
    platinum.currentInstalledNib.cleanNib(false);
    platinum.currentInstalledNib.polishNib("italic", true);
    std::cout << "Currently installed nib type is: " << platinum.currentInstalledNib.style << std::endl;
    platinum.currentInstalledNib.changeNib("bold");
    std::cout << "Currently installed nib type is: " << platinum.currentInstalledNib.style << std::endl;


    gbColor.currentGame.saveGameStateToRAM();
    gbColor.currentGame.doYouHaveBattleToads();
    gbColor.howBigIsScreen();

    gbColor.adjustVolume(10.0f);
    gbColor.adjustBrightness(35.0);
    std::cout << "You are playing " << gbColor.currentGame.name << std::endl;
    goldenSun.isClean = false;
    gbColor.insertNewCartridge(goldenSun);
    std::cout << "You are playing " << gbColor.currentGame.name << std::endl;
    gbColor.currentGame.cleanCartridgeHead(gbColor.currentGame);

    marioBros3.cleanCartridgeHead(marioBros3);
    marioBros3.saveGameStateToRAM();
    marioBros3.doYouHaveBattleToads();  
    std::cout << "Excalibur is made from " << excalibur.material << "!" << std::endl;
    
    leica.emitFlash();
    leica.displayBatteryLvl();
    leica.captureImage();

    //std::cout << "Camera battery is currently at " << leica.displayBatteryLvl() << " percent.\n";
    harmonKardon.displayNumOfChannels();
    harmonKardon.changeOutputChannelGroup(2);
    harmonKardon.addInputChannel();
    harmonKardon.displayNumOfChannels();
    std::cout << "Receiver volume is at " << harmonKardon.mainVolume << std::endl;
    harmonKardon.changeVolume(-7.3f);
    std::cout << "Receiver volume is at " << harmonKardon.mainVolume << std::endl;

    std::cout << "Active Speakers: " << jbl.numOfSpeakers << std::endl;
    jbl.addSpeakers(2);
    std::cout << "Active Speakers: " << jbl.numOfSpeakers << std::endl;
    jbl.changeVolume(11.4f);
    jbl.bypassSpeakerDriver();
    std::cout << "Active Speakers: " << jbl.numOfSpeakers << std::endl;
    
    audioTechnica.rotateForward();
    audioTechnica.moveNeedle(2.3f);
    audioTechnica.changePitchAdjust(-0.3f);
    
    rca.changeFmChannel(979);
    rca.changeChannelPreset(3);
    rca.changeWaveListenedType("am");

    vanHalen.displayAlbumName();
    phillips.playCD(2, vanHalen);
    phillips.changeTrack (2, vanHalen);
    std::cout << "Hey, what does this button do?...\n";
    phillips.pausePlayback();

    std::cout << "Current CD in rotation: " << bose.cdChanger.currentDisc << std::endl;
    bose.insertNewDisc(rideTheLightning);
    std::cout << "Current CD in rotation: " << bose.cdChanger.currentDisc << std::endl;
    bose.changeFmChannel(959, bose.radio);
    bose.changeFmChannel(1007, rca);
    bose.playInReverse(bose.turntable);
    bose.whatsInCdPlayer();
    
    std::cout << "good to go!" << std::endl;
}
