#include <DIS/ActionResponsePdu.h> 

using namespace DIS;


ActionResponsePdu::ActionResponsePdu() : SimulationManagementFamilyPdu(),
   _requestID(0), 
   _requestStatus(0), 
   _numberOfFixedDatumRecords(0), 
   _numberOfVariableDatumRecords(0), 
   _fixedDatums(), 
   _variableDatums()
{
    setPduType( 17 );
}

ActionResponsePdu::~ActionResponsePdu()
{
}

unsigned int ActionResponsePdu::getRequestID() const
{
    return _requestID;
}

void ActionResponsePdu::setRequestID(unsigned int pX)
{
    _requestID = pX;
}

unsigned int ActionResponsePdu::getRequestStatus() const
{
    return _requestStatus;
}

void ActionResponsePdu::setRequestStatus(unsigned int pX)
{
    _requestStatus = pX;
}

unsigned int ActionResponsePdu::getNumberOfFixedDatumRecords() const
{
    return _numberOfFixedDatumRecords;
}

void ActionResponsePdu::setNumberOfFixedDatumRecords(unsigned int pX)
{
    _numberOfFixedDatumRecords = pX;
}

unsigned int ActionResponsePdu::getNumberOfVariableDatumRecords() const
{
    return _numberOfVariableDatumRecords;
}

void ActionResponsePdu::setNumberOfVariableDatumRecords(unsigned int pX)
{
    _numberOfVariableDatumRecords = pX;
}

FixedDatum& ActionResponsePdu::getFixedDatums() 
{
    return _fixedDatums;
}

const FixedDatum& ActionResponsePdu::getFixedDatums() const
{
    return _fixedDatums;
}

void ActionResponsePdu::setFixedDatums(const FixedDatum &pX)
{
    _fixedDatums = pX;
}

VariableDatum& ActionResponsePdu::getVariableDatums() 
{
    return _variableDatums;
}

const VariableDatum& ActionResponsePdu::getVariableDatums() const
{
    return _variableDatums;
}

void ActionResponsePdu::setVariableDatums(const VariableDatum &pX)
{
    _variableDatums = pX;
}

void ActionResponsePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _requestID;
    dataStream << _requestStatus;
    dataStream << _numberOfFixedDatumRecords;
    dataStream << _numberOfVariableDatumRecords;
    _fixedDatums.marshal(dataStream);
    _variableDatums.marshal(dataStream);
}

void ActionResponsePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _requestID;
    dataStream >> _requestStatus;
    dataStream >> _numberOfFixedDatumRecords;
    dataStream >> _numberOfVariableDatumRecords;
    _fixedDatums.unmarshal(dataStream);
    _variableDatums.unmarshal(dataStream);
}


bool ActionResponsePdu::operator ==(const ActionResponsePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementFamilyPdu::operator==(rhs);

     if( ! (_requestID == rhs._requestID) ) ivarsEqual = false;
     if( ! (_requestStatus == rhs._requestStatus) ) ivarsEqual = false;
     if( ! (_numberOfFixedDatumRecords == rhs._numberOfFixedDatumRecords) ) ivarsEqual = false;
     if( ! (_numberOfVariableDatumRecords == rhs._numberOfVariableDatumRecords) ) ivarsEqual = false;
     if( ! (_fixedDatums == rhs._fixedDatums) ) ivarsEqual = false;
     if( ! (_variableDatums == rhs._variableDatums) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ActionResponsePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + 4;  // _requestID
   marshalSize = marshalSize + 4;  // _requestStatus
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
