// -----------------------------------------------------------------------------
//  G4_QPIX | ConfigManager.h
//
//
//   * Author: Everybody is an author!
//   * Creation date: 18 Nov 2022
// -----------------------------------------------------------------------------

#ifndef CONFIG_MANAGER_H
#define CONFIG_MANAGER_H 

// Class Includes

// Package Includes

// Geant Includes
#include "G4Types.hh"
#include "G4String.hh"
#include "G4ThreeVector.hh"

// System Includes

// Forward Declarations
class G4GenericMessenger;


class ConfigManager {
  public:

    // Thread-specific instance for use with Get/Set functions
    static ConfigManager* Instance();

    ConfigManager();
    ConfigManager(const ConfigManager&);
    ~ConfigManager();
    
    void CreateCommands();


    // Access current values
    static G4int         GetEventIDOffset()                 { return Instance()->eventIDOffset_; }
    static G4double      GetEnergyThreshold()               { return Instance()->energyThreshold_; }
    static G4String      GetParticleType()                  { return Instance()->particleType_; }
    static G4bool        GetDecayAtTimeZero()               { return Instance()->decayAtTimeZero_; }
    static G4bool        GetIsotropic()                     { return Instance()->isotropic_; }
    static G4bool        GetOverrideVertexPosition()        { return Instance()->overrideVertexPosition_; }
    static G4bool        GetPrintParticleInfo()             { return Instance()->printParticleInfo_; }
    static G4String      GetInputFile()                     { return Instance()->inputFile_; }
    static G4String      GetOutputFile()                    { return Instance()->outputFile_; }
    static G4String      GetMarleyJson()                    { return Instance()->marleyJson_; }
    static G4String      GetGenerator()                     { return Instance()->generator_; }
    static G4String      GetGenieFormat()                   { return Instance()->genieFormat_; }
    static G4bool        GetMultirun()                      { return Instance()->multirun_; }
    static G4ThreeVector GetMomentumDirection()             { return Instance()->momentumDirection_; }
    static G4double      GetVertexX()                       { return Instance()->vertexX_; }
    static G4double      GetVertexY()                       { return Instance()->vertexY_; }
    static G4double      GetVertexZ()                       { return Instance()->vertexZ_; }
    static G4int         GetNAr39Decays()                   { return Instance()->nAr39Decays_; }
    static G4int         GetNAr42Decays()                   { return Instance()->nAr42Decays_; }
    static G4int         GetNAt215Decays()                   { return Instance()->nAt215Decays_; }
    static G4int         GetNAt218Decays()                   { return Instance()->nAt218Decays_; }
    static G4int         GetNKr85Decays()                   { return Instance()->nKr85Decays_; }
    static G4int         GetNCo60Decays()                   { return Instance()->nCo60Decays_; }
    static G4int         GetNK40Decays()                    { return Instance()->nK40Decays_; }
    static G4int         GetNK42Decays()                    { return Instance()->nK42Decays_; }
    static G4int         GetNBi209Decays()                   { return Instance()->nBi209Decays_; }
    static G4int         GetNBi210Decays()                   { return Instance()->nBi210Decays_; }
    static G4int         GetNBi211Decays()                  { return Instance()->nBi211Decays_; }
    static G4int         GetNBi212Decays()                  { return Instance()->nBi212Decays_; }
    static G4int         GetNBi214Decays()                  { return Instance()->nBi214Decays_; }
    static G4int         GetNHg206Decays()                   { return Instance()->nHg206Decays_; }
    static G4int         GetNPb209Decays()                   { return Instance()->nPb209Decays_; }
    static G4int         GetNPb210Decays()                   { return Instance()->nPb210Decays_; }
    static G4int         GetNPb211Decays()                   { return Instance()->nPb211Decays_; }
    static G4int         GetNPb212Decays()                   { return Instance()->nPb212Decays_; }
    static G4int         GetNPb206Decays()                   { return Instance()->nPb206Decays_; }
    static G4int         GetNPb214Decays()                  { return Instance()->nPb214Decays_; }
    static G4int         GetNPo210Decays()                  { return Instance()->nPo210Decays_; }
    static G4int         GetNPo211Decays()                  { return Instance()->nPo211Decays_; }
    static G4int         GetNPo212Decays()                  { return Instance()->nPo212Decays_; }
    static G4int         GetNPo214Decays()                  { return Instance()->nPo214Decays_; }
    static G4int         GetNPo215Decays()                  { return Instance()->nPo215Decays_; }
    static G4int         GetNPo216Decays()                  { return Instance()->nPo216Decays_; }
    static G4int         GetNPo218Decays()                  { return Instance()->nPo218Decays_; }
    static G4int         GetNRn218Decays()                   { return Instance()->nRn218Decays_; }
    static G4int         GetNRn219Decays()                  { return Instance()->nRn219Decays_; }
    static G4int         GetNRn220Decays()                  { return Instance()->nRn220Decays_; }
    static G4int         GetNRn222Decays()                  { return Instance()->nRn222Decays_; }
    static G4int         GetNTl206Decays()                   { return Instance()->nTl206Decays_; }
    static G4int         GetNTl207Decays()                   { return Instance()->nTl207Decays_; }
    static G4int         GetNTl208Decays()                   { return Instance()->nTl208Decays_; }
    static G4int         GetNTl210Decays()                   { return Instance()->nTl210Decays_; }
    static G4int         GetNTo206Decays()                   { return Instance()->nTo206Decays_; }
    static G4double      GetEventCutoff()                   { return Instance()->eventCutoff_; }
    static G4double      GetEventWindow()                   { return Instance()->eventWindow_; }
    static G4bool        GetSNTimingOn()                    { return Instance()->snTimingOn_; }
    static G4String      GetTh2Name()                       { return Instance()->th2Name_; }
    static const G4String&  GetDetectorConfiguration()      { return Instance()->detectorConfiguration_; }
    static G4double      GetDetectorLength()                { return Instance()->detectorLength_; }
    static G4double      GetDetectorWidth()                 { return Instance()->detectorWidth_; }
    static G4double      GetDetectorHeight()                { return Instance()->detectorHeight_; }

    // Change values (e.g. via Messenger) -- pass strings by value for toLower()
    static void SetEventIDOffset(G4int value)               { Instance()->eventIDOffset_ = value; }
    static void SetEnergyThreshold(G4double value)          { Instance()->energyThreshold_ = value; }
    static void SetParticleType(G4String value)             { Instance()->particleType_ = value; }
    static void SetDecayAtTimeZero(G4bool value)            { Instance()->decayAtTimeZero_ = value; }
    static void SetIsotropic(G4bool value)                  { Instance()->isotropic_ = value; }
    static void SetOverrideVertexPosition(G4bool value)     { Instance()->overrideVertexPosition_ = value; }
    static void SetPrintParticleInfo(G4bool value)          { Instance()->printParticleInfo_ = value; }
    static void SetInputFile(G4String value)                { Instance()->inputFile_ = value; }
    static void SetOutputFile(G4String value)               { Instance()->outputFile_= value; }
    static void SetMarleyJson(G4String value)               { Instance()->marleyJson_= value; }
    static void SetGenerator(G4String value)                { Instance()->generator_ = value; }
    static void SetGenieFormat(G4String value)              { Instance()->genieFormat_ = value; }
    static void SetMultirun(G4bool value)                   { Instance()->multirun_ = value; }
    static void SetMomentumDirection(G4ThreeVector value)   { Instance()->momentumDirection_ = value; }
    static void SetVertexX(G4double value)                  { Instance()->vertexX_ = value; }
    static void SetVertexY(G4double value)                  { Instance()->vertexY_ = value; }
    static void SetVertexZ(G4double value)                  { Instance()->vertexZ_ = value; }
    static void SetNAr39Decays(G4int value)                 { Instance()->nAr39Decays_ = value; }
    static void SetNAr42Decays(G4int value)                 { Instance()->nAr42Decays_ = value; }
    static void SetNKr85Decays(G4int value)                 { Instance()->nKr85Decays_ = value; }
    static void SetNCo60Decays(G4int value)                 { Instance()->nCo60Decays_ = value; }
    static void SetNK40Decays(G4int value)                  { Instance()->nK40Decays_ = value; }
    static void SetNK42Decays(G4int value)                  { Instance()->nK42Decays_ = value; }
    static void SetNAt215Decays(G4int value)                { Instance()->nAt215Decays_ = value; }
    static void SetNAt218Decays(G4int value)                { Instance()->nAt218Decays_ = value; }
    static void SetNBi209Decays(G4int value)                { Instance()->nBi209Decays_ = value; }
    static void SetNBi210Decays(G4int value)                { Instance()->nBi210Decays_ = value; }
    static void SetNBi211Decays(G4int value)                { Instance()->nBi211Decays_ = value; }
    static void SetNBi212Decays(G4int value)                { Instance()->nBi212Decays_ = value; }
    static void SetNBi214Decays(G4int value)                { Instance()->nBi214Decays_ = value; }
    static void SetNHg206Decays(G4int value)                { Instance()->nHg206Decays_ = value; }
    static void SetNPb210Decays(G4int value)                { Instance()->nPb210Decays_ = value; }
    static void SetNPb211Decays(G4int value)                { Instance()->nPb211Decays_ = value; }
    static void SetNPb212Decays(G4int value)                { Instance()->nPb212Decays_ = value; }
    static void SetNPb214Decays(G4int value)                { Instance()->nPb214Decays_ = value; }
    static void SetNPo210Decays(G4int value)                { Instance()->nPo210Decays_ = value; }
    static void SetNPo211Decays(G4int value)                { Instance()->nPo211Decays_ = value; }
    static void SetNPo212Decays(G4int value)                { Instance()->nPo212Decays_ = value; }
    static void SetNPo214Decays(G4int value)                { Instance()->nPo214Decays_ = value; }
    static void SetNPo215Decays(G4int value)                { Instance()->nPo215Decays_ = value; }
    static void SetNPo216Decays(G4int value)                { Instance()->nPo216Decays_ = value; }
    static void SetNPo218Decays(G4int value)                { Instance()->nPo218Decays_ = value; }
    static void SetNRn218Decays(G4int value)                { Instance()->nRn218Decays_ = value; }
    static void SetNRn219Decays(G4int value)                { Instance()->nRn219Decays_ = value; }
    static void SetNRn220Decays(G4int value)                { Instance()->nRn220Decays_ = value; }
    static void SetNRn222Decays(G4int value)                { Instance()->nRn222Decays_ = value; }
    static void SetNTl206Decays(G4int value)                { Instance()->nTl206Decays_ = value; }
    static void SetNTl207Decays(G4int value)                { Instance()->nTl207Decays_ = value; }
    static void SetNTl208Decays(G4int value)                { Instance()->nTl208Decays_ = value; }
    static void SetNTl210Decays(G4int value)                { Instance()->nTl210Decays_ = value; }
    static void SetEventCutoff(G4double value)              { Instance()->eventCutoff_ = value; }
    static void SetEventWindow(G4double value)              { Instance()->eventWindow_ = value; }
    static void SetSNTimingOn(G4bool value)                 { Instance()->snTimingOn_ = value; }
    static void SetTh2Name(G4String value)                  { Instance()->th2Name_ = value; }            
    static void SetDetectorConfiguration(const G4String& value)   { Instance()->detectorConfiguration_ = value; }
    static void SetDetectorLength(G4double value)           { Instance()->detectorLength_ = value; }
    static void SetDetectorWidth(G4double value)            { Instance()->detectorWidth_ = value; }
    static void SetDetectorHeight(G4double value)           { Instance()->detectorHeight_ = value; }

    // Print out all configuration settings
    static void Print() { Instance()->PrintConfig(); }
    void PrintConfig() const;

  private:
    // All messengers
    G4GenericMessenger* msgEvent_;
    G4GenericMessenger* msgInputs_;
    G4GenericMessenger* msgSupernova_;
    G4GenericMessenger* msgSupernovaTiming_;
    G4GenericMessenger* msgGeometry_;


  private:
    // msgEvent variables
    G4int         eventIDOffset_;
    G4double      energyThreshold_;

    // msgInputs variables
    G4String      particleType_;
    G4bool        decayAtTimeZero_;
    G4bool        isotropic_;
    G4bool        overrideVertexPosition_;
    G4bool        printParticleInfo_;
    G4String      inputFile_;
    G4String      outputFile_;
    G4String      marleyJson_;
    G4String      generator_;
    G4String      genieFormat_;
    G4bool        multirun_;
    G4ThreeVector momentumDirection_;
    G4double      vertexX_;
    G4double      vertexY_;
    G4double      vertexZ_;

    // msgSupernova variables
    G4int         nAt215Decays_;
    G4int         nAt218Decays_;
    G4int         nAr39Decays_;
    G4int         nAr42Decays_;
    G4int         nKr85Decays_;
    G4int         nCo60Decays_;
    G4int         nHg206Decays_;
    G4int         nK40Decays_;
    G4int         nK42Decays_;
    G4int         nBi209Decays_;
    G4int         nBi210Decays_;
    G4int         nBi211Decays_;
    G4int         nBi212Decays_;
    G4int         nBi214Decays_;
    G4int         nPb206Decays_;
    G4int         nPb209Decays_;
    G4int         nPb210Decays_;
    G4int         nPb211Decays_;
    G4int         nPb212Decays_;
    G4int         nPb214Decays_;
    G4int         nPo210Decays_;
    G4int         nPo211Decays_;
    G4int         nPo212Decays_;
    G4int         nPo214Decays_;
    G4int         nPo215Decays_;
    G4int         nPo216Decays_;
    G4int         nPo218Decays_;
    G4int         nRn218Decays_;
    G4int         nRn219Decays_;
    G4int         nRn220Decays_;
    G4int         nRn222Decays_;
    G4int         nTl206Decays_;
    G4int         nTl207Decays_;
    G4int         nTl208Decays_;
    G4int         nTl210Decays_;
    G4int         nTo206Decays_;
    G4double      eventCutoff_;
    G4double      eventWindow_;

    // msgSupernovaTiming variables
    G4bool        snTimingOn_;
    G4String      th2Name_;

    // msgGeometry variables
    G4String      detectorConfiguration_;
    G4double      detectorLength_;
    G4double      detectorWidth_;
    G4double      detectorHeight_;
};
#endif
