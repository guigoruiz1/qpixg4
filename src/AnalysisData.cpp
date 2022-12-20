// -----------------------------------------------------------------------------
//  AnalysisData.cpp
//
//  Class definition of the AnalysisData (second part of AnalysisManager)
//   * Author: Everybody is an author!
//   * Creation date: 20 Dec 2022
// -----------------------------------------------------------------------------

// QPix includes
#include "AnalysisData.h"

// Geant4 includes
#include "G4AutoLock.hh"


//-----------------------------------------------------------------------------
AnalysisData::AnalysisData()
{
#ifdef G4ANALYSIS_USE
#endif
}

//-----------------------------------------------------------------------------
AnalysisData::~AnalysisData()
{
#ifdef G4ANALYSIS_USE
#endif
}

//-----------------------------------------------------------------------------
void AnalysisData::EventReset()
{
  // reset event variables after filling TTree objects per event
  event_ = -1;
  number_particles_ = 0;

  generator_initial_number_particles_ = 0;
  generator_initial_particle_x_.clear();
  generator_initial_particle_y_.clear();
  generator_initial_particle_z_.clear();
  generator_initial_particle_t_.clear();
  generator_initial_particle_px_.clear();
  generator_initial_particle_py_.clear();
  generator_initial_particle_pz_.clear();
  generator_initial_particle_energy_.clear();
  generator_initial_particle_pdg_code_.clear();
  generator_initial_particle_mass_.clear();
  generator_initial_particle_charge_.clear();

  generator_final_number_particles_ = 0;
  generator_final_particle_x_.clear();
  generator_final_particle_y_.clear();
  generator_final_particle_z_.clear();
  generator_final_particle_t_.clear();
  generator_final_particle_px_.clear();
  generator_final_particle_py_.clear();
  generator_final_particle_pz_.clear();
  generator_final_particle_energy_.clear();
  generator_final_particle_pdg_code_.clear();
  generator_final_particle_mass_.clear();
  generator_final_particle_charge_.clear();

  number_hits_ = 0;
  energy_deposit_ = 0;

  particle_track_id_.clear();
  particle_parent_track_id_.clear();
  particle_pdg_code_.clear();
  particle_mass_.clear();
  particle_charge_.clear();
  particle_process_key_.clear();
  particle_total_occupancy_.clear();

  particle_number_daughters_.clear();
  particle_daughter_track_ids_.clear();

  particle_initial_x_.clear();
  particle_initial_y_.clear();
  particle_initial_z_.clear();
  particle_initial_t_.clear();

  particle_initial_px_.clear();
  particle_initial_py_.clear();
  particle_initial_pz_.clear();
  particle_initial_energy_.clear();

  hit_track_id_.clear();
  hit_start_x_.clear();
  hit_start_y_.clear();
  hit_start_z_.clear();
  hit_start_t_.clear();
  hit_end_x_.clear();
  hit_end_y_.clear();
  hit_end_z_.clear();
  hit_end_t_.clear();
  hit_energy_deposit_.clear();
  hit_length_.clear();
  hit_process_key_.clear();
}

//-----------------------------------------------------------------------------
void AnalysisData::SetRun(int const value)
{
  run_ = value;
}

//-----------------------------------------------------------------------------
void AnalysisData::SetEvent(int const value)
{
  event_ = value;
}

//-----------------------------------------------------------------------------
void AnalysisData::AddInitialGeneratorParticle(GeneratorParticle const * particle)
{
  generator_initial_number_particles_ += 1;
  generator_initial_particle_pdg_code_.push_back(particle->PDGCode());
  generator_initial_particle_mass_.push_back(particle->Mass());
  generator_initial_particle_charge_.push_back(particle->Charge());
  generator_initial_particle_x_.push_back(particle->X());
  generator_initial_particle_y_.push_back(particle->Y());
  generator_initial_particle_z_.push_back(particle->Z());
  generator_initial_particle_t_.push_back(particle->T());
  generator_initial_particle_px_.push_back(particle->Px());
  generator_initial_particle_py_.push_back(particle->Py());
  generator_initial_particle_pz_.push_back(particle->Pz());
  generator_initial_particle_energy_.push_back(particle->Energy());
}

//-----------------------------------------------------------------------------
void AnalysisData::AddFinalGeneratorParticle(GeneratorParticle const * particle)
{
  generator_final_number_particles_ += 1;
  generator_final_particle_pdg_code_.push_back(particle->PDGCode());
  generator_final_particle_mass_.push_back(particle->Mass());
  generator_final_particle_charge_.push_back(particle->Charge());
  generator_final_particle_x_.push_back(particle->X());
  generator_final_particle_y_.push_back(particle->Y());
  generator_final_particle_z_.push_back(particle->Z());
  generator_final_particle_t_.push_back(particle->T());
  generator_final_particle_px_.push_back(particle->Px());
  generator_final_particle_py_.push_back(particle->Py());
  generator_final_particle_pz_.push_back(particle->Pz());
  generator_final_particle_energy_.push_back(particle->Energy());
}

//-----------------------------------------------------------------------------
void AnalysisData::AddMCParticle(MCParticle const * particle)
{
  particle_track_id_.push_back(particle->TrackID());
  particle_parent_track_id_.push_back(particle->ParentTrackID());
  particle_pdg_code_.push_back(particle->PDGCode());
  particle_mass_.push_back(particle->Mass());
  particle_charge_.push_back(particle->Charge());
  particle_process_key_.push_back(this->ProcessToKey(particle->Process()));
  particle_total_occupancy_.push_back(particle->TotalOccupancy());

  particle_initial_x_.push_back(particle->InitialPosition().X());
  particle_initial_y_.push_back(particle->InitialPosition().Y());
  particle_initial_z_.push_back(particle->InitialPosition().Z());
  particle_initial_t_.push_back(particle->InitialPosition().T());

  particle_initial_px_.push_back(particle->InitialMomentum().X());
  particle_initial_py_.push_back(particle->InitialMomentum().Y());
  particle_initial_pz_.push_back(particle->InitialMomentum().Z());
  particle_initial_energy_.push_back(particle->InitialMomentum().E());

  particle_number_daughters_.push_back(particle->NumberDaughters());
  particle_daughter_track_ids_.push_back(particle->Daughters());

  number_particles_ += 1;

  std::vector< TrajectoryHit > const hits = particle->Hits();

  for (auto const & hit : hits)
  {
    energy_deposit_ += hit.Energy();

    hit_track_id_.push_back(hit.TrackID());

    hit_start_x_.push_back(hit.StartPoint().X());
    hit_start_y_.push_back(hit.StartPoint().Y());
    hit_start_z_.push_back(hit.StartPoint().Z());
    hit_start_t_.push_back(hit.StartTime());

    hit_end_x_.push_back(hit.EndPoint().X());
    hit_end_y_.push_back(hit.EndPoint().Y());
    hit_end_z_.push_back(hit.EndPoint().Z());
    hit_end_t_.push_back(hit.EndTime());

    hit_length_.push_back(hit.Length());
    hit_energy_deposit_.push_back(hit.Energy());

    hit_process_key_.push_back(this->ProcessToKey(hit.Process()));
    number_hits_ += 1;
    }
}

//-----------------------------------------------------------------------------
int AnalysisData::ProcessToKey(std::string const & process)
{
  int key = -2;

  if (process.compare("NoProcess")                 == 0) key = -1;
  else if (process.compare("primary")              == 0) key =  0;
  else if (process.compare("eIoni")                == 0) key =  1;
  else if (process.compare("msc")                  == 0) key =  2;
  else if (process.compare("compt")                == 0) key =  3;
  else if (process.compare("phot")                 == 0) key =  4;
  else if (process.compare("eBrem")                == 0) key =  5;
  else if (process.compare("ionIoni")              == 0) key =  6;
  else if (process.compare("hIoni")                == 0) key =  7;
  else if (process.compare("RadioactiveDecayBase") == 0) key =  8;
  else if (process.compare("CoulombScat")          == 0) key =  9;
  else if (process.compare("Rayl")                 == 0) key = 10;
  else if (process.compare("Transportation")       == 0) key = 11;
  else if (process.compare("annihil")              == 0) key = 12;
  else if (process.compare("conv")                 == 0) key = 13;
  else if (process.compare("hadElastic")           == 0) key = 14;
  else if (process.compare("nCapture")             == 0) key = 15;
  else if (process.compare("neutronInelastic")     == 0) key = 16;
  else if (process.compare("photonNuclear")        == 0) key = 17;
  else if (process.compare("protonInelastic")      == 0) key = 18;
  else if (process.compare("dInelastic")           == 0) key = 19;
  else if (process.compare("Decay")                == 0) key = 20;
  else if (process.compare("RadioactiveDecay")     == 0) key = 21;
  else { std::cout << "Uncategorized process: " << process << std::endl; }

  return key;
}

