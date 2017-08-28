#include <DIS/EventReportReliablePdu.h> 

using namespace DIS;


EventReportReliablePdu::EventReportReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   _eventType(0), 
   _pad1(0), 
   _numberOfFixedDatumRecords(0), 
   _numberOfVariableDatumRecords(0), 
   _fixedDatumRecords(), 
   _variableDatumRecords()
{
    setPduType( 61 );
}

EventReportReliablePdu::~EventReportReliablePdu()
{
}

unsigned short EventReportReliablePdu::getEventType() const
{
    return _eventType;
}

void EventReportReliablePdu::setEventType(unsigned short pX)
{
    _eventType = pX;
}

unsigned int EventReportReliablePdu::getPad1() const
{
    return _pad1;
}

void EventReportReliablePdu::setPad1(unsigned int pX)
{
    _pad1 = pX;
}

unsigned int EventReportReliablePdu::getNumberOfFixedDatumRecords() const
{
    return _numberOfFixedDatumRecords;
}

void EventReportReliablePdu::setNumberOfFixedDatumRecords(unsigned int pX)
{
    _numberOfFixedDatumRecords = pX;
}

unsigned int EventReportReliablePdu::getNumberOfVariableDatumRecords() const
{
    return _numberOfVariableDatumRecords;
}

void EventReportReliablePdu::setNumberOfVariableDatumRecords(unsigned int pX)
{
    _numberOfVariableDatumRecords = pX;
}

FixedDatum& EventReportReliablePdu::getFixedDatumRecords() 
{
    return _fixedDatumRecords;
}

const FixedDatum& EventReportReliablePdu::getFixedDatumRecords() const
{
    return _fixedDatumRecords;
}

void EventReportReliablePdu::setFixedDatumRecords(const FixedDatum &pX)
{
    _fixedDatumRecords = pX;
}

VariableDatum& EventReportReliablePdu::getVariableDatumRecords() 
{
    return _variableDatumRecords;
}

const VariableDatum& EventReportReliablePdu::getVariableDatumRecords() const
{
    return _variableDatumRecords;
}

void EventReportReliablePdu::setVariableDatumRecords(const VariableDatum &pX)
{
    _variableDatumRecords = pX;
}

void EventReportReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _eventType;
    dataStream << _pad1;
    dataStream << _numberOfFixedDatumRecords;
    dataStream << _numberOfVariableDatumRecords;
    _fixedDatumRecords.marshal(dataStream);
    _variableDatumRecords.marshal(dataStream);
}

void EventReportReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _eventType;
    dataStream >> _pad1;
    dataStream >> _numberOfFixedDatumRecords;
    dataStream >> _numberOfVariableDatumRecords;
    _fixedDatumRecords.unmarshal(dataStream);
    _variableDatumRecords.unmarshal(dataStream);
}


bool EventReportReliablePdu::operator ==(const EventReportReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (_eventType == rhs._eventType) ) ivarsEqual = false;
     if( ! (_pad1 == rhs._pad1) ) ivarsEqual = false;
     if( ! (_numberOfFixedDatumRecords == rhs._numberOfFixedDatumRecords) ) ivarsEqual = false;
     if( ! (_numberOfVariableDatumRecords == rhs._numberOfVariableDatumRecords) ) ivarsEqual = false;
     if( ! (_fixedDatumRecords == rhs._fixedDatumRecords) ) ivarsEqual = false;
     if( ! (_variableDatumRecords == rhs._variableDatumRecords) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EventReportReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 2;  // _eventType
   marshalSize = marshalSize + 4;  // _pad1
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
