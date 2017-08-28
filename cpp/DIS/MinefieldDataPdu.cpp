#include <DIS/MinefieldDataPdu.h> 

using namespace DIS;


MinefieldDataPdu::MinefieldDataPdu() : MinefieldFamilyPdu(),
   _minefieldID(), 
   _requestingEntityID(), 
   _minefieldSequenceNumbeer(0), 
   _requestID(0), 
   _pduSequenceNumber(0), 
   _numberOfPdus(0), 
   _numberOfMinesInThisPdu(0), 
   _numberOfSensorTypes(0), 
   _pad2(0), 
   _dataFilter(0), 
   _mineType(), 
   _sensorTypes(), 
   _pad3(0), 
   _mineLocation()
{
    setPduType( 39 );
}

MinefieldDataPdu::~MinefieldDataPdu()
{
}

EntityID& MinefieldDataPdu::getMinefieldID() 
{
    return _minefieldID;
}

const EntityID& MinefieldDataPdu::getMinefieldID() const
{
    return _minefieldID;
}

void MinefieldDataPdu::setMinefieldID(const EntityID &pX)
{
    _minefieldID = pX;
}

EntityID& MinefieldDataPdu::getRequestingEntityID() 
{
    return _requestingEntityID;
}

const EntityID& MinefieldDataPdu::getRequestingEntityID() const
{
    return _requestingEntityID;
}

void MinefieldDataPdu::setRequestingEntityID(const EntityID &pX)
{
    _requestingEntityID = pX;
}

unsigned short MinefieldDataPdu::getMinefieldSequenceNumbeer() const
{
    return _minefieldSequenceNumbeer;
}

void MinefieldDataPdu::setMinefieldSequenceNumbeer(unsigned short pX)
{
    _minefieldSequenceNumbeer = pX;
}

unsigned char MinefieldDataPdu::getRequestID() const
{
    return _requestID;
}

void MinefieldDataPdu::setRequestID(unsigned char pX)
{
    _requestID = pX;
}

unsigned char MinefieldDataPdu::getPduSequenceNumber() const
{
    return _pduSequenceNumber;
}

void MinefieldDataPdu::setPduSequenceNumber(unsigned char pX)
{
    _pduSequenceNumber = pX;
}

unsigned char MinefieldDataPdu::getNumberOfPdus() const
{
    return _numberOfPdus;
}

void MinefieldDataPdu::setNumberOfPdus(unsigned char pX)
{
    _numberOfPdus = pX;
}

unsigned char MinefieldDataPdu::getNumberOfMinesInThisPdu() const
{
    return _numberOfMinesInThisPdu;
}

void MinefieldDataPdu::setNumberOfMinesInThisPdu(unsigned char pX)
{
    _numberOfMinesInThisPdu = pX;
}

unsigned char MinefieldDataPdu::getNumberOfSensorTypes() const
{
    return _numberOfSensorTypes;
}

void MinefieldDataPdu::setNumberOfSensorTypes(unsigned char pX)
{
    _numberOfSensorTypes = pX;
}

unsigned char MinefieldDataPdu::getPad2() const
{
    return _pad2;
}

void MinefieldDataPdu::setPad2(unsigned char pX)
{
    _pad2 = pX;
}

unsigned int MinefieldDataPdu::getDataFilter() const
{
    return _dataFilter;
}

void MinefieldDataPdu::setDataFilter(unsigned int pX)
{
    _dataFilter = pX;
}

EntityType& MinefieldDataPdu::getMineType() 
{
    return _mineType;
}

const EntityType& MinefieldDataPdu::getMineType() const
{
    return _mineType;
}

void MinefieldDataPdu::setMineType(const EntityType &pX)
{
    _mineType = pX;
}

TwoByteChunk& MinefieldDataPdu::getSensorTypes() 
{
    return _sensorTypes;
}

const TwoByteChunk& MinefieldDataPdu::getSensorTypes() const
{
    return _sensorTypes;
}

void MinefieldDataPdu::setSensorTypes(const TwoByteChunk &pX)
{
    _sensorTypes = pX;
}

unsigned char MinefieldDataPdu::getPad3() const
{
    return _pad3;
}

void MinefieldDataPdu::setPad3(unsigned char pX)
{
    _pad3 = pX;
}

Vector3Float& MinefieldDataPdu::getMineLocation() 
{
    return _mineLocation;
}

const Vector3Float& MinefieldDataPdu::getMineLocation() const
{
    return _mineLocation;
}

void MinefieldDataPdu::setMineLocation(const Vector3Float &pX)
{
    _mineLocation = pX;
}

void MinefieldDataPdu::marshal(DataStream& dataStream) const
{
    MinefieldFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _minefieldID.marshal(dataStream);
    _requestingEntityID.marshal(dataStream);
    dataStream << _minefieldSequenceNumbeer;
    dataStream << _requestID;
    dataStream << _pduSequenceNumber;
    dataStream << _numberOfPdus;
    dataStream << _numberOfMinesInThisPdu;
    dataStream << _numberOfSensorTypes;
    dataStream << _pad2;
    dataStream << _dataFilter;
    _mineType.marshal(dataStream);
    _sensorTypes.marshal(dataStream);
    dataStream << _pad3;
    _mineLocation.marshal(dataStream);
}

void MinefieldDataPdu::unmarshal(DataStream& dataStream)
{
    MinefieldFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _minefieldID.unmarshal(dataStream);
    _requestingEntityID.unmarshal(dataStream);
    dataStream >> _minefieldSequenceNumbeer;
    dataStream >> _requestID;
    dataStream >> _pduSequenceNumber;
    dataStream >> _numberOfPdus;
    dataStream >> _numberOfMinesInThisPdu;
    dataStream >> _numberOfSensorTypes;
    dataStream >> _pad2;
    dataStream >> _dataFilter;
    _mineType.unmarshal(dataStream);
    _sensorTypes.unmarshal(dataStream);
    dataStream >> _pad3;
    _mineLocation.unmarshal(dataStream);
}


bool MinefieldDataPdu::operator ==(const MinefieldDataPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = MinefieldFamilyPdu::operator==(rhs);

     if( ! (_minefieldID == rhs._minefieldID) ) ivarsEqual = false;
     if( ! (_requestingEntityID == rhs._requestingEntityID) ) ivarsEqual = false;
     if( ! (_minefieldSequenceNumbeer == rhs._minefieldSequenceNumbeer) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_pduSequenceNumber == rhs._pduSequenceNumber) ) ivarsEqual = false;
     if( ! (_numberOfPdus == rhs._numberOfPdus) ) ivarsEqual = false;
     if( ! (_numberOfMinesInThisPdu == rhs._numberOfMinesInThisPdu) ) ivarsEqual = false;
     if( ! (_numberOfSensorTypes == rhs._numberOfSensorTypes) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_dataFilter == rhs._dataFilter) ) ivarsEqual = false;
     if( ! (_mineType == rhs._mineType) ) ivarsEqual = false;
     if( ! (_sensorTypes == rhs._sensorTypes) ) ivarsEqual = false;
     if( ! (_pad3 == rhs._pad3) ) ivarsEqual = false;
     if( ! (_mineLocation == rhs._mineLocation) ) ivarsEqual = false;

    return ivarsEqual;
 }

int MinefieldDataPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = MinefieldFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _minefieldID.getMarshalledSize();  // _minefieldID
   marshalSize = marshalSize + _requestingEntityID.getMarshalledSize();  // _requestingEntityID
   marshalSize = marshalSize + 2;  // _minefieldSequenceNumbeer
   marshalSize = marshalSize + 1;  // _requestID
   marshalSize = marshalSize + 1;  // _pduSequenceNumber
   marshalSize = marshalSize + 1;  // _numberOfPdus
   marshalSize = marshalSize + 1;  // _numberOfMinesInThisPdu
   marshalSize = marshalSize + 1;  // _numberOfSensorTypes
   marshalSize = marshalSize + 1;  // _pad2
   marshalSize = marshalSize + 4;  // _dataFilter
   marshalSize = marshalSize + _mineType.getMarshalledSize();  // _mineType
   marshalSize = marshalSize + _sensorTypes.getMarshalledSize();  // _sensorTypes
   marshalSize = marshalSize + 1;  // _pad3
   marshalSize = marshalSize + _mineLocation.getMarshalledSize();  // _mineLocation
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
