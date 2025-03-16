/*
 Project 3 - Part 3 / 5
 video: Chapter 2 - Part 8
 Constructors tasks

 Create a branch named Part3

 On this new branch:

 0) if you opted to not fill in any of your member functions in part2, 
    fill in ALL of your member functions
    
 1) Add a constructor for each User-Defined-Type.
    The constructor should be the first declaration in your UDT, before all member variables and member functions.
    add a std::cout message in the constructor that prints out the name of the class being constructed.  
    When you run your code, you'll see the order that your objects are created in the program output. 
 
 2) For each User-Defined-Type:
        amend some of the member functions to print out something interesting via std::cout
 
 3) Instantiate 1 or 2 instances of EACH of your user-defined types in the main() function.  
    You should have at least 12 different variables declared in main(), because you have written 12 different types (including the nested types)

 4) For each instantiated UDT: 
        call each of that instance's member functions.
        You're doing this to show that your code doesn't produce warnings when you call the functions that take arguments.
 
 5) add some std::cout statements in main() that print out your UDT's member variable values or values returned from your UDT member functions (if they return values)
 
 After you finish defining each type/function:
 click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 
 example:
 */

#include <iostream>
namespace Example 
{
struct UDT  // my user defined type named 'UDT'
{
    int thing = 0; //a member variable
    UDT();              //1) the constructor
    void printThing();  //the member function
};

//the function definitions are outside of the class
UDT::UDT()
{
    std::cout << "UDT being constructed!" << std::endl; //1) 
}

void UDT::printThing()
{
    std::cout << "UDT::printThing() " << thing << std::endl;  //2) printing out something interesting
}

int main()
{
    UDT foo;              //3) instantiating a UDT named 'foo' in main()
    foo.printThing();     //4) calling a member function of the UDT instance.
    
    //5) a std::cout statement accessing foo's member variable.
    //It also demonstrates a 'ternary expression', which is syntactic shorthand for an 'if/else' expression
    std::cout << "Is foo's member var 'thing' equal to 0? " << (foo.thing == 0 ? "Yes" : "No") << "\n";
    
    return 0;
}
} //end namespace Example

//insert Example::main() into main() of user's repo.





struct Sword
{
    int lengthInCm = 82;
    float weightnGrams = 853.8f;
    std::string material = "glorious nippon steel";
    int minSinceLastSharpen = 1440;
    int crossguardWidth = 35;
    Sword();

    bool longOrShort();
    void stab();
    bool needSharpen();
};

Sword::Sword()
{
    
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
    std::cout << "->------ \n";
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
        std::string style = "fine";
        bool isPolished = false;
        bool needsCleaning = false;
        float lengthInMm = 25;
        double mmDistanceBetweenTines = 0.001;

        void cleanNib(bool toClean);
        void polishNib(std::string nibStyle, bool isPolished);
        void changeNib(std::string newNib);
    };

    Nib currentInstalledNib;
    int displayCurrentInkLvl();

    void writeCharacter(char userCharacter);
    void drawALine(int x_start, int y_start, int lengthOfLine);
    float getMmNibLength(Nib currentNib);
    float compareNibLength(Nib currentNib, Nib newNib);
    void definitelyNotAForLoop(int length);
};

FountainPen::FountainPen()
{
    
}

FountainPen::Nib::Nib()
{
    
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
    std::cout << userChar;
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
        void cleanCartridgeHead(std::string gameToClean);
        bool doYouHaveBattleToads();
    };

    Cartridge currentGame;

    float adjustVolume(float adjustAmount);
    double adjustBrightness(double adjustAmount);
    void insertNewCartridge(Cartridge newGame);

};

GameBoy::Cartridge::Cartridge()   // Getting error w/ sub-class constructor that is declared by parent
{
    
}

GameBoy::GameBoy()
{
    
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
    std::cout << "There is not space left for a new save...\n";
    
}

void GameBoy::Cartridge::cleanCartridgeHead(std::string gameToClean)
{
    if (isClean)
    {
        std::cout << "Save your breath, this one's already clean!\n";
    }
    else
    {
        std::cout << "*wind noises...*\n";
        isClean = true;
        std::cout << gameToClean << " is all clean!\n";
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
    std::cout << ">= 1,000 words.";
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
    int fmChannel = 971;    // Should be float, but see note in Radio::changeFmChannel def below
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
    
}

int Radio::changeFmChannel(int trgtChnl)
{
    /* This *should* be a float. Compare with float threw a warning, but the following also gave implicit cast warnings:
    int fmCompare = std::round(fmChannel * 10);
    int trgtCompare = std::round(trgtChannel * 10);
    if (fmCompare != trgtChnl)
    ...
    
    */
    
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
    
}

CdChanger::CdChanger()
{
    
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


    
    std::cout << "good to go!" << std::endl;
}
