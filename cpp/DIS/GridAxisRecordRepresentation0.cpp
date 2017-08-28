#include <DIS/GridAxisRecordRepresentation0.h> 

using namespace DIS;


GridAxisRecordRepresentation0::GridAxisRecordRepresentation0() : GridAxisRecord(),
   _numberOfBytes(0), 
   _dataValues()
{
}

GridAxisRecordRepresentation0::~GridAxisRecordRepresentation0()
{
}

unsigned short GridAxisRecordRepresentation0::getNumberOfBytes() const
{
    return _numberOfBytes;
}

void GridAxisRecordRepresentation0::setNumberOfBytes(unsigned short pX)
{
    _numberOfBytes = pX;
}

OneByteChunk& GridAxisRecordRepresentation0::getDataValues() 
{
    return _dataValues;
}

const OneByteChunk& GridAxisRecordRepresentation0::getDataValues() const
{
    return _dataValues;
}

void GridAxisRecordRepresentation0::setDataValues(const OneByteChunk &pX)
{
    _dataValues = pX;
}

void GridAxisRecordRepresentation0::marshal(DataStream& dataStream) const
{
    GridAxisRecord::marshal(dataStream); // Marshal information in superclass first
    dataStream << _numberOfBytes;
    _dataValues.marshal(dataStream);
}

void GridAxisRecordRepresentation0::unmarshal(DataStream& dataStream)
{
    GridAxisRecord::unmarshal(dataStream); // unmarshal information in superclass first
    dataStream >> _numberOfBytes;
    _dataValues.unmarshal(dataStream);
}


bool GridAxisRecordRepresentation0::operator ==(const GridAxisRecordRepresentation0& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = GridAxisRecord::operator==(rhs);

     if( ! (_numberOfBytes == rhs._numberOfBytes) ) ivarsEqual = false;
     if( ! (_dataValues == rhs._dataValues) ) ivarsEqual = false;

    return ivarsEqual;
 }

int GridAxisRecordRepresentation0::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = GridAxisRecord::getMarshalledSize();
   marshalSize = marshalSize + 2;  // _numberOfBytes
   marshalSize = marshalSize + _dataValues.getMarshalledSize();  // _dataValues
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
