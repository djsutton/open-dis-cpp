#include <DIS/MinefieldStatePdu.h> 

using namespace DIS;


MinefieldStatePdu::MinefieldStatePdu() : MinefieldFamilyPdu(),
   _minefieldID(), 
   _minefieldSequence(0), 
   _forceID(0), 
   _numberOfPerimeterPoints(0), 
   _minefieldType(), 
   _numberOfMineTypes(0), 
   _minefieldLocation(), 
   _minefieldOrientation(), 
   _appearance(0), 
   _protocolMode(0), 
   _perimeterPoints(), 
   _mineType()
{
    setPduType( 37 );
}

MinefieldStatePdu::~MinefieldStatePdu()
{
}

EntityID& MinefieldStatePdu::getMinefieldID() 
{
    return _minefieldID;
}

const EntityID& MinefieldStatePdu::getMinefieldID() const
{
    return _minefieldID;
}

void MinefieldStatePdu::setMinefieldID(const EntityID &pX)
{
    _minefieldID = pX;
}

unsigned short MinefieldStatePdu::getMinefieldSequence() const
{
    return _minefieldSequence;
}

void MinefieldStatePdu::setMinefieldSequence(unsigned short pX)
{
    _minefieldSequence = pX;
}

unsigned char MinefieldStatePdu::getForceID() const
{
    return _forceID;
}

void MinefieldStatePdu::setForceID(unsigned char pX)
{
    _forceID = pX;
}

unsigned char MinefieldStatePdu::getNumberOfPerimeterPoints() const
{
    return _numberOfPerimeterPoints;
}

void MinefieldStatePdu::setNumberOfPerimeterPoints(unsigned char pX)
{
    _numberOfPerimeterPoints = pX;
}

EntityType& MinefieldStatePdu::getMinefieldType() 
{
    return _minefieldType;
}

const EntityType& MinefieldStatePdu::getMinefieldType() const
{
    return _minefieldType;
}

void MinefieldStatePdu::setMinefieldType(const EntityType &pX)
{
    _minefieldType = pX;
}

unsigned short MinefieldStatePdu::getNumberOfMineTypes() const
{
    return _numberOfMineTypes;
}

void MinefieldStatePdu::setNumberOfMineTypes(unsigned short pX)
{
    _numberOfMineTypes = pX;
}

Vector3Double& MinefieldStatePdu::getMinefieldLocation() 
{
    return _minefieldLocation;
}

const Vector3Double& MinefieldStatePdu::getMinefieldLocation() const
{
    return _minefieldLocation;
}

void MinefieldStatePdu::setMinefieldLocation(const Vector3Double &pX)
{
    _minefieldLocation = pX;
}

Orientation& MinefieldStatePdu::getMinefieldOrientation() 
{
    return _minefieldOrientation;
}

const Orientation& MinefieldStatePdu::getMinefieldOrientation() const
{
    return _minefieldOrientation;
}

void MinefieldStatePdu::setMinefieldOrientation(const Orientation &pX)
{
    _minefieldOrientation = pX;
}

unsigned short MinefieldStatePdu::getAppearance() const
{
    return _appearance;
}

void MinefieldStatePdu::setAppearance(unsigned short pX)
{
    _appearance = pX;
}

unsigned short MinefieldStatePdu::getProtocolMode() const
{
    return _protocolMode;
}

void MinefieldStatePdu::setProtocolMode(unsigned short pX)
{
    _protocolMode = pX;
}

Point& MinefieldStatePdu::getPerimeterPoints() 
{
    return _perimeterPoints;
}

const Point& MinefieldStatePdu::getPerimeterPoints() const
{
    return _perimeterPoints;
}

void MinefieldStatePdu::setPerimeterPoints(const Point &pX)
{
    _perimeterPoints = pX;
}

EntityType& MinefieldStatePdu::getMineType() 
{
    return _mineType;
}

const EntityType& MinefieldStatePdu::getMineType() const
{
    return _mineType;
}

void MinefieldStatePdu::setMineType(const EntityType &pX)
{
    _mineType = pX;
}

void MinefieldStatePdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _minefieldID.marshal(dataStream);
    dataStream << _minefieldSequence;
    dataStream << _forceID;
    dataStream << _numberOfPerimeterPoints;
    _minefieldType.marshal(dataStream);
    dataStream << _numberOfMineTypes;
    _minefieldLocation.marshal(dataStream);
    _minefieldOrientation.marshal(dataStream);
    dataStream << _appearance;
    dataStream << _protocolMode;
    _perimeterPoints.marshal(dataStream);
    _mineType.marshal(dataStream);
}

void MinefieldStatePdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _minefieldID.unmarshal(dataStream);
    dataStream >> _minefieldSequence;
    dataStream >> _forceID;
    dataStream >> _numberOfPerimeterPoints;
    _minefieldType.unmarshal(dataStream);
    dataStream >> _numberOfMineTypes;
    _minefieldLocation.unmarshal(dataStream);
    _minefieldOrientation.unmarshal(dataStream);
    dataStream >> _appearance;
    dataStream >> _protocolMode;
    _perimeterPoints.unmarshal(dataStream);
    _mineType.unmarshal(dataStream);
}


bool MinefieldStatePdu::operator ==(const MinefieldStatePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (_minefieldID == rhs._minefieldID) ) ivarsEqual = false;
     if( ! (_minefieldSequence == rhs._minefieldSequence) ) ivarsEqual = false;
     if( ! (_forceID == rhs._forceID) ) ivarsEqual = false;
     if( ! (_numberOfPerimeterPoints == rhs._numberOfPerimeterPoints) ) ivarsEqual = false;
     if( ! (_minefieldType == rhs._minefieldType) ) ivarsEqual = false;
     if( ! (_numberOfMineTypes == rhs._numberOfMineTypes) ) ivarsEqual = false;
     if( ! (_minefieldLocation == rhs._minefieldLocation) ) ivarsEqual = false;
     if( ! (_minefieldOrientation == rhs._minefieldOrientation) ) ivarsEqual = false;
     if( ! (_appearance == rhs._appearance) ) ivarsEqual = false;
     if( ! (_protocolMode == rhs._protocolMode) ) ivarsEqual = false;
     if( ! (_perimeterPoints == rhs._perimeterPoints) ) ivarsEqual = false;
     if( ! (_mineType == rhs._mineType) ) ivarsEqual = false;

    return ivarsEqual;
 }

int MinefieldStatePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _minefieldID.getMarshalledSize();  // _minefieldID
   marshalSize = marshalSize + 2;  // _minefieldSequence
   marshalSize = marshalSize + 1;  // _forceID
   marshalSize = marshalSize + 1;  // _numberOfPerimeterPoints
   marshalSize = marshalSize + _minefieldType.getMarshalledSize();  // _minefieldType
   marshalSize = marshalSize + 2;  // _numberOfMineTypes
   marshalSize = marshalSize + _minefieldLocation.getMarshalledSize();  // _minefieldLocation
   marshalSize = marshalSize + _minefieldOrientation.getMarshalledSize();  // _minefieldOrientation
   marshalSize = marshalSize + 2;  // _appearance
   marshalSize = marshalSize + 2;  // _protocolMode
   marshalSize = marshalSize + _perimeterPoints.getMarshalledSize();  // _perimeterPoints
   marshalSize = marshalSize + _mineType.getMarshalledSize();  // _mineType
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
