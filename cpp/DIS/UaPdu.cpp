#include <DIS/UaPdu.h> 

using namespace DIS;


UaPdu::UaPdu() : DistributedEmissionsFamilyPdu(),
   _emittingEntityID(), 
   _eventID(), 
   _stateChangeIndicator(0), 
   _pad(0), 
   _passiveParameterIndex(0), 
   _propulsionPlantConfiguration(0), 
   _numberOfShafts(0), 
   _numberOfAPAs(0), 
   _numberOfUAEmitterSystems(0), 
   _shaftRPMs(), 
   _apaData(), 
   _emitterSystems()
{
    setPduType( 29 );
}

UaPdu::~UaPdu()
{
}

EntityID& UaPdu::getEmittingEntityID() 
{
    return _emittingEntityID;
}

const EntityID& UaPdu::getEmittingEntityID() const
{
    return _emittingEntityID;
}

void UaPdu::setEmittingEntityID(const EntityID &pX)
{
    _emittingEntityID = pX;
}

EventID& UaPdu::getEventID() 
{
    return _eventID;
}

const EventID& UaPdu::getEventID() const
{
    return _eventID;
}

void UaPdu::setEventID(const EventID &pX)
{
    _eventID = pX;
}

char UaPdu::getStateChangeIndicator() const
{
    return _stateChangeIndicator;
}

void UaPdu::setStateChangeIndicator(char pX)
{
    _stateChangeIndicator = pX;
}

char UaPdu::getPad() const
{
    return _pad;
}

void UaPdu::setPad(char pX)
{
    _pad = pX;
}

unsigned short UaPdu::getPassiveParameterIndex() const
{
    return _passiveParameterIndex;
}

void UaPdu::setPassiveParameterIndex(unsigned short pX)
{
    _passiveParameterIndex = pX;
}

unsigned char UaPdu::getPropulsionPlantConfiguration() const
{
    return _propulsionPlantConfiguration;
}

void UaPdu::setPropulsionPlantConfiguration(unsigned char pX)
{
    _propulsionPlantConfiguration = pX;
}

unsigned char UaPdu::getNumberOfShafts() const
{
    return _numberOfShafts;
}

void UaPdu::setNumberOfShafts(unsigned char pX)
{
    _numberOfShafts = pX;
}

unsigned char UaPdu::getNumberOfAPAs() const
{
    return _numberOfAPAs;
}

void UaPdu::setNumberOfAPAs(unsigned char pX)
{
    _numberOfAPAs = pX;
}

unsigned char UaPdu::getNumberOfUAEmitterSystems() const
{
    return _numberOfUAEmitterSystems;
}

void UaPdu::setNumberOfUAEmitterSystems(unsigned char pX)
{
    _numberOfUAEmitterSystems = pX;
}

ShaftRPMs& UaPdu::getShaftRPMs() 
{
    return _shaftRPMs;
}

const ShaftRPMs& UaPdu::getShaftRPMs() const
{
    return _shaftRPMs;
}

void UaPdu::setShaftRPMs(const ShaftRPMs &pX)
{
    _shaftRPMs = pX;
}

ApaData& UaPdu::getApaData() 
{
    return _apaData;
}

const ApaData& UaPdu::getApaData() const
{
    return _apaData;
}

void UaPdu::setApaData(const ApaData &pX)
{
    _apaData = pX;
}

AcousticEmitterSystemData& UaPdu::getEmitterSystems() 
{
    return _emitterSystems;
}

const AcousticEmitterSystemData& UaPdu::getEmitterSystems() const
{
    return _emitterSystems;
}

void UaPdu::setEmitterSystems(const AcousticEmitterSystemData &pX)
{
    _emitterSystems = pX;
}

void UaPdu::marshal(DataStream& dataStream) const
{
    DistributedEmissionsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _emittingEntityID.marshal(dataStream);
    _eventID.marshal(dataStream);
    dataStream << _stateChangeIndicator;
    dataStream << _pad;
    dataStream << _passiveParameterIndex;
    dataStream << _propulsionPlantConfiguration;
    dataStream << _numberOfShafts;
    dataStream << _numberOfAPAs;
    dataStream << _numberOfUAEmitterSystems;
    _shaftRPMs.marshal(dataStream);
    _apaData.marshal(dataStream);
    _emitterSystems.marshal(dataStream);
}

void UaPdu::unmarshal(DataStream& dataStream)
{
    DistributedEmissionsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _emittingEntityID.unmarshal(dataStream);
    _eventID.unmarshal(dataStream);
    dataStream >> _stateChangeIndicator;
    dataStream >> _pad;
    dataStream >> _passiveParameterIndex;
    dataStream >> _propulsionPlantConfiguration;
    dataStream >> _numberOfShafts;
    dataStream >> _numberOfAPAs;
    dataStream >> _numberOfUAEmitterSystems;
    _shaftRPMs.unmarshal(dataStream);
    _apaData.unmarshal(dataStream);
    _emitterSystems.unmarshal(dataStream);
}


bool UaPdu::operator ==(const UaPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = DistributedEmissionsFamilyPdu::operator==(rhs);

     if( ! (_emittingEntityID == rhs._emittingEntityID) ) ivarsEqual = false;
     if( ! (_eventID == rhs._eventID) ) ivarsEqual = false;
     if( ! (_stateChangeIndicator == rhs._stateChangeIndicator) ) ivarsEqual = false;
     if( ! (_pad == rhs._pad) ) ivarsEqual = false;
     if( ! (_passiveParameterIndex == rhs._passiveParameterIndex) ) ivarsEqual = false;
     if( ! (_propulsionPlantConfiguration == rhs._propulsionPlantConfiguration) ) ivarsEqual = false;
     if( ! (_numberOfShafts == rhs._numberOfShafts) ) ivarsEqual = false;
     if( ! (_numberOfAPAs == rhs._numberOfAPAs) ) ivarsEqual = false;
     if( ! (_numberOfUAEmitterSystems == rhs._numberOfUAEmitterSystems) ) ivarsEqual = false;
     if( ! (_shaftRPMs == rhs._shaftRPMs) ) ivarsEqual = false;
     if( ! (_apaData == rhs._apaData) ) ivarsEqual = false;
     if( ! (_emitterSystems == rhs._emitterSystems) ) ivarsEqual = false;

    return ivarsEqual;
 }

int UaPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = DistributedEmissionsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _emittingEntityID.getMarshalledSize();  // _emittingEntityID
   marshalSize = marshalSize + _eventID.getMarshalledSize();  // _eventID
   marshalSize = marshalSize + 1;  // _stateChangeIndicator
   marshalSize = marshalSize + 1;  // _pad
   marshalSize = marshalSize + 2;  // _passiveParameterIndex
   marshalSize = marshalSize + 1;  // _propulsionPlantConfiguration
   marshalSize = marshalSize + 1;  // _numberOfShafts
   marshalSize = marshalSize + 1;  // _numberOfAPAs
   marshalSize = marshalSize + 1;  // _numberOfUAEmitterSystems
   marshalSize = marshalSize + _shaftRPMs.getMarshalledSize();  // _shaftRPMs
   marshalSize = marshalSize + _apaData.getMarshalledSize();  // _apaData
   marshalSize = marshalSize + _emitterSystems.getMarshalledSize();  // _emitterSystems
    return marshalSize;
}

// Copyright (c) 1995-2009 held by the author(s).  All rights reserved.
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions
//  are met:
// 
//  * Redistributions of source code must retain the above copyright
// notice, this list of conditions and the following disclaimer.
// * Redistributions in binary form must reproduce the above copyright
// notice, this list of conditions and the following disclaimer
// in the documentation and/or other materials provided with the
// distribution.
// * Neither the names of the Naval Postgraduate School (NPS)
//  Modeling Virtual Environments and Simulation (MOVES) Institute
// (http://www.nps.edu and http://www.MovesInstitute.org)
// nor the names of its contributors may be used to endorse or
//  promote products derived from this software without specific
// prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
// AS IS AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
// LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
// FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
// COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
// INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
// BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
// LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
// LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
// ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.
