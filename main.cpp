 /*
 Project 3 - Part 2 / 5
 Video: Chapter 2 Part 6
 Implementations tasks
 
Create a branch named Part2

 tasks
 0) delete all of the plain english pseudo-code you added in Part1.
   don't forget to remove the blank lines left behind after you remove your comments
   - you should be left with only your UDTs.
*/
// example:
// if you had something like this at the end of Part1e:
/*
Thing: Car Wash   
    5 properties:
        - number of vacuum cleaners
        - number of eco-friendly cleaning supplies
        - stores the amount of water used per week.
        - stores amount of profit made per week
        - number of cars serviced per day
    3 things it can do:
        - wash and wax car
        - charge customer
        - detail the car interior
 */

#include <iostream>
#include <string>
namespace Part1eVersion 
{
struct CarWash        
{
    //number of vacuum cleaners                     
    int numVacuumCleaners = 3; 
    //number of eco-friendly cleaning supplies      
    int numEcoFriendlyCleaningSupplies = 20;     
    //stores the amount of water used per week.     
    float waterUsedPerWeek = 200.f;            
    //stores amount of profit made per week         
    float profitPerWeek = 495.95f;               
    //number of cars serviced per day               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(float costPerGallon, double fuelAmountInGallons = 2.0, bool requiresDiesel = false);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    //wash and wax car
    void washAndWaxCar( Car car ); 
    //charge customer
    float chargeCustomer(float discountPercentage);
    //detail the car interior
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}

//this is what I want to see after the code is cleaned up: 
namespace Part2Version
{
struct CarWash        
{
    int numVacuumCleaners = 3; 
    int numEcoFriendlyCleaningSupplies = 20;     
    float waterUsedPerWeek = 200.f;            
    float profitPerWeek = 495.95f;               
    int numberOfCarsServiced = 10;               
    
    struct Car  
    {
        bool isAPickupTruck = false;
        float gasMileage = 26.2f;        
        int year = 1985;
        std::string manufacturer = "Toyota";
        std::string model = "Corolla";

        void fillTank(double fuelAmountInGallons = 2.0);  
        void breakDown(std::string failureType, bool requiresTow = false);
        int getMilesTraveledAnnually(bool includeUberLyftTrips);
    };

    void washAndWaxCar( Car car ); 
    float chargeCustomer(float discountPercentage);
    void detailInterior( Car car );
    
    Car carBeingServiced;  
};
}
  /*
    The above snippet is just an example showing you how to clean up your code.  
    Do not put your cleaned up code into a namespace like I have done here.

 1) write the definition for the Type that leftFoot and rightFoot are instantiations of.
    don't forget to define and implement the member functions 'stepForward()' and 'stepSize()'
    you should be able to deduce the return type of those functions based on their usage in Person::run()
    You'll need to insert the Person struct from the video in the space below.
 */


struct Person
{
    int age;
    int height;
    float hairLength;
    float GPA;
    unsigned int SATScore;
    int distanceTraveled;

    struct Foot
    {
        int shoeSize{12};
        char shoeWidth;
        int strideLength{20};
        int footLabel;
    
        int stepForward()
        {
            return stepSize();
        }
        int stepSize()
        {
            return shoeSize + strideLength;
        }
    };

    Foot leftFoot;
    Foot rightFoot;

    void run(int howFast, bool startWithLeftFoot)
    {
        if (startWithLeftFoot) 
            distanceTraveled += (leftFoot.stepSize() + rightFoot.stepSize()) * howFast;

        distanceTraveled += (rightFoot.stepSize() + leftFoot.stepSize()) * howFast;
    }
};



 /*
 2) provide implementations for the member functions you declared in your 10 user-defined types from the previous video outside of your UDT definitions.
    If you have 'unused parameter' warnings, you aren't using one of your function parameters in your implementation.
    Solution: use the parameter in your implementation.

    If you have 'shadows a field of <classname>' warnings, a local variable in the function has the same name as a class member.  
    This local variable could also be a function parameter with the same name as the class member.
    Solution: change the local variable's name so it is different from the class member variable's name.
 
 3) be sure to write the correct full qualified name for the nested type's member functions.
 
 4) After you finish defining each type/function, click the [run] button.  Clear up any errors or warnings as best you can.
 if your code produces a -Wpadded warning, add '-Wno-padded' to the .replit file with the other compiler flags (-Weverything -Wno-missing-prototypes etc etc)
 If your code produces -Wconversion warnings, do NOT use static_cast<> to solve the warnings.  
 Casting has not been covered yet.
 Change your code so that no warnings are produced WITHOUT using casting.
 This usually means you have to use identical types for all variables used in an expression that is producing that conversion warning.
 */


struct Sword
{
    int lengthInCm = 82;
    float weightnGrams = 853.8f;
    std::string material = "glorious nippon steel";
    int minSinceLastSharpen = 1440;
    int crossguardWidth = 35;

    bool longOrShort();
    void stab();
    bool needSharpen();
};

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
    std::string inkColor = "black";
    float inkRemaining = 30.0f;
    int daysSinceLastClean = 30;
    float nibWidthInMm = 10.5f;
    float feedCapacity = 30.0f;

    struct Nib
    {
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
};


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
void FountainPen::drawALine(int x_start, int y_start, int lineLeng)
{
    std::cout << x_start << " x ";
    for (int i = 0; i < lineLeng; i++)
        {
            std::cout << "-";
        }
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
    else
    {
        std::cout << "The current nib is longer.\n";
        return currentNib.lengthInMm;
    }
}

struct GameBoy
{
    int screenSize = 5;
    double screenBrightness = 75.0;
    std::string nameOfInsertedGame = "Pokemon Yellow";
    float volume = 15.0f;
    float batteryConsumptionPercentage = 80.0f;

    struct Cartridge
    {
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

    void emitFlash();
    float displayBatteryLvl();
    void captureImage();
};

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

int Receiver::changeOutputChannelGroup(int t)
{
    if (t > numOfOutputChannels)
    {
        std::cout << "Invalid channel selection.";
        return 1;
    }
    else
    {
        currentOutputChannel = t;
        return 0;
    }
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
    int numOfSpeakers = 2;
    float tweeterDiameter = 2.0f;
    int speakerWattage = 35;
    float wooferDiameter = 5.5f;
    float midDriverDiameter = 3.3f;

    void powerOnOrOff();
    float changeVolume(float changeAmount);
    void bypassSpeakerDriver();
};

void Speakers::powerOnOrOff()
{
    // TODO
}

float Speakers::changeVolume(float changeAmount)
{
    // TODO
    return 0.0;
}

void Speakers::bypassSpeakerDriver()
{
    // TODO
}


struct Turntable
{
    int playbackSpeed = 45;
    float pitchAdjustPercent = 0.0f;
    int playDirection = 1;
    float needLocation = 1.0f;
    int totalRunTime = 0;

    void rotateForward();
    float moveNeedle(float needleLocation, float moveAmount);
    float changePitchAdjust(float changeAmount);
};

void Turntable::rotateForward()
{
    // TODO
}

float Turntable::moveNeedle(float needleLoc, float mvAmnt)
{
    // TODO
    return 0.0;
}
float changePitchAdjust(float chngAmnt)
{
    // TODO
    return 0.0;
}

struct Radio
{
    float fmChannel = 97.1f;
    int amChannel = 540;
    int satChannel = 55;
    int channelPreset = 1;
    float broadcastSignalStrengthPercent = 100.0f;

    void changeChannel(float targetChannel);
    void demodulateBroadcastWave(float wave);
    void changeWaveListenedType(int targetWave);
};

void Radio::changeChannel(float trgtChnl)
{
    // TODO
}
void Radio::demodulateBroadcastWave(float wav)
{
    // TODO
}
void Radio::changeWaveListenedType(int trgtWave)
{
    // TODO
}

struct CdChanger
{
    int numDiscsInChanger = 0;
    int maxNumDiscsInChanger = 32;
    int currTrackNumber = 1;
    std::string currentTrackName = "Sister Christian";
    std::string currentDisc = "Midnight Madness";

    void playCD(int newCdNumber);
    void changeTrack (int newTrackNumber);
    void pausePlayback();
};

void CdChanger::playCD(int newCdNum)
{
    // TODO
}
void CdChanger::changeTrack (int newTrackNum)
{
    // TODO
}
void CdChanger::pausePlayback()
{
    // TODO
}

struct HomeStereo
{
    Receiver receiver;
    Speakers speakers;
    Turntable turntable;
    Radio radio;
    CdChanger cdChanger;

    void playMusic();
    void changeFmChannel(float newFmChannel, Radio radio);
    void playInReverse(Turntable attachedTurntable);
};

void HomeStereo::playMusic()
{
    // TODO
}
void HomeStereo::changeFmChannel(float newFmChnl, Radio rad)
{
    // TODO
}
void HomeStereo::playInReverse(Turntable atchdTable)
{
    // TODO
}







int main()
{
    std::cout << "good to go!" << std::endl;
}
