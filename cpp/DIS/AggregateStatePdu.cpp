#include <DIS/AggregateStatePdu.h> 

using namespace DIS;


AggregateStatePdu::AggregateStatePdu() : EntityManagementFamilyPdu(),
   _aggregateID(), 
   _forceID(0), 
   _aggregateState(0), 
   _aggregateType(), 
   _formation(0), 
   _aggregateMarking(), 
   _dimensions(), 
   _orientation(), 
   _centerOfMass(), 
   _velocity(), 
   _numberOfDisAggregates(0), 
   _numberOfDisEntities(0), 
   _numberOfSilentAggregateTypes(0), 
   _numberOfSilentEntityTypes(0), 
   _aggregateIDList(), 
   _entityIDList(), 
   _pad2(0), 
   _silentAggregateSystemList(), 
   _silentEntitySystemList(), 
   _numberOfVariableDatumRecords(0), 
   _variableDatumList()
{
    setPduType( 33 );
}

AggregateStatePdu::~AggregateStatePdu()
{
}

EntityID& AggregateStatePdu::getAggregateID() 
{
    return _aggregateID;
}

const EntityID& AggregateStatePdu::getAggregateID() const
{
    return _aggregateID;
}

void AggregateStatePdu::setAggregateID(const EntityID &pX)
{
    _aggregateID = pX;
}

unsigned char AggregateStatePdu::getForceID() const
{
    return _forceID;
}

void AggregateStatePdu::setForceID(unsigned char pX)
{
    _forceID = pX;
}

unsigned char AggregateStatePdu::getAggregateState() const
{
    return _aggregateState;
}

void AggregateStatePdu::setAggregateState(unsigned char pX)
{
    _aggregateState = pX;
}

EntityType& AggregateStatePdu::getAggregateType() 
{
    return _aggregateType;
}

const EntityType& AggregateStatePdu::getAggregateType() const
{
    return _aggregateType;
}

void AggregateStatePdu::setAggregateType(const EntityType &pX)
{
    _aggregateType = pX;
}

unsigned int AggregateStatePdu::getFormation() const
{
    return _formation;
}

void AggregateStatePdu::setFormation(unsigned int pX)
{
    _formation = pX;
}

AggregateMarking& AggregateStatePdu::getAggregateMarking() 
{
    return _aggregateMarking;
}

const AggregateMarking& AggregateStatePdu::getAggregateMarking() const
{
    return _aggregateMarking;
}

void AggregateStatePdu::setAggregateMarking(const AggregateMarking &pX)
{
    _aggregateMarking = pX;
}

Vector3Float& AggregateStatePdu::getDimensions() 
{
    return _dimensions;
}

const Vector3Float& AggregateStatePdu::getDimensions() const
{
    return _dimensions;
}

void AggregateStatePdu::setDimensions(const Vector3Float &pX)
{
    _dimensions = pX;
}

Orientation& AggregateStatePdu::getOrientation() 
{
    return _orientation;
}

const Orientation& AggregateStatePdu::getOrientation() const
{
    return _orientation;
}

void AggregateStatePdu::setOrientation(const Orientation &pX)
{
    _orientation = pX;
}

Vector3Double& AggregateStatePdu::getCenterOfMass() 
{
    return _centerOfMass;
}

const Vector3Double& AggregateStatePdu::getCenterOfMass() const
{
    return _centerOfMass;
}

void AggregateStatePdu::setCenterOfMass(const Vector3Double &pX)
{
    _centerOfMass = pX;
}

Vector3Float& AggregateStatePdu::getVelocity() 
{
    return _velocity;
}

const Vector3Float& AggregateStatePdu::getVelocity() const
{
    return _velocity;
}

void AggregateStatePdu::setVelocity(const Vector3Float &pX)
{
    _velocity = pX;
}

unsigned short AggregateStatePdu::getNumberOfDisAggregates() const
{
    return _numberOfDisAggregates;
}

void AggregateStatePdu::setNumberOfDisAggregates(unsigned short pX)
{
    _numberOfDisAggregates = pX;
}

unsigned short AggregateStatePdu::getNumberOfDisEntities() const
{
    return _numberOfDisEntities;
}

void AggregateStatePdu::setNumberOfDisEntities(unsigned short pX)
{
    _numberOfDisEntities = pX;
}

unsigned short AggregateStatePdu::getNumberOfSilentAggregateTypes() const
{
    return _numberOfSilentAggregateTypes;
}

void AggregateStatePdu::setNumberOfSilentAggregateTypes(unsigned short pX)
{
    _numberOfSilentAggregateTypes = pX;
}

unsigned short AggregateStatePdu::getNumberOfSilentEntityTypes() const
{
    return _numberOfSilentEntityTypes;
}

void AggregateStatePdu::setNumberOfSilentEntityTypes(unsigned short pX)
{
    _numberOfSilentEntityTypes = pX;
}

AggregateID& AggregateStatePdu::getAggregateIDList() 
{
    return _aggregateIDList;
}

const AggregateID& AggregateStatePdu::getAggregateIDList() const
{
    return _aggregateIDList;
}

void AggregateStatePdu::setAggregateIDList(const AggregateID &pX)
{
    _aggregateIDList = pX;
}

EntityID& AggregateStatePdu::getEntityIDList() 
{
    return _entityIDList;
}

const EntityID& AggregateStatePdu::getEntityIDList() const
{
    return _entityIDList;
}

void AggregateStatePdu::setEntityIDList(const EntityID &pX)
{
    _entityIDList = pX;
}

unsigned char AggregateStatePdu::getPad2() const
{
    return _pad2;
}

void AggregateStatePdu::setPad2(unsigned char pX)
{
    _pad2 = pX;
}

EntityType& AggregateStatePdu::getSilentAggregateSystemList() 
{
    return _silentAggregateSystemList;
}

const EntityType& AggregateStatePdu::getSilentAggregateSystemList() const
{
    return _silentAggregateSystemList;
}

void AggregateStatePdu::setSilentAggregateSystemList(const EntityType &pX)
{
    _silentAggregateSystemList = pX;
}

EntityType& AggregateStatePdu::getSilentEntitySystemList() 
{
    return _silentEntitySystemList;
}

const EntityType& AggregateStatePdu::getSilentEntitySystemList() const
{
    return _silentEntitySystemList;
}

void AggregateStatePdu::setSilentEntitySystemList(const EntityType &pX)
{
    _silentEntitySystemList = pX;
}

unsigned int AggregateStatePdu::getNumberOfVariableDatumRecords() const
{
    return _numberOfVariableDatumRecords;
}

void AggregateStatePdu::setNumberOfVariableDatumRecords(unsigned int pX)
{
    _numberOfVariableDatumRecords = pX;
}

VariableDatum& AggregateStatePdu::getVariableDatumList() 
{
    return _variableDatumList;
}

const VariableDatum& AggregateStatePdu::getVariableDatumList() const
{
    return _variableDatumList;
}

void AggregateStatePdu::setVariableDatumList(const VariableDatum &pX)
{
    _variableDatumList = pX;
}

void AggregateStatePdu::marshal(DataStream& dataStream) const
{
    EntityManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _aggregateID.marshal(dataStream);
    dataStream << _forceID;
    dataStream << _aggregateState;
    _aggregateType.marshal(dataStream);
    dataStream << _formation;
    _aggregateMarking.marshal(dataStream);
    _dimensions.marshal(dataStream);
    _orientation.marshal(dataStream);
    _centerOfMass.marshal(dataStream);
    _velocity.marshal(dataStream);
    dataStream << _numberOfDisAggregates;
    dataStream << _numberOfDisEntities;
    dataStream << _numberOfSilentAggregateTypes;
    dataStream << _numberOfSilentEntityTypes;
    _aggregateIDList.marshal(dataStream);
    _entityIDList.marshal(dataStream);
    dataStream << _pad2;
    _silentAggregateSystemList.marshal(dataStream);
    _silentEntitySystemList.marshal(dataStream);
    dataStream << _numberOfVariableDatumRecords;
    _variableDatumList.marshal(dataStream);
}

void AggregateStatePdu::unmarshal(DataStream& dataStream)
{
    EntityManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _aggregateID.unmarshal(dataStream);
    dataStream >> _forceID;
    dataStream >> _aggregateState;
    _aggregateType.unmarshal(dataStream);
    dataStream >> _formation;
    _aggregateMarking.unmarshal(dataStream);
    _dimensions.unmarshal(dataStream);
    _orientation.unmarshal(dataStream);
    _centerOfMass.unmarshal(dataStream);
    _velocity.unmarshal(dataStream);
    dataStream >> _numberOfDisAggregates;
    dataStream >> _numberOfDisEntities;
    dataStream >> _numberOfSilentAggregateTypes;
    dataStream >> _numberOfSilentEntityTypes;
    _aggregateIDList.unmarshal(dataStream);
    _entityIDList.unmarshal(dataStream);
    dataStream >> _pad2;
    _silentAggregateSystemList.unmarshal(dataStream);
    _silentEntitySystemList.unmarshal(dataStream);
    dataStream >> _numberOfVariableDatumRecords;
    _variableDatumList.unmarshal(dataStream);
}


bool AggregateStatePdu::operator ==(const AggregateStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = EntityManagementFamilyPdu::operator==(rhs);

     if( ! (_aggregateID == rhs._aggregateID) ) ivarsEqual = false;
     if( ! (_forceID == rhs._forceID) ) ivarsEqual = false;
     if( ! (_aggregateState == rhs._aggregateState) ) ivarsEqual = false;
     if( ! (_aggregateType == rhs._aggregateType) ) ivarsEqual = false;
     if( ! (_formation == rhs._formation) ) ivarsEqual = false;
     if( ! (_aggregateMarking == rhs._aggregateMarking) ) ivarsEqual = false;
     if( ! (_dimensions == rhs._dimensions) ) ivarsEqual = false;
     if( ! (_orientation == rhs._orientation) ) ivarsEqual = false;
     if( ! (_centerOfMass == rhs._centerOfMass) ) ivarsEqual = false;
     if( ! (_velocity == rhs._velocity) ) ivarsEqual = false;
     if( ! (_numberOfDisAggregates == rhs._numberOfDisAggregates) ) ivarsEqual = false;
     if( ! (_numberOfDisEntities == rhs._numberOfDisEntities) ) ivarsEqual = false;
     if( ! (_numberOfSilentAggregateTypes == rhs._numberOfSilentAggregateTypes) ) ivarsEqual = false;
     if( ! (_numberOfSilentEntityTypes == rhs._numberOfSilentEntityTypes) ) ivarsEqual = false;
     if( ! (_aggregateIDList == rhs._aggregateIDList) ) ivarsEqual = false;
     if( ! (_entityIDList == rhs._entityIDList) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_silentAggregateSystemList == rhs._silentAggregateSystemList) ) ivarsEqual = false;
     if( ! (_silentEntitySystemList == rhs._silentEntitySystemList) ) ivarsEqual = false;
     if( ! (_numberOfVariableDatumRecords == rhs._numberOfVariableDatumRecords) ) ivarsEqual = false;
     if( ! (_variableDatumList == rhs._variableDatumList) ) ivarsEqual = false;

    return ivarsEqual;
 }

int AggregateStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = EntityManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _aggregateID.getMarshalledSize();  // _aggregateID
   marshalSize = marshalSize + 1;  // _forceID
   marshalSize = marshalSize + 1;  // _aggregateState
   marshalSize = marshalSize + _aggregateType.getMarshalledSize();  // _aggregateType
   marshalSize = marshalSize + 4;  // _formation
   marshalSize = marshalSize + _aggregateMarking.getMarshalledSize();  // _aggregateMarking
   marshalSize = marshalSize + _dimensions.getMarshalledSize();  // _dimensions
   marshalSize = marshalSize + _orientation.getMarshalledSize();  // _orientation
   marshalSize = marshalSize + _centerOfMass.getMarshalledSize();  // _centerOfMass
   marshalSize = marshalSize + _velocity.getMarshalledSize();  // _velocity
   marshalSize = marshalSize + 2;  // _numberOfDisAggregates
   marshalSize = marshalSize + 2;  // _numberOfDisEntities
   marshalSize = marshalSize + 2;  // _numberOfSilentAggregateTypes
   marshalSize = marshalSize + 2;  // _numberOfSilentEntityTypes
   marshalSize = marshalSize + _aggregateIDList.getMarshalledSize();  // _aggregateIDList
   marshalSize = marshalSize + _entityIDList.getMarshalledSize();  // _entityIDList
   marshalSize = marshalSize + 1;  // _pad2
   marshalSize = marshalSize + _silentAggregateSystemList.getMarshalledSize();  // _silentAggregateSystemList
   marshalSize = marshalSize + _silentEntitySystemList.getMarshalledSize();  // _silentEntitySystemList
   marshalSize = marshalSize + 4;  // _numberOfVariableDatumRecords
   marshalSize = marshalSize + _variableDatumList.getMarshalledSize();  // _variableDatumList
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
