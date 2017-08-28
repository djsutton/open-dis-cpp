#include <DIS/PduStream.h> 

using namespace DIS;


PduStream::PduStream():
   _shortDescription(0), 
   _longDescription(0), 
   _personRecording(0), 
   _authorEmail(0), 
   _startTime(0), 
   _stopTime(0), 
   _pduCount(0), 
   _pdusInStream()
{
}

PduStream::~PduStream()
{
}

char PduStream::getShortDescription() const
{
    return _shortDescription;
}

void PduStream::setShortDescription(char pX)
{
    _shortDescription = pX;
}

char PduStream::getLongDescription() const
{
    return _longDescription;
}

void PduStream::setLongDescription(char pX)
{
    _longDescription = pX;
}

char PduStream::getPersonRecording() const
{
    return _personRecording;
}

void PduStream::setPersonRecording(char pX)
{
    _personRecording = pX;
}

char PduStream::getAuthorEmail() const
{
    return _authorEmail;
}

void PduStream::setAuthorEmail(char pX)
{
    _authorEmail = pX;
}

long PduStream::getStartTime() const
{
    return _startTime;
}

void PduStream::setStartTime(long pX)
{
    _startTime = pX;
}

long PduStream::getStopTime() const
{
    return _stopTime;
}

void PduStream::setStopTime(long pX)
{
    _stopTime = pX;
}

unsigned int PduStream::getPduCount() const
{
    return _pduCount;
}

void PduStream::setPduCount(unsigned int pX)
{
    _pduCount = pX;
}

Pdu& PduStream::getPdusInStream() 
{
    return _pdusInStream;
}

const Pdu& PduStream::getPdusInStream() const
{
    return _pdusInStream;
}

void PduStream::setPdusInStream(const Pdu &pX)
{
    _pdusInStream = pX;
}

void PduStream::marshal(DataStream& dataStream) const
{
    dataStream << _shortDescription;
    dataStream << _longDescription;
    dataStream << _personRecording;
    dataStream << _authorEmail;
    dataStream << _startTime;
    dataStream << _stopTime;
    dataStream << _pduCount;
    _pdusInStream.marshal(dataStream);
}

void PduStream::unmarshal(DataStream& dataStream)
{
    dataStream >> _shortDescription;
    dataStream >> _longDescription;
    dataStream >> _personRecording;
    dataStream >> _authorEmail;
    dataStream >> _startTime;
    dataStream >> _stopTime;
    dataStream >> _pduCount;
    _pdusInStream.unmarshal(dataStream);
}


bool PduStream::operator ==(const PduStream& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_shortDescription == rhs._shortDescription) ) ivarsEqual = false;
     if( ! (_longDescription == rhs._longDescription) ) ivarsEqual = false;
     if( ! (_personRecording == rhs._personRecording) ) ivarsEqual = false;
     if( ! (_authorEmail == rhs._authorEmail) ) ivarsEqual = false;
     if( ! (_startTime == rhs._startTime) ) ivarsEqual = false;
     if( ! (_stopTime == rhs._stopTime) ) ivarsEqual = false;
     if( ! (_pduCount == rhs._pduCount) ) ivarsEqual = false;
     if( ! (_pdusInStream == rhs._pdusInStream) ) ivarsEqual = false;

    return ivarsEqual;
 }

int PduStream::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _shortDescription
   marshalSize = marshalSize + 1;  // _longDescription
   marshalSize = marshalSize + 1;  // _personRecording
   marshalSize = marshalSize + 1;  // _authorEmail
   marshalSize = marshalSize + 8;  // _startTime
   marshalSize = marshalSize + 8;  // _stopTime
   marshalSize = marshalSize + 4;  // _pduCount
   marshalSize = marshalSize + _pdusInStream.getMarshalledSize();  // _pdusInStream
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
