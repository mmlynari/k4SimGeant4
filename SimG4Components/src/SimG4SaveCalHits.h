#ifndef SIMG4COMPONENTS_G4SAVECALHITS_H
#define SIMG4COMPONENTS_G4SAVECALHITS_H

// Gaudi
#include "GaudiAlg/GaudiTool.h"

// FCCSW
#include "FWCore/DataHandle.h"
#include "SimG4Interface/ISimG4SaveOutputTool.h"

// datamodel
namespace fcc {
class CaloClusterCollection;
class CaloHitCollection;
class CaloClusterHitsAssociationCollection;
}

/** @class SimG4SaveCalHits SimG4Components/src/SimG4SaveCalHits.h SimG4SaveCalHits.h
 *
 *  Save tracker hits tool.
 *
 *  @author Anna Zaborowska
 */

class SimG4SaveCalHits: public GaudiTool, virtual public ISimG4SaveOutputTool {
public:
  explicit SimG4SaveCalHits(const std::string& aType , const std::string& aName,
                  const IInterface* aParent);
  virtual ~SimG4SaveCalHits();
  /**  Initialize.
   *   @return status code
   */
  virtual StatusCode initialize();
  /**  Finalize.
   *   @return status code
   */
  virtual StatusCode finalize();
  /**  Save the data output.
   *   Saves the tracker hits and clusters from every hits collection associated with the event
   *   that has m_calType in its name.
   *   @param[in] aEvent Event with data to save.
   *   @return status code
   */
  virtual StatusCode saveOutput(const G4Event& aEvent) final;
private:
  /// Handle for calo clusters
  DataHandle<fcc::CaloClusterCollection> m_caloClusters;
  /// Handle for calo hits
  DataHandle<fcc::CaloHitCollection> m_caloHits;
  /// Name of the calorimeter type (ECal/HCal)
  std::string m_calType;

};

#endif /* SIMG4COMPONENTS_G4SAVECALHITS_H */
