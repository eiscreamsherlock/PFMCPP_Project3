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
    char currentFoot{};

    struct Foot
    {
        int shoeSize;
        char shoeWidth;
        int strideLength;
        char footLabel{};
    
        void stepForward();
        int stepSize(int size, int length);
    };
    Foot rightFoot;
    Foot leftFoot;

    void run(int howFast, bool startWithLeftFoot);

};

void Person::run(int howFast, bool startWithLeftFoot)
{
    if(startWithLeftFoot == true)
    {
        leftFoot.stepForward();
        rightFoot.stepForward();
    }
    else
    {
        rightFoot.stepForward();
        leftFoot.stepForward();
    }
    
    distanceTraveled += (leftFoot.stepSize(leftFoot.shoeSize, leftFoot.strideLength) + rightFoot.stepSize(rightFoot.shoeSize, rightFoot.strideLength)) * howFast;
    
}

void Person::Foot::stepForward()
{
    
}

int Person::Foot::stepSize(int size, int stride)
{
    return size + stride;
}





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
    int swordLengthInCm = 82;
    float swordWeightnGrams = 853.8f;
    std::string swordMaterial = "carbon steel";
    int minSinceLastSharpen = 1440;
    int crossguardWidth = 35;

    void chop();
    void stab();
    void sheatheOrUnsheathe();
};

struct FountainPen
{
    std::string inkColor = "black";
    float inkRemaining = 30.0f;
    int daysSinceLastClean = 30;
    float nibWidthInMm = 10.5f;
    float nibFeedCapacity = 30.0f;
    struct Nib
    {
        std::string nibStyle = "fine";
        bool isPolished = false;
        bool needsCleaning = false;
        int lengthOfNibInMm = 25;
        double mmDistanceBetweenTines = 0.001;

        void cleanNib(bool needsCleaning);
        void polishNib(std::string nibStyle, bool isPolished);
        void changeNib(std::string oldNib, std::string newNib);
    };

    Nib currentInstalledNib;
    int displayCurrentInkLvl();

    void writeCharacter(char userCharacter);
    void drawALine(int x_start, int y_start, int lengthOfLine);
    float getMmNibWidth(Nib currentNib);
    float compareFeedCapacity(Nib currentNib, Nib newNib);
};

struct GameBoy
{
    int screenSize = 5;
    double screenBrightness = 75.0;
    std::string nameOfInsertedGame = "Pokemon Yellow";
    float volume = 15.0f;
    float batteryConsumptionPercentage = 80.0f;
    struct GameCartridge
    {
        std::string name = "Battle Toads";
        bool isClean = true;
        std::string cartridgeColor = "grey";
        int cartridgeMemoryUsed = 8;
        bool isRumblePackEnabled = false;

        void saveGameStateToRAM();
        void cleanCartridgeHead(std::string gameToClean);
        bool doYouHaveBattleToads();
    };

    GameCartridge currentGame;

    void powerOnOrOff();
    float adjustVolume(float adjustAmount);
    double adjustBrightness(double adjustAmount);
    void insertNewCartridge(GameCartridge oldGame, GameCartridge newGame);

};

struct Camera
{
    float batteryLevelPercentage = 100.0f;
    int screenDiagnoalSize = 3;
    int numOfPixels = 14;
    int numOfButtons = 7;
    int flashBrightnessEV = 9.0;

    void emitFlash();
    int adjustAperture(int adjustAmount);
    void captureImage();
};

struct Receiver
{
    int numOfInputChannels = 2;
    float mainVolume = 35.0;
    int numOfOutputChannels = 4;
    float trebleVolume = 5.0f;
    float bassVolume = 5.0f;

    int changeOutputChannelGroup(int target);
    void powerOnOrOff();
    float changeVolume(float changeAmount);
};

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








int main()
{
    std::cout << "good to go!" << std::endl;
}
