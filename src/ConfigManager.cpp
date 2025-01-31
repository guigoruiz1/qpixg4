// -----------------------------------------------------------------------------
//  ConfigManager.cpp
//
//  Class definition of the ConfigManager Singleton Container
//   * Author: Everybody is an author!
//   * Creation date: 18 November 2022
// -----------------------------------------------------------------------------

// Class Includes
#include "ConfigManager.h"

// Geant Includes
#include "globals.hh"
#include "G4GenericMessenger.hh"
#include "G4Threading.hh"
#include "G4ThreeVector.hh"
#include "CLHEP/Units/SystemOfUnits.h"

// System Includes
#include <fstream>
#include <iostream>
#include <typeinfo>
#include <float.h>
#include <stdlib.h>

//-----------------------------------------------------------------------------
// Singleton Initializers for master and worker threads
ConfigManager* ConfigManager::Instance() {
  static const ConfigManager* masterInstance = 0;
  static G4ThreadLocal ConfigManager* theInstance = 0;

  if (!theInstance) {
    if (!G4Threading::IsWorkerThread()) {   // Master or sequential
      theInstance = new ConfigManager;
      masterInstance = theInstance;
    } else {                    // Workers copy from master
      theInstance = new ConfigManager(*masterInstance);
    }
  }
  return theInstance;
}

//-----------------------------------------------------------------------------
ConfigManager::ConfigManager()
  : eventIDOffset_(0), energyThreshold_(0),
  particleType_(""), decayAtTimeZero_(false), isotropic_(true),
  overrideVertexPosition_(false), printParticleInfo_(false), inputFile_(""), outputFile_(""), marleyJson_(""), generator_(""),
  genieFormat_(""), multirun_(false), momentumDirection_(0,0,0), vertexX_(2.3*CLHEP::m/2), vertexY_(6.0*CLHEP::m/2), vertexZ_(3.7*CLHEP::m/2),
  nAt215Decays_(0), 
  nAt218Decays_(0), 
  nAr39Decays_(0), 
  nAr42Decays_(0), 
  nKr85Decays_(0), 
  nCo60Decays_(0), 
  nHg206Decays_(0), 
  nK40Decays_(0),
  nK42Decays_(0), 
  nBi209Decays_(0),
  nBi210Decays_(0),
  nBi211Decays_(0),
  nBi212Decays_(0),
  nBi214Decays_(0),
  nPb206Decays_(0),
  nPb209Decays_(0), 
  nPb210Decays_(0),
  nPb211Decays_(0),
  nPb212Decays_(0), 
  nPb214Decays_(0), 
  nPo210Decays_(0), 
  nPo211Decays_(0), 
  nPo214Decays_(0), 
  nPo215Decays_(0), 
  nPo216Decays_(0), 
  nPo218Decays_(0), 
  nRn218Decays_(0), 
  nRn219Decays_(0), 
  nRn220Decays_(0), 
  nRn222Decays_(0),
  nTl207Decays_(0), 
  nTl208Decays_(0), 
  nTl210Decays_(0),
  nTo206Decays_(0), 
  eventCutoff_(0),
  eventWindow_(0),
  snTimingOn_(false), th2Name_("nusperbin2d_nue"),
  detectorConfiguration_("HD"),
  detectorLength_(0), detectorWidth_(0), detectorHeight_(0)
{
  CreateCommands();
}

//-----------------------------------------------------------------------------
ConfigManager::ConfigManager(const ConfigManager& master)
  : eventIDOffset_(master.eventIDOffset_),
  energyThreshold_(master.energyThreshold_),
  particleType_(master.particleType_),
  decayAtTimeZero_(master.decayAtTimeZero_), isotropic_(master.isotropic_),
  overrideVertexPosition_(master.overrideVertexPosition_),
  printParticleInfo_(master.printParticleInfo_), inputFile_(master.inputFile_),
  outputFile_(master.outputFile_), marleyJson_(master.marleyJson_),
  generator_(master.generator_), genieFormat_(master.genieFormat_),
  multirun_(master.multirun_), momentumDirection_(master.momentumDirection_),
  vertexX_(master.vertexX_), vertexY_(master.vertexY_),
  vertexZ_(master.vertexZ_),
  nAt215Decays_(master.nAt215Decays_),
  nAt218Decays_(master.nAt218Decays_),
  nAr39Decays_(master.nAr39Decays_), 
  nAr42Decays_(master.nAr42Decays_),
  nKr85Decays_(master.nKr85Decays_), 
  nCo60Decays_(master.nCo60Decays_),
  nK40Decays_(master.nK40Decays_), 
  nK42Decays_(master.nK42Decays_),
  nBi209Decays_(master.nBi209Decays_),
  nBi210Decays_(master.nBi210Decays_),
  nBi211Decays_(master.nBi211Decays_),
  nBi212Decays_(master.nBi212Decays_), 
  nBi214Decays_(master.nBi214Decays_), 
  nHg206Decays_(master.nHg206Decays_), 
  nPb209Decays_(master.nPb209Decays_),
  nPb210Decays_(master.nPb210Decays_),
  nPb211Decays_(master.nPb211Decays_),
  nPb212Decays_(master.nPb212Decays_),
  nPb214Decays_(master.nPb214Decays_),
  nPo210Decays_(master.nPo210Decays_), 
  nPo211Decays_(master.nPo211Decays_), 
  nPo212Decays_(master.nPo212Decays_), 
  nPo214Decays_(master.nPo214Decays_), 
  nPo215Decays_(master.nPo215Decays_), 
  nPo216Decays_(master.nPo216Decays_), 
  nPo218Decays_(master.nPo218Decays_), 
  nRn218Decays_(master.nRn218Decays_),
  nRn219Decays_(master.nRn219Decays_),
  nRn220Decays_(master.nRn220Decays_),
  nRn222Decays_(master.nRn222Decays_),
  nTl206Decays_(master.nTl206Decays_),
  nTl207Decays_(master.nTl207Decays_),
  nTl208Decays_(master.nTl208Decays_),
  nTl210Decays_(master.nTl210Decays_),
  nTo206Decays_(master.nTo206Decays_),
  eventCutoff_(master.eventCutoff_), eventWindow_(master.eventWindow_),
  snTimingOn_(master.snTimingOn_), th2Name_(master.th2Name_),
  detectorConfiguration_(master.detectorConfiguration_), 
  detectorLength_(master.detectorLength_), detectorWidth_(master.detectorWidth_), detectorHeight_(master.detectorHeight_)
{
  CreateCommands();
}

//-----------------------------------------------------------------------------
ConfigManager::~ConfigManager()
{
  delete msgEvent_;
  delete msgInputs_;
  delete msgSupernova_;
  delete msgSupernovaTiming_;
  delete msgGeometry_;
}

//-----------------------------------------------------------------------------
void ConfigManager::CreateCommands()
{
  // Instantiate all messengers
  msgEvent_ = new G4GenericMessenger(this, "/event/", "user-defined event configuration");
  msgInputs_ = new G4GenericMessenger(this, "/inputs/", "Control commands of the ion primary generator.");
  msgSupernova_ = new G4GenericMessenger(this, "/supernova/", "Control commands of the supernova generator.");
  msgSupernovaTiming_ = new G4GenericMessenger(this, "/supernova/timing/", "control commands for SupernovaTiming");
  msgGeometry_ = new G4GenericMessenger(this, "/geometry/", "control commands for DetectorConstruction");

  // Declare all properties for msgEvent
  msgEvent_->DeclareProperty("offset", eventIDOffset_, "Event ID offset.");
  msgEvent_->DeclarePropertyWithUnit("energy_threshold", "MeV", energyThreshold_, "Events that deposit less energy than this energy threshold will not be saved.");

  // Declare all properties for msgInputs
  msgInputs_->DeclareProperty("particle_type", particleType_,  "which kind of particle?");
  msgInputs_->DeclareProperty("decay_at_time_zero", decayAtTimeZero_, "Set to true to make unstable isotopes decay at t=0.");
  msgInputs_->DeclareProperty("isotropic", isotropic_, "isotropic");
  msgInputs_->DeclareProperty("override_vertex_position", overrideVertexPosition_, "override vertex position");
  msgInputs_->DeclareProperty("print_particle_info", printParticleInfo_, "Extra Printing for Debugging");
  msgInputs_->DeclareProperty("input_file", inputFile_, "input ROOT file");
  msgInputs_->DeclareProperty("output_file", outputFile_, "output ROOT file");
  msgInputs_->DeclareProperty("MARLEY_json", marleyJson_, "marley config json file");
  msgInputs_->DeclareProperty("generator", generator_, "event generator of input file");
  msgInputs_->DeclareProperty("multirun", multirun_, "multiple runs");
  msgInputs_->DeclareProperty("genie_format", genieFormat_, "format of genie-produced input file");
  msgInputs_->DeclareProperty("momentum_direction", momentumDirection_, "initial momentum of generator particles");

  msgInputs_->DeclarePropertyWithUnit("vertex_x", "mm", vertexX_, "vertex x");
  msgInputs_->DeclarePropertyWithUnit("vertex_y", "mm", vertexY_, "vertex y");
  msgInputs_->DeclarePropertyWithUnit("vertex_z", "mm", vertexZ_, "vertex z");

  // Declare all properties for msgSupernova
  msgSupernova_->DeclareProperty("N_Ar39_Decays", nAr39Decays_,  "number of Ar39 decays");
  msgSupernova_->DeclareProperty("N_Ar42_Decays", nAr42Decays_,  "number of Ar42 decays");
  msgSupernova_->DeclareProperty("N_At215_Decays", nAt218Decays_,  "number of At215 decays");
  msgSupernova_->DeclareProperty("N_At218_Decays", nAt218Decays_,  "number of At218 decays");
  msgSupernova_->DeclareProperty("N_Kr85_Decays", nKr85Decays_,  "number of Kr85 decays");
  msgSupernova_->DeclareProperty("N_Co60_Decays", nCo60Decays_,  "number of Co60 decays");
  msgSupernova_->DeclareProperty("N_Hg206_Decays", nHg206Decays_,  "number of Hg206 decays");
  msgSupernova_->DeclareProperty("N_K40_Decays", nK40Decays_,  "number of K40 decays");
  msgSupernova_->DeclareProperty("N_K42_Decays", nK42Decays_,  "number of K42 decays");
  msgSupernova_->DeclareProperty("N_Bi209_Decays", nBi209Decays_,  "number of Bi209 decays");
  msgSupernova_->DeclareProperty("N_Bi210_Decays", nBi210Decays_,  "number of Bi210 decays");
  msgSupernova_->DeclareProperty("N_Bi211_Decays", nBi211Decays_,  "number of Bi211 decays");
  msgSupernova_->DeclareProperty("N_Bi212_Decays", nBi209Decays_,  "number of Bi212 decays");
  msgSupernova_->DeclareProperty("N_Bi214_Decays", nBi214Decays_,  "number of Bi214 decays");
  msgSupernova_->DeclareProperty("N_Pb206_Decays", nPb206Decays_,  "number of Pb206 decays");
  msgSupernova_->DeclareProperty("N_Pb209_Decays", nPb209Decays_,  "number of Pb209 decays");
  msgSupernova_->DeclareProperty("N_Pb210_Decays", nPb210Decays_,  "number of Pb210 decays");
  msgSupernova_->DeclareProperty("N_Pb211_Decays", nPb211Decays_,  "number of Pb211 decays");
  msgSupernova_->DeclareProperty("N_Pb212_Decays", nPb212Decays_,  "number of Pb212 decays");
  msgSupernova_->DeclareProperty("N_Pb214_Decays", nPb214Decays_,  "number of Pb214 decays");
  msgSupernova_->DeclareProperty("N_Po210_Decays", nPo210Decays_,  "number of Po210 decays");
  msgSupernova_->DeclareProperty("N_Po211_Decays", nPo211Decays_,  "number of Po211 decays");
  msgSupernova_->DeclareProperty("N_Po212_Decays", nPo212Decays_,  "number of Po212 decays");
  msgSupernova_->DeclareProperty("N_Po214_Decays", nPo214Decays_,  "number of Po214 decays");
  msgSupernova_->DeclareProperty("N_Po215_Decays", nPo215Decays_,  "number of Po215 decays");
  msgSupernova_->DeclareProperty("N_Po216_Decays", nPo216Decays_,  "number of Po216 decays");
  msgSupernova_->DeclareProperty("N_Po218_Decays", nPo218Decays_,  "number of Po218 decays");
  msgSupernova_->DeclareProperty("N_Rn218_Decays", nRn218Decays_,  "number of Rn218 decays");
  msgSupernova_->DeclareProperty("N_Rn219_Decays", nRn219Decays_,  "number of Rn219 decays");
  msgSupernova_->DeclareProperty("N_Rn220_Decays", nRn220Decays_,  "number of Rn220 decays");
  msgSupernova_->DeclareProperty("N_Rn222_Decays", nRn222Decays_,  "number of Rn222 decays");
  msgSupernova_->DeclareProperty("N_Tl206_Decays", nTl206Decays_,  "number of Tl206 decays");
  msgSupernova_->DeclareProperty("N_Tl207_Decays", nTl207Decays_,  "number of Tl207 decays");
  msgSupernova_->DeclareProperty("N_Tl208_Decays", nTl208Decays_,  "number of Tl208 decays");
  msgSupernova_->DeclareProperty("N_Tl210_Decays", nTl210Decays_,  "number of Tl210 decays");
  msgSupernova_->DeclareProperty("N_To206_Decays", nTo206Decays_,  "number of To206 decays");

  msgSupernova_->DeclarePropertyWithUnit("Event_Cutoff", "ns", eventCutoff_,  "window to simulate the times");
  msgSupernova_->DeclarePropertyWithUnit("Event_Window", "ns", eventWindow_,  "window to simulate the times");

  // Declare all properties for msgSupernovaTiming
  msgSupernovaTiming_->DeclareProperty("on", snTimingOn_, "turn on SupernovaTiming");
  msgSupernovaTiming_->DeclareProperty("th2_name", th2Name_, "name of TH2");

  // Declare all properties for msgGeometry
  msgGeometry_->DeclareProperty("detector_configuration", detectorConfiguration_, "detector configuration").SetCandidates("HD VD TS");
  msgGeometry_->DeclareProperty("detector_length", detectorLength_, "detector length");
  msgGeometry_->DeclareProperty("detector_width", detectorWidth_, "detector width");
  msgGeometry_->DeclareProperty("detector_height", detectorHeight_, "detector height");
}

//-----------------------------------------------------------------------------
void ConfigManager::PrintConfig() const
{
  G4cout << "EventAction -- Event_ID_Offset:    " << eventIDOffset_ << G4endl
     << "EventAction -- Energy_Threshold:   " << energyThreshold_ << G4endl
     << G4endl
     << "Input -- Generator:                " << generator_ << G4endl
     << "Input -- Genie Format:             " << genieFormat_ << G4endl
     << "Input -- Particle_Type:            " << particleType_ << G4endl
     << "Input -- Decay_At_Time_Zero:       " << decayAtTimeZero_ << G4endl
     << "Input -- Isotropic:                " << isotropic_ << G4endl
     << "Input -- Override_Vertex_Position: " << overrideVertexPosition_ << G4endl
     << "Input -- Print_Particle_Info:      " << printParticleInfo_ << G4endl
     << "Input -- Input_File:               " << inputFile_ << G4endl
     << "Input -- Output_File:              " << outputFile_ << G4endl
     << "Input -- MARLEY_json:              " << marleyJson_ << G4endl
     << "Input -- Momentum_Direction:       " << momentumDirection_ << G4endl
     << "Input -- Vertex_X:                 " << vertexX_/CLHEP::mm << " mm" << G4endl
     << "Input -- Vertex_Y:                 " << vertexY_/CLHEP::mm << " mm" <<  G4endl
     << "Input -- Vertex_Z:                 " << vertexZ_/CLHEP::mm << " mm" << G4endl
     << "Input -- Multirun:                 " << multirun_ << G4endl
     << G4endl
     << "Supernova -- N_At215_Decays:  " << nAt215Decays_ << G4endl
     << "Supernova -- N_At218_Decays:  " << nAt218Decays_ << G4endl
     << "Supernova -- N_Ar39_Decays:  " << nAr39Decays_ << G4endl
     << "Supernova -- N_Ar42_Decays:  " << nAr42Decays_ << G4endl
     << "Supernova -- N_Kr85_Decays:  " << nKr85Decays_ << G4endl
     << "Supernova -- N_Co60_Decays:  " << nCo60Decays_ << G4endl
     << "Supernova -- N_Hg206_Decays: " << nHg206Decays_ << G4endl
     << "Supernova -- N_K40_Decays:   " << nK40Decays_ << G4endl
     << "Supernova -- N_K42_Decays:   " << nK42Decays_ << G4endl
     << "Supernova -- N_Bi209_Decays: " << nBi209Decays_ << G4endl
     << "Supernova -- N_Bi210_Decays: " << nBi210Decays_ << G4endl
     << "Supernova -- N_Bi211_Decays: " << nBi211Decays_ << G4endl
     << "Supernova -- N_Bi212_Decays: " << nBi212Decays_ << G4endl
     << "Supernova -- N_Bi214_Decays: " << nBi214Decays_ << G4endl
     << "Supernova -- N_Pb206_Decays: " << nPb206Decays_ << G4endl
     << "Supernova -- N_Pb209_Decays: " << nPb209Decays_ << G4endl
     << "Supernova -- N_Pb210_Decays: " << nPb210Decays_ << G4endl
     << "Supernova -- N_Pb211_Decays: " << nPb211Decays_ << G4endl
     << "Supernova -- N_Pb212_Decays: " << nPb212Decays_ << G4endl
     << "Supernova -- N_Pb214_Decays: " << nPb214Decays_ << G4endl
     << "Supernova -- N_Po210_Decays: " << nPo210Decays_ << G4endl
     << "Supernova -- N_Po211_Decays: " << nPo211Decays_ << G4endl
     << "Supernova -- N_Po212_Decays: " << nPo212Decays_ << G4endl
     << "Supernova -- N_Po214_Decays: " << nPo214Decays_ << G4endl
     << "Supernova -- N_Po215_Decays: " << nPo215Decays_ << G4endl
     << "Supernova -- N_Po216_Decays: " << nPo216Decays_ << G4endl
     << "Supernova -- N_Po218_Decays: " << nPo218Decays_ << G4endl
     << "Supernova -- N_Rn218_Decays: " << nRn218Decays_ << G4endl
     << "Supernova -- N_Rn219_Decays: " << nRn219Decays_ << G4endl
     << "Supernova -- N_Rn220_Decays: " << nRn220Decays_ << G4endl
     << "Supernova -- N_Rn222_Decays: " << nRn222Decays_ << G4endl
     << "Supernova -- N_Tl206_Decays: " << nTl206Decays_ << G4endl
     << "Supernova -- N_Tl207_Decays: " << nTl207Decays_ << G4endl
     << "Supernova -- N_Tl208_Decays: " << nTl208Decays_ << G4endl
     << "Supernova -- N_Tl210_Decays: " << nTl210Decays_ << G4endl
     << "Supernova -- N_To206_Decays: " << nTo206Decays_ << G4endl
     << "Supernova -- Event_Cutoff:   " << eventCutoff_/CLHEP::ns << " ns" << G4endl
     << "Supernova -- Event_Window:   " << eventWindow_/CLHEP::ns << " ns" << G4endl
     << G4endl
     << "SupernovaTiming -- Supernova_Timing_On: " << snTimingOn_ << G4endl
     << "SupernovaTiming -- TH2_Name:            " << th2Name_ << G4endl
     << G4endl
     << "Geometry -- Detector_Configuration:        " << detectorConfiguration_ << G4endl
     << "Geometry -- Detector_Length:               " << detectorLength_/CLHEP::m << " m" << G4endl
     << "Geometry -- Detector_Width:                " << detectorWidth_/CLHEP::m << " m" << G4endl
     << "Geometry -- Detector_Height:               " << detectorHeight_/CLHEP::m << " m" <<G4endl
     << G4endl;
}
