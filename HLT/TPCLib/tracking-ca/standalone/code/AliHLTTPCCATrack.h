//-*- Mode: C++ -*-
// @(#) $Id: AliHLTTPCCATrack.h 31935 2009-04-13 20:57:12Z sgorbuno $
// ************************************************************************
// This file is property of and copyright by the ALICE HLT Project        *
// ALICE Experiment at CERN, All rights reserved.                         *
// See cxx source for full Copyright notice                               *
//                                                                        *
//*************************************************************************

#ifndef ALIHLTTPCCATRACK_H
#define ALIHLTTPCCATRACK_H

#include "AliHLTTPCCADef.h"
#include "AliHLTTPCCATrackParam.h"

/**
 * @class ALIHLTTPCCAtrack
 *
 * The class describes the [partially] reconstructed TPC track [candidate].
 * The class is dedicated for internal use by the AliHLTTPCCATracker algorithm.
 * The track parameters at both ends are stored separately in the AliHLTTPCCAEndPoint class
 */
class AliHLTTPCCATrack
{
  public:
#if !defined(HLTCA_GPUCODE)
    AliHLTTPCCATrack() : fAlive( 0 ), fFirstHitID( 0 ), fNHits( 0 ), fParam() {}
    ~AliHLTTPCCATrack() {}
#endif

    GPUhd() bool Alive()               const { return fAlive; }
    GPUhd() int  NHits()               const { return fNHits; }
    GPUhd() int  FirstHitID()          const { return fFirstHitID; }
    GPUhd() const AliHLTTPCCATrackParam &Param() const { return fParam; };

    GPUhd() void SetAlive( bool v )               { fAlive = v; }
    GPUhd() void SetNHits( int v )               { fNHits = v; }
    GPUhd() void SetFirstHitID( int v )          { fFirstHitID = v; }
    GPUhd() void SetParam( AliHLTTPCCATrackParam v ) { fParam = v; };

  private:

    bool fAlive;       // flag for mark tracks used by the track merger
    int  fFirstHitID; // index of the first track cell in the track->cell pointer array
    int  fNHits;      // number of track cells
    AliHLTTPCCATrackParam fParam; // track parameters

  private:
    //void Dummy(); // to make rulechecker happy by having something in .cxx file

    //ClassDef(AliHLTTPCCATrack,1)
};

#endif