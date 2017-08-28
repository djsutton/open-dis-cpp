#include <DIS/ElectronicEmissionSystemData.h> 

using namespace DIS;


ElectronicEmissionSystemData::ElectronicEmissionSystemData():
   _systemDataLength(0), 
   _numberOfBeams(0), 
   _emissionsPadding2(0), 
   _emitterSystem(), 
   _location(), 
   _beamDataRecords()
{
}

ElectronicEmissionSystemData::~ElectronicEmissionSystemData()
{
}

unsigned char ElectronicEmissionSystemData::getSystemDataLength() const
{
    return _systemDataLength;
}

void ElectronicEmissionSystemData::setSystemDataLength(unsigned char pX)
{
    _systemDataLength = pX;
}

unsigned char ElectronicEmissionSystemData::getNumberOfBeams() const
{
    return _numberOfBeams;
}

void ElectronicEmissionSystemData::setNumberOfBeams(unsigned char pX)
{
    _numberOfBeams = pX;
}

unsigned short ElectronicEmissionSystemData::getEmissionsPadding2() const
{
    return _emissionsPadding2;
}

void ElectronicEmissionSystemData::setEmissionsPadding2(unsigned short pX)
{
    _emissionsPadding2 = pX;
}

EmitterSystem& ElectronicEmissionSystemData::getEmitterSystem() 
{
    return _emitterSystem;
}

const EmitterSystem& ElectronicEmissionSystemData::getEmitterSystem() const
{
    return _emitterSystem;
}

void ElectronicEmissionSystemData::setEmitterSystem(const EmitterSystem &pX)
{
    _emitterSystem = pX;
}

Vector3Float& ElectronicEmissionSystemData::getLocation() 
{
    return _location;
}

const Vector3Float& ElectronicEmissionSystemData::getLocation() const
{
    return _location;
}

void ElectronicEmissionSystemData::setLocation(const Vector3Float &pX)
{
    _location = pX;
}

ElectronicEmissionBeamData& ElectronicEmissionSystemData::getBeamDataRecords() 
{
    return _beamDataRecords;
}

const ElectronicEmissionBeamData& ElectronicEmissionSystemData::getBeamDataRecords() const
{
    return _beamDataRecords;
}

void ElectronicEmissionSystemData::setBeamDataRecords(const ElectronicEmissionBeamData &pX)
{
    _beamDataRecords = pX;
}

void ElectronicEmissionSystemData::marshal(DataStream& dataStream) const
{
    dataStream << _systemDataLength;
    dataStream << _numberOfBeams;
    dataStream << _emissionsPadding2;
    _emitterSystem.marshal(dataStream);
    _location.marshal(dataStream);
    _beamDataRecords.marshal(dataStream);
}

void ElectronicEmissionSystemData::unmarshal(DataStream& dataStream)
{
    dataStream >> _systemDataLength;
    dataStream >> _numberOfBeams;
    dataStream >> _emissionsPadding2;
    _emitterSystem.unmarshal(dataStream);
    _location.unmarshal(dataStream);
    _beamDataRecords.unmarshal(dataStream);
}


bool ElectronicEmissionSystemData::operator ==(const ElectronicEmissionSystemData& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_systemDataLength == rhs._systemDataLength) ) ivarsEqual = false;
     if( ! (_numberOfBeams == rhs._numberOfBeams) ) ivarsEqual = false;
     if( ! (_emissionsPadding2 == rhs._emissionsPadding2) ) ivarsEqual = false;
     if( ! (_emitterSystem == rhs._emitterSystem) ) ivarsEqual = false;
     if( ! (_location == rhs._location) ) ivarsEqual = false;
     if( ! (_beamDataRecords == rhs._beamDataRecords) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ElectronicEmissionSystemData::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _systemDataLength
   marshalSize = marshalSize + 1;  // _numberOfBeams
   marshalSize = marshalSize + 2;  // _emissionsPadding2
   marshalSize = marshalSize + _emitterSystem.getMarshalledSize();  // _emitterSystem
   marshalSize = marshalSize + _location.getMarshalledSize();  // _location
   marshalSize = marshalSize + _beamDataRecords.getMarshalledSize();  // _beamDataRecords
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
