#include <DIS/MinefieldQueryPdu.h> 

using namespace DIS;


MinefieldQueryPdu::MinefieldQueryPdu() : MinefieldFamilyPdu(),
   _minefieldID(), 
   _requestingEntityID(), 
   _requestID(0), 
   _numberOfPerimeterPoints(0), 
   _pad2(0), 
   _numberOfSensorTypes(0), 
   _dataFilter(0), 
   _requestedMineType(), 
   _requestedPerimeterPoints(), 
   _sensorTypes()
{
    setPduType( 38 );
}

MinefieldQueryPdu::~MinefieldQueryPdu()
{
}

EntityID& MinefieldQueryPdu::getMinefieldID() 
{
    return _minefieldID;
}

const EntityID& MinefieldQueryPdu::getMinefieldID() const
{
    return _minefieldID;
}

void MinefieldQueryPdu::setMinefieldID(const EntityID &pX)
{
    _minefieldID = pX;
}

EntityID& MinefieldQueryPdu::getRequestingEntityID() 
{
    return _requestingEntityID;
}

const EntityID& MinefieldQueryPdu::getRequestingEntityID() const
{
    return _requestingEntityID;
}

void MinefieldQueryPdu::setRequestingEntityID(const EntityID &pX)
{
    _requestingEntityID = pX;
}

unsigned char MinefieldQueryPdu::getRequestID() const
{
    return _requestID;
}

void MinefieldQueryPdu::setRequestID(unsigned char pX)
{
    _requestID = pX;
}

unsigned char MinefieldQueryPdu::getNumberOfPerimeterPoints() const
{
    return _numberOfPerimeterPoints;
}

void MinefieldQueryPdu::setNumberOfPerimeterPoints(unsigned char pX)
{
    _numberOfPerimeterPoints = pX;
}

unsigned char MinefieldQueryPdu::getPad2() const
{
    return _pad2;
}

void MinefieldQueryPdu::setPad2(unsigned char pX)
{
    _pad2 = pX;
}

unsigned char MinefieldQueryPdu::getNumberOfSensorTypes() const
{
    return _numberOfSensorTypes;
}

void MinefieldQueryPdu::setNumberOfSensorTypes(unsigned char pX)
{
    _numberOfSensorTypes = pX;
}

unsigned int MinefieldQueryPdu::getDataFilter() const
{
    return _dataFilter;
}

void MinefieldQueryPdu::setDataFilter(unsigned int pX)
{
    _dataFilter = pX;
}

EntityType& MinefieldQueryPdu::getRequestedMineType() 
{
    return _requestedMineType;
}

const EntityType& MinefieldQueryPdu::getRequestedMineType() const
{
    return _requestedMineType;
}

void MinefieldQueryPdu::setRequestedMineType(const EntityType &pX)
{
    _requestedMineType = pX;
}

Point& MinefieldQueryPdu::getRequestedPerimeterPoints() 
{
    return _requestedPerimeterPoints;
}

const Point& MinefieldQueryPdu::getRequestedPerimeterPoints() const
{
    return _requestedPerimeterPoints;
}

void MinefieldQueryPdu::setRequestedPerimeterPoints(const Point &pX)
{
    _requestedPerimeterPoints = pX;
}

TwoByteChunk& MinefieldQueryPdu::getSensorTypes() 
{
    return _sensorTypes;
}

const TwoByteChunk& MinefieldQueryPdu::getSensorTypes() const
{
    return _sensorTypes;
}

void MinefieldQueryPdu::setSensorTypes(const TwoByteChunk &pX)
{
    _sensorTypes = pX;
}

void MinefieldQueryPdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _minefieldID.marshal(dataStream);
    _requestingEntityID.marshal(dataStream);
    dataStream << _requestID;
    dataStream << _numberOfPerimeterPoints;
    dataStream << _pad2;
    dataStream << _numberOfSensorTypes;
    dataStream << _dataFilter;
    _requestedMineType.marshal(dataStream);
    _requestedPerimeterPoints.marshal(dataStream);
    _sensorTypes.marshal(dataStream);
}

void MinefieldQueryPdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _minefieldID.unmarshal(dataStream);
    _requestingEntityID.unmarshal(dataStream);
    dataStream >> _requestID;
    dataStream >> _numberOfPerimeterPoints;
    dataStream >> _pad2;
    dataStream >> _numberOfSensorTypes;
    dataStream >> _dataFilter;
    _requestedMineType.unmarshal(dataStream);
    _requestedPerimeterPoints.unmarshal(dataStream);
    _sensorTypes.unmarshal(dataStream);
}


bool MinefieldQueryPdu::operator ==(const MinefieldQueryPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (_minefieldID == rhs._minefieldID) ) ivarsEqual = false;
     if( ! (_requestingEntityID == rhs._requestingEntityID) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_numberOfPerimeterPoints == rhs._numberOfPerimeterPoints) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_numberOfSensorTypes == rhs._numberOfSensorTypes) ) ivarsEqual = false;
     if( ! (_dataFilter == rhs._dataFilter) ) ivarsEqual = false;
     if( ! (_requestedMineType == rhs._requestedMineType) ) ivarsEqual = false;
     if( ! (_requestedPerimeterPoints == rhs._requestedPerimeterPoints) ) ivarsEqual = false;
     if( ! (_sensorTypes == rhs._sensorTypes) ) ivarsEqual = false;

    return ivarsEqual;
 }

int MinefieldQueryPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _minefieldID.getMarshalledSize();  // _minefieldID
   marshalSize = marshalSize + _requestingEntityID.getMarshalledSize();  // _requestingEntityID
   marshalSize = marshalSize + 1;  // _requestID
   marshalSize = marshalSize + 1;  // _numberOfPerimeterPoints
   marshalSize = marshalSize + 1;  // _pad2
   marshalSize = marshalSize + 1;  // _numberOfSensorTypes
   marshalSize = marshalSize + 4;  // _dataFilter
   marshalSize = marshalSize + _requestedMineType.getMarshalledSize();  // _requestedMineType
   marshalSize = marshalSize + _requestedPerimeterPoints.getMarshalledSize();  // _requestedPerimeterPoints
   marshalSize = marshalSize + _sensorTypes.getMarshalledSize();  // _sensorTypes
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
