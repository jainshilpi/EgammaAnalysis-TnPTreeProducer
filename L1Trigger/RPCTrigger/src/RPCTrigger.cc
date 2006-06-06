/** \file RPCTrigger.cc
 *
 *  $Date: 2006/05/30 18:48:40 $
 *  $Revision: 1.3 $
 *  \author Tomasz Fruboes
 */


#include <memory>

// user include files
#include "FWCore/Framework/interface/Frameworkfwd.h"
#include "FWCore/Framework/interface/EDProducer.h"

#include "FWCore/Framework/interface/Event.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "FWCore/ParameterSet/interface/ParameterSet.h"

#include <FWCore/Framework/interface/ESHandle.h> // Handle to read geometry

#include "DataFormats/MuonDetId/interface/RPCDetId.h"
#include "DataFormats/RPCDigi/interface/RPCDigiCollection.h"


#include "Geometry/RPCGeometry/interface/RPCGeometry.h"
#include "Geometry/Records/interface/MuonGeometryRecord.h"

// L1RpcTrigger specific includes
#include "L1Trigger/RPCTrigger/interface/RPCTrigger.h"
#include "L1Trigger/RPCTrigger/src/RPCTriggerGeo.h"

RPCTrigger::RPCTrigger(const edm::ParameterSet& iConfig)
{
   // The data formats are not ready yet (V 2006), so we `produce` a fake data
   // to be able to run
  produces<int>("FakeTemp");
  
  
  
  //
  

}


RPCTrigger::~RPCTrigger(){ }



void
RPCTrigger::produce(edm::Event& iEvent, const edm::EventSetup& iSetup)
{
  
  // Build the trigger linksystem geometry;
  if (!theLinksystem.isGeometryBuilt()){

    edm::ESHandle<RPCGeometry> rpcGeom;
    iSetup.get<MuonGeometryRecord>().get( rpcGeom );     
    theLinksystem.buildGeometry(rpcGeom);

  } 

  // Get RpcDigi`s
  edm::Handle<RPCDigiCollection> rpcDigis;
  iEvent.getByType(rpcDigis);
   
  // Build cones from digis

}

//define this as a plug-in
DEFINE_FWK_MODULE(RPCTrigger)
