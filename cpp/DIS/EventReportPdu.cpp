#include <DIS/EventReportPdu.h> 

using namespace DIS;


EventReportPdu::EventReportPdu() : SimulationManagementFamilyPdu(),
   _eventType(0), 
   _padding1(0), 
   _numberOfFixedDatumRecords(0), 
   _numberOfVariableDatumRecords(0), 
   _fixedDatums(), 
   _variableDatums()
{
    setPduType( 21 );
}

EventReportPdu::~EventReportPdu()
{
}

unsigned int EventReportPdu::getEventType() const
{
    return _eventType;
}

void EventReportPdu::setEventType(unsigned int pX)
{
    _eventType = pX;
}

unsigned int EventReportPdu::getPadding1() const
{
    return _padding1;
}

void EventReportPdu::setPadding1(unsigned int pX)
{
    _padding1 = pX;
}

unsigned int EventReportPdu::getNumberOfFixedDatumRecords() const
{
    return _numberOfFixedDatumRecords;
}

void EventReportPdu::setNumberOfFixedDatumRecords(unsigned int pX)
{
    _numberOfFixedDatumRecords = pX;
}

unsigned int EventReportPdu::getNumberOfVariableDatumRecords() const
{
    return _numberOfVariableDatumRecords;
}

void EventReportPdu::setNumberOfVariableDatumRecords(unsigned int pX)
{
    _numberOfVariableDatumRecords = pX;
}

FixedDatum& EventReportPdu::getFixedDatums() 
{
    return _fixedDatums;
}

const FixedDatum& EventReportPdu::getFixedDatums() const
{
    return _fixedDatums;
}

void EventReportPdu::setFixedDatums(const FixedDatum &pX)
{
    _fixedDatums = pX;
}

VariableDatum& EventReportPdu::getVariableDatums() 
{
    return _variableDatums;
}

const VariableDatum& EventReportPdu::getVariableDatums() const
{
    return _variableDatums;
}

void EventReportPdu::setVariableDatums(const VariableDatum &pX)
{
    _variableDatums = pX;
}

void EventReportPdu::marshal(DataStream& dataStream) const
{
    SimulationManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _eventType;
    dataStream << _padding1;
    dataStream << _numberOfFixedDatumRecords;
    dataStream << _numberOfVariableDatumRecords;
    _fixedDatums.marshal(dataStream);
    _variableDatums.marshal(dataStream);
}

void EventReportPdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _eventType;
    dataStream >> _padding1;
    dataStream >> _numberOfFixedDatumRecords;
    dataStream >> _numberOfVariableDatumRecords;
    _fixedDatums.unmarshal(dataStream);
    _variableDatums.unmarshal(dataStream);
}


bool EventReportPdu::operator ==(const EventReportPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementFamilyPdu::operator==(rhs);

     if( ! (_eventType == rhs._eventType) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_numberOfFixedDatumRecords == rhs._numberOfFixedDatumRecords) ) ivarsEqual = false;
     if( ! (_numberOfVariableDatumRecords == rhs._numberOfVariableDatumRecords) ) ivarsEqual = false;
     if( ! (_fixedDatums == rhs._fixedDatums) ) ivarsEqual = false;
     if( ! (_variableDatums == rhs._variableDatums) ) ivarsEqual = false;

    return ivarsEqual;
 }

int EventReportPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 4;  // _eventType
   marshalSize = marshalSize + 4;  // _padding1
   marshalSize = marshalSize + 4;  // _numberOfFixedDatumRecords
   marshalSize = marshalSize + 4;  // _numberOfVariableDatumRecords
   marshalSize = marshalSize + _fixedDatums.getMarshalledSize();  // _fixedDatums
   marshalSize = marshalSize + _variableDatums.getMarshalledSize();  // _variableDatums
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
