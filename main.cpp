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
    int lengthInCm = 82;
    float weightnGrams = 853.8f;
    std::string material = "glorious nippon steel";
    int minSinceLastSharpen = 1440;
    int crossguardWidth = 35;

    bool longOrShort();
    void stab();
    bool needSharpen();
};

Sword::Sword()
{
    std::cout << "Sword being constructed!\n";
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
    float inkRemaining = 30.0f;
    int daysSinceLastClean = 30;
    float nibWidthInMm = 10.5f;
    float feedCapacity = 30.0f;

    struct Nib
    {
        Nib();
        std::string style = "extra fine";
        bool isPolished = false;
        bool needsCleaning = false;
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
    void definitelyNotAForLoop(int length);        // This is a helper function, not implementing below
};

FountainPen::FountainPen()
{
    std::cout << "FountainPen is being constructed!\n";
}

FountainPen::Nib::Nib()
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
    int screenSize = 5;
    double screenBrightness = 75.0;
    std::string nameOfInsertedGame = "Pokemon Yellow";
    float volume = 15.0f;
    float batteryConsumptionPercentage = 80.0f;

    struct Cartridge
    {
        Cartridge();
        std::string name = "Battle Toads";
        bool isClean = true;
        std::string cartridgeColor = "grey";
        int maxMemory = {16};
        int memoryUsed = {7};
        bool isRumblePackEnabled = false;
        bool isBattleToads = {false};

        void saveGameStateToRAM();
        void cleanCartridgeHead(Cartridge cName);
        bool doYouHaveBattleToads();
    };

    Cartridge currentGame;

    float adjustVolume(float adjustAmount);
    double adjustBrightness(double adjustAmount);
    void insertNewCartridge(Cartridge newGame);

};

GameBoy::Cartridge::Cartridge()
{
    std::cout << "Cartridge is being constructed!\n";
}

GameBoy::GameBoy()
{
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
    float batteryLevelPercentage = 100.0f;
    int screenDiagnoalSize = 3;
    int numOfPixels = 14;
    int numOfButtons = 7;
    int flashBrightnessEV = 9;
    Camera();

    void emitFlash();
    float displayBatteryLvl();
    void captureImage();
};

Camera::Camera()
{
    std::cout << "Camera is being constructed!\n";
}

void Camera::emitFlash()
{
    std::cout << "FLASH " << flashBrightnessEV << " times!\n";
}

float Camera::displayBatteryLvl()
{
    return batteryLevelPercentage;
}

void Camera::captureImage()
{
    std::cout << ">= 1,000 words.\n";
}

struct Receiver
{
    Receiver();
    int numOfInputChannels = 2;
    int currentInputChannel = 1;
    float mainVolume = 35.0;
    int numOfOutputChannels = 4;
    int currentOutputChannel = 1;
    float trebleVolume = 5.0f;
    float bassVolume = 5.0f;

    int changeOutputChannelGroup(int target);
    void addInputChannel();
    float changeVolume(float changeAmount);
};

Receiver::Receiver()
{
    std::cout << "Receiver is being constructed!\n";
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
    numOfOutputChannels += 1;
}

float Receiver::changeVolume(float chgAmnt)
{
    mainVolume += chgAmnt;
    return mainVolume;
}

struct Speakers
{
    Speakers();
    int numOfSpeakers = 2;
    float tweeterDiameter = 2.0f;
    int speakerWattage = 35;
    float wooferDiameter = 5.5f;
    float midDriverDiameter = 3.3f;
    float volume = 10.0f;

    void addSpeakers(int spkrsToAdd);
    float changeVolume(float changeAmount);
    void bypassSpeakerDriver();
};

Speakers::Speakers()
{
    std::cout << "Speakers is being constructed!\n";
}

void Speakers::addSpeakers(int numSpkrs)
{
    numOfSpeakers += numSpkrs;
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
    int playbackSpeed = 45;
    float pitchAdjustPercent = 0.0f;
    int playDirection = 1;
    float needLocation = 1.0f;
    int totalRunTime = 0;

    void rotateForward();
    float moveNeedle(float moveAmount);    // returns new location
    float changePitchAdjust(float changeAmount);
};

Turntable::Turntable()
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
    int fmChannel = 971;
    int amChannel = 540;
    int satChannel = 55;
    int activeChannelPreset = 1;
    std::string currentWaveType = {"fm"};    // I think this should be an enum, but we haven't covered that yet.
    float broadcastSignalStrengthPercent = 100.0f;

    int changeFmChannel(int targetChannel);
    void changeChannelPreset(int preset);
    std::string changeWaveListenedType(std::string targetWave);    // should prob only accept a wave types enum
};

Radio::Radio()
{
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
    int numDiscsInChanger = 0;
    int maxNumDiscsInChanger = 32;
    int currTrackNumber = 1;
    int currentDiscNumber = {};
    std::string currentTrackName = "Sister Christian";
    std::string currentDisc = "Midnight Madness";

    struct Disc
    {
        Disc();
        std::string albumName;
        std::string firstTrack;
        int numOfTracks = 12;            // I know this limits all discs to 12 tracks.
        std::string trackList[12] {};    // but I don't know how to do a dynamic-sized array in C++ yet
    };

    Disc activeDisk;

    void playCD(int newCdNumber, Disc discToPlay);
    void changeTrack (int newTrackNumber, Disc currentDisc);
    void pausePlayback();
};

CdChanger::Disc::Disc()
{
    std::cout << "Disc is being constructed!\n";
}

CdChanger::CdChanger()
{
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
};

HomeStereo::HomeStereo()
{
    std::cout << "HomeStereo is being constructed!\n";
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

    std::cout << "Camera battery is currently at " << leica.displayBatteryLvl() << " percent.\n";

    harmonKardon.changeOutputChannelGroup(2);
    harmonKardon.addInputChannel();
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
    
    std::cout << "good to go!" << std::endl;
}
