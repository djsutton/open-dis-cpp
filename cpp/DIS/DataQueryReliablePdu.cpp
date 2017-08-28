#include <DIS/DataQueryReliablePdu.h> 

using namespace DIS;


DataQueryReliablePdu::DataQueryReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   _requiredReliabilityService(0), 
   _pad1(0), 
   _pad2(0), 
   _requestID(0), 
   _timeInterval(0), 
   _numberOfFixedDatumRecords(0), 
   _numberOfVariableDatumRecords(0), 
   _fixedDatumRecords(), 
   _variableDatumRecords()
{
    setPduType( 58 );
}

DataQueryReliablePdu::~DataQueryReliablePdu()
{
}

unsigned char DataQueryReliablePdu::getRequiredReliabilityService() const
{
    return _requiredReliabilityService;
}

void DataQueryReliablePdu::setRequiredReliabilityService(unsigned char pX)
{
    _requiredReliabilityService = pX;
}

unsigned short DataQueryReliablePdu::getPad1() const
{
    return _pad1;
}

void DataQueryReliablePdu::setPad1(unsigned short pX)
{
    _pad1 = pX;
}

unsigned char DataQueryReliablePdu::getPad2() const
{
    return _pad2;
}

void DataQueryReliablePdu::setPad2(unsigned char pX)
{
    _pad2 = pX;
}

unsigned int DataQueryReliablePdu::getRequestID() const
{
    return _requestID;
}

void DataQueryReliablePdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

unsigned int DataQueryReliablePdu::getTimeInterval() const
{
    return _timeInterval;
}

void DataQueryReliablePdu::setTimeInterval(unsigned int pX)
{
    _timeInterval = pX;
}

unsigned int DataQueryReliablePdu::getNumberOfFixedDatumRecords() const
{
    return _numberOfFixedDatumRecords;
}

void DataQueryReliablePdu::setNumberOfFixedDatumRecords(unsigned int pX)
{
    _numberOfFixedDatumRecords = pX;
}

unsigned int DataQueryReliablePdu::getNumberOfVariableDatumRecords() const
{
    return _numberOfVariableDatumRecords;
}

void DataQueryReliablePdu::setNumberOfVariableDatumRecords(unsigned int pX)
{
    _numberOfVariableDatumRecords = pX;
}

FixedDatum& DataQueryReliablePdu::getFixedDatumRecords() 
{
    return _fixedDatumRecords;
}

const FixedDatum& DataQueryReliablePdu::getFixedDatumRecords() const
{
    return _fixedDatumRecords;
}

void DataQueryReliablePdu::setFixedDatumRecords(const FixedDatum &pX)
{
    _fixedDatumRecords = pX;
}

VariableDatum& DataQueryReliablePdu::getVariableDatumRecords() 
{
    return _variableDatumRecords;
}

const VariableDatum& DataQueryReliablePdu::getVariableDatumRecords() const
{
    return _variableDatumRecords;
}

void DataQueryReliablePdu::setVariableDatumRecords(const VariableDatum &pX)
{
    _variableDatumRecords = pX;
}

void DataQueryReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _requiredReliabilityService;
    dataStream << _pad1;
    dataStream << _pad2;
    dataStream << _requestID;
    dataStream << _timeInterval;
    dataStream << _numberOfFixedDatumRecords;
    dataStream << _numberOfVariableDatumRecords;
    _fixedDatumRecords.marshal(dataStream);
    _variableDatumRecords.marshal(dataStream);
}

void DataQueryReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _requiredReliabilityService;
    dataStream >> _pad1;
    dataStream >> _pad2;
    dataStream >> _requestID;
    dataStream >> _timeInterval;
    dataStream >> _numberOfFixedDatumRecords;
    dataStream >> _numberOfVariableDatumRecords;
    _fixedDatumRecords.unmarshal(dataStream);
    _variableDatumRecords.unmarshal(dataStream);
}


bool DataQueryReliablePdu::operator ==(const DataQueryReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (_requiredReliabilityService == rhs._requiredReliabilityService) ) ivarsEqual = false;
     if( ! (_pad1 == rhs._pad1) ) ivarsEqual = false;
     if( ! (_pad2 == rhs._pad2) ) ivarsEqual = false;
     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_timeInterval == rhs._timeInterval) ) ivarsEqual = false;
     if( ! (_numberOfFixedDatumRecords == rhs._numberOfFixedDatumRecords) ) ivarsEqual = false;
     if( ! (_numberOfVariableDatumRecords == rhs._numberOfVariableDatumRecords) ) ivarsEqual = false;
     if( ! (_fixedDatumRecords == rhs._fixedDatumRecords) ) ivarsEqual = false;
     if( ! (_variableDatumRecords == rhs._variableDatumRecords) ) ivarsEqual = false;

    return ivarsEqual;
 }

int DataQueryReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 1;  // _requiredReliabilityService
   marshalSize = marshalSize + 2;  // _pad1
   marshalSize = marshalSize + 1;  // _pad2
   marshalSize = marshalSize + 4;  // _requestID
   marshalSize = marshalSize + 4;  // _timeInterval
   marshalSize = marshalSize + 4;  // _numberOfFixedDatumRecords
   marshalSize = marshalSize + 4;  // _numberOfVariableDatumRecords
   marshalSize = marshalSize + _fixedDatumRecords.getMarshalledSize();  // _fixedDatumRecords
   marshalSize = marshalSize + _variableDatumRecords.getMarshalledSize();  // _variableDatumRecords
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
