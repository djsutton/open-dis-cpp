#include <DIS/CommentReliablePdu.h> 

using namespace DIS;


CommentReliablePdu::CommentReliablePdu() : SimulationManagementWithReliabilityFamilyPdu(),
   _numberOfFixedDatumRecords(0), 
   _numberOfVariableDatumRecords(0), 
   _fixedDatumRecords(), 
   _variableDatumRecords()
{
    setPduType( 62 );
}

CommentReliablePdu::~CommentReliablePdu()
{
}

unsigned int CommentReliablePdu::getNumberOfFixedDatumRecords() const
{
    return _numberOfFixedDatumRecords;
}

void CommentReliablePdu::setNumberOfFixedDatumRecords(unsigned int pX)
{
    _numberOfFixedDatumRecords = pX;
}

unsigned int CommentReliablePdu::getNumberOfVariableDatumRecords() const
{
    return _numberOfVariableDatumRecords;
}

void CommentReliablePdu::setNumberOfVariableDatumRecords(unsigned int pX)
{
    _numberOfVariableDatumRecords = pX;
}

FixedDatum& CommentReliablePdu::getFixedDatumRecords() 
{
    return _fixedDatumRecords;
}

const FixedDatum& CommentReliablePdu::getFixedDatumRecords() const
{
    return _fixedDatumRecords;
}

void CommentReliablePdu::setFixedDatumRecords(const FixedDatum &pX)
{
    _fixedDatumRecords = pX;
}

VariableDatum& CommentReliablePdu::getVariableDatumRecords() 
{
    return _variableDatumRecords;
}

const VariableDatum& CommentReliablePdu::getVariableDatumRecords() const
{
    return _variableDatumRecords;
}

void CommentReliablePdu::setVariableDatumRecords(const VariableDatum &pX)
{
    _variableDatumRecords = pX;
}

void CommentReliablePdu::marshal(DataStream& dataStream) const
{
    SimulationManagementWithReliabilityFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    dataStream << _numberOfFixedDatumRecords;
    dataStream << _numberOfVariableDatumRecords;
    _fixedDatumRecords.marshal(dataStream);
    _variableDatumRecords.marshal(dataStream);
}

void CommentReliablePdu::unmarshal(DataStream& dataStream)
{
    SimulationManagementWithReliabilityFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _numberOfFixedDatumRecords;
    dataStream >> _numberOfVariableDatumRecords;
    _fixedDatumRecords.unmarshal(dataStream);
    _variableDatumRecords.unmarshal(dataStream);
}


bool CommentReliablePdu::operator ==(const CommentReliablePdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = SimulationManagementWithReliabilityFamilyPdu::operator==(rhs);

     if( ! (_numberOfFixedDatumRecords == rhs._numberOfFixedDatumRecords) ) ivarsEqual = false;
     if( ! (_numberOfVariableDatumRecords == rhs._numberOfVariableDatumRecords) ) ivarsEqual = false;
     if( ! (_fixedDatumRecords == rhs._fixedDatumRecords) ) ivarsEqual = false;
     if( ! (_variableDatumRecords == rhs._variableDatumRecords) ) ivarsEqual = false;

    return ivarsEqual;
 }

int CommentReliablePdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = SimulationManagementWithReliabilityFamilyPdu::getMarshalledSize();
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
