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

/*
Thing 1) Sword
5 properties:
    1) length (float)
    2) weight (float)
    3) material (std::string)
    4) time since last sharpening (int)
    5) width of crossguard (float)
3 things it can do:
    1) chop
    2) stab
    3) sheathe/unsheathe
*/
struct Sword
{
//     1) length (float)
    int swordLengthInCm = 82;
//     2) weight (float)
    float swordWeightnGrams = 853.8f;
//     3) material (std::string)
    std::string swordMaterial = "carbon steel";
//     4) time since last sharpening (int)
    int minSinceLastSharpen = 1440;
//     5) width of crossguard (float)
    int crossguardWidth = 35;
// 3 things it can do:
//     1) chop
    void chop();
//     2) stab
    void stab();
//     3) sheathe/unsheathe
    void sheatheOrUnsheathe();
};
/*
Thing 2) Fountain Pen
5 properties:
    1) Color of ink (std::string)
    2) Amount of ink in resevoir (float)
    3) Time since last cleaning (int)
    4) Nib width (float)
    5) Nib feed capacity (float)
3 things it can do:
    1) Display current ink level
    2) Write a character
    3) Draw a line
*/
struct FountainPen
{
//     1) Color of ink (std::string)
    std::string inkColor = "black";
//     2) Amount of ink in resevoir (float)
    float inkRemaining = 30.0f;
//     3) Time since last cleaning (int)
    int daysSinceLastClean = 30;
//     4) Nib width (float)
    float nibWidthInMm = 10.5f;
//     5) Nib feed capacity (float)
    float nibFeedCapacity = 30.0f;
    struct Nib
    {
        std::string nibStyle = "fine";
        bool isPolished = false;
        bool needsCleaning = false;
        int lengthOfNibInMm = 25;
        double mmDistanceBetweenTines = 0.001;

        void cleanNib(bool needsCleaning);    // Pass in needsCleaning to potentially skip if already clean
        void polishNib(std::string nibStyle, bool isPolished);
        void changeNib(std::string oldNib, std::string newNib);
    };
// 3 things it can do:
    Nib currentInstalledNib;
//     1) Display current ink level
    int displayCurrentInkLvl();
//     2) Write a character
    void writeCharacter(char userCharacter);
//     3) Draw a line
    void drawALine(int x_start, int y_start, int lengthOfLine);
    float getMmNibWidth(Nib currentNib);        // return Nib size
    float compareFeedCapacity(Nib currentNib, Nib newNib);
};
/*
Thing 3) Gameboy
5 properties:
    1) screen size (int)
    2) screen brightness (double)
    3) name of inserted game (std::string)
    4) volume (float)
    5) battery percentage remaining (float)
3 things it can do:
    1) power on/off
    2) adjust volume
    3) adjust brightness
*/
struct GameBoy
{
//     1) screen size (int)
    int screenSize = 5;
//     2) screen brightness (double)
    double screenBrightness = 75.0;
//     3) name of inserted game (std::string)
    std::string nameOfInsertedGame = "Pokemon Yellow";
//     4) volume (float)
    float volume = 15.0f;
//     5) battery percentage remaining (float)
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
        bool doYouHaveBattleToads();        // Tells us if they have Battle Toads
    };
// 3 things it can do:
//     1) power on/off

    GameCartridge currentGame;
    void powerOnOrOff();
//     2) adjust volume
    float adjustVolume(float adjustAmount); // return updated volume
//     3) adjust brightness
    double adjustBrightness(double adjustAmount); // return updated brightness
    void insertNewCartridge(GameCartridge oldGame, GameCartridge newGame);

};
/*
Thing 4) Camera
5 properties:
    1) Battery level (float)
    2) Screen size, area (int)
    3) Number of megapixels (int)
    4) Number of buttons (int)
    5) flash brightness (float)
3 things it can do:
    1) emit flash
    2) adjust aperture
    3) capture image
*/
struct Camera
{
//     1) Battery level (float)
    float batteryLevelPercentage = 100.0f;
//     2) Screen size, area (int)
    int screenDiagnoalSize = 3;
//     3) Number of megapixels (int)
    int numOfPixels = 14;
//     4) Number of buttons (int)
    int numOfButtons = 7;
//     5) flash brightness (float)
    int flashBrightnessEV = 9.0;
// 3 things it can do:
//     1) emit flash
    void emitFlash();
//     2) adjust aperture
    int adjustAperture(int adjustAmount);    // return new aperture
//     3) capture image
    void captureImage();                    // saves to disk, but returns no value
};
/*
Thing 5) receiver
5 properties:
    1) number of input channels (int)
    2) main volume (float)
    3) number of output channels (int)
    4) treble volume (float)
    5) bass volume (float)
3 things it can do:
    1) change output channel group
    2) power on/off
    3) change volume
*/
struct Receiver
{
//     1) number of input channels (int)
    int numOfInputChannels = 2;
//     2) main volume (float)
    float mainVolume = 35.0;
//     3) number of output channels (int)
    int numOfOutputChannels = 4;
//     4) treble volume (float)
    float trebleVolume = 5.0f;
//     5) bass volume (float)
    float bassVolume = 5.0f;
// 3 things it can do:
//     1) change output channel group
    int changeOutputChannelGroup(int target);    // return active channel group
//     2) power on/off
    void powerOnOrOff();
//     3) change volume
    float changeVolume(float changeAmount);      // return updated volume
};
/*
Thing 6) speakers
5 properties:
    1) number of speakers (int)
    2) diameter of tweeter (float)
    3) power (in watts) (int)
    4) diameter of woofer (float)
    5) diameter of midrange driver (float)
3 things it can do:
    1) power on/off
    2) adjust output volume
    3) bypass driver (for headphone use)
*/
struct Speakers
{
//     1) number of speakers (int)
    int numOfSpeakers = 2;
//     2) diameter of tweeter (float)
    float tweeterDiameter = 2.0f;
//     3) power (in watts) (int)
    int speakerWattage = 35;
//     4) diameter of woofer (float)
    float wooferDiameter = 5.5f;
//     5) diameter of midrange driver (float)
    float midDriverDiameter = 3.3f;
// 3 things it can do:
//     1) power on/off
    void powerOnOrOff();
//     2) adjust output volume
    float changeVolume(float changeAmount);    // return the new volume
//     3) bypass driver (for headphone use)
    void bypassSpeakerDriver();
};
/*
Thing 7) turntable
5 properties:
    1) speed (rotation per min) (int)
    2) pitch adjust percent (float)
    3) rotation direction (int)
    4) needle location (float)
    5) running time (int)
3 things it can do:
    1) rotate forward
    2) move needle
    3) change pitch adjust percentage
*/
struct Turntable
{
//     1) speed (rotation per min) (int)
    int playbackSpeed = 45;
//     2) pitch adjust percent (float)
    float pitchAdjustPercent = 0.0f;
//     3) rotation direction (int)
    int playDirection = 1;
//     4) needle location (float)
    float needLocation = 1.0f;
//     5) running time (int)
    int totalRunTime = 0;
// 3 things it can do:
//     1) rotate forward
    void rotateForward();
//     2) move needle
    float moveNeedle(float needleLocation, float moveAmount);    // return new location
//     3) change pitch adjust percentage
    float changePitchAdjust(float changeAmount);                // return new pitch adjust amount
};
/*
Thing 8) radio
5 properties:
    1) fm channel (float)
    2) am channel (int)
    3) satellite station (int)
    4) channel preset (int)
    5) current signal strength (float)
3 things it can do:
    1) change channel
    2) demodulate broadcast wave
    3) change wave type (am/fm/xm)
*/
struct Radio
{
//     1) fm channel (float)
    float fmChannel = 97.1f;
//     2) am channel (int)
    int amChannel = 540;
//     3) satellite station (int)
    int satChannel = 55;
//     4) channel preset (int)
    int channelPreset = 1;
//     5) current signal strength (float)
    float broadcastSignalStrengthPercent = 100.0f;
// 3 things it can do:
//     1) change channel
    void changeChannel(float targetChannel);
//     2) demodulate broadcast wave
    void demodulateBroadcastWave(float wave);
//     3) change wave type (am/fm/xm)
    void changeWaveListenedType(int targetWave);
};
/*
Thing 9) cd changer
5 properties:
    1) current number of cds in changer (int)
    2) max number of cds (int)
    3) current track number (int)
    4) current track name (std::string)
    5) current cd in reader (std::string)
3 things it can do:
    1) play cd
    2) change track
    3) pause playback
*/
struct CdChanger
{
//     1) current number of cds in changer (int)
    int numDiscsInChanger = 0;
//     2) max number of cds (int)
    int maxNumDiscsInChanger = 32;
//     3) current track number (int)
    int currTrackNumber = 1;
//     4) current track name (std::string)
    std::string currentTrackName = "Sister Christian";
//     5) current cd in reader (std::string)
    std::string currentDisc = "Midnight Madness";
// 3 things it can do:
//     1) play cd
    void playCD(int newCdNumber);
//     2) change track
    void changeTrack (int newTrackNumber);
//     3) pause playback
    void pausePlayback();
};
/*
Thing 10) Home stereo
5 properties:
    1) receiver
    2) speakers
    3) turntable
    4) radio
    5) cd changer
3 things it can do:
    1) play music
    2) change FM channel
    3) play backwards (to find the devil's music)
*/
struct HomeStereo
{
//     1) receiver
    Receiver receiver;
//     2) speakers
    Speakers speakers;
//     3) turntable
    Turntable turntable;
//     4) radio
    Radio radio;
//     5) cd changer
    CdChanger cdChanger;
// 3 things it can do:
//     1) play music
    void playMusic();
//     2) change FM channel
    void changeFmChannel(float newFmChannel, Radio radio);
//     3) play backwards (to find the devil's music)
    void playInReverse(Turntable attachedTurntable);
};








int main()
{
    std::cout << "good to go!" << std::endl;
}
