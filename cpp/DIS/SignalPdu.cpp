#include <DIS/SignalPdu.h> 

using namespace DIS;


SignalPdu::SignalPdu() : RadioCommunicationsFamilyPdu(),
   _entityId(), 
   _radioId(0), 
   _encodingScheme(0), 
   _tdlType(0), 
   _sampleRate(0), 
   _dataLength(0), 
   _samples(0), 
   _data()
{
    setPduType( 26 );
}

SignalPdu::~SignalPdu()
{
}

EntityID& SignalPdu::getEntityId() 
{
    return _entityId;
}

const EntityID& SignalPdu::getEntityId() const
{
    return _entityId;
}

void SignalPdu::setEntityId(const EntityID &pX)
{
    _entityId = pX;
}

unsigned short SignalPdu::getRadioId() const
{
    return _radioId;
}

void SignalPdu::setRadioId(unsigned short pX)
{
    _radioId = pX;
}

unsigned short SignalPdu::getEncodingScheme() const
{
    return _encodingScheme;
}

void SignalPdu::setEncodingScheme(unsigned short pX)
{
    _encodingScheme = pX;
}

unsigned short SignalPdu::getTdlType() const
{
    return _tdlType;
}

void SignalPdu::setTdlType(unsigned short pX)
{
    _tdlType = pX;
}

unsigned int SignalPdu::getSampleRate() const
{
    return _sampleRate;
}

void SignalPdu::setSampleRate(unsigned int pX)
{
    _sampleRate = pX;
}

unsigned short SignalPdu::getDataLength() const
{
    return _dataLength;
}

void SignalPdu::setDataLength(unsigned short pX)
{
    _dataLength = pX;
}

unsigned short SignalPdu::getSamples() const
{
    return _samples;
}

void SignalPdu::setSamples(unsigned short pX)
{
    _samples = pX;
}

OneByteChunk& SignalPdu::getData() 
{
    return _data;
}

const OneByteChunk& SignalPdu::getData() const
{
    return _data;
}

void SignalPdu::setData(const OneByteChunk &pX)
{
    _data = pX;
}

void SignalPdu::marshal(DataStream& dataStream) const
{
    RadioCommunicationsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _entityId.marshal(dataStream);
    dataStream << _radioId;
    dataStream << _encodingScheme;
    dataStream << _tdlType;
    dataStream << _sampleRate;
    dataStream << _dataLength;
    dataStream << _samples;
    _data.marshal(dataStream);
}

void SignalPdu::unmarshal(DataStream& dataStream)
{
    RadioCommunicationsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _entityId.unmarshal(dataStream);
    dataStream >> _radioId;
    dataStream >> _encodingScheme;
    dataStream >> _tdlType;
    dataStream >> _sampleRate;
    dataStream >> _dataLength;
    dataStream >> _samples;
    _data.unmarshal(dataStream);
}


bool SignalPdu::operator ==(const SignalPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = RadioCommunicationsFamilyPdu::operator==(rhs);

     if( ! (_entityId == rhs._entityId) ) ivarsEqual = false;
     if( ! (_radioId == rhs._radioId) ) ivarsEqual = false;
     if( ! (_encodingScheme == rhs._encodingScheme) ) ivarsEqual = false;
     if( ! (_tdlType == rhs._tdlType) ) ivarsEqual = false;
     if( ! (_sampleRate == rhs._sampleRate) ) ivarsEqual = false;
     if( ! (_dataLength == rhs._dataLength) ) ivarsEqual = false;
     if( ! (_samples == rhs._samples) ) ivarsEqual = false;
     if( ! (_data == rhs._data) ) ivarsEqual = false;

    return ivarsEqual;
 }

int SignalPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = RadioCommunicationsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _entityId.getMarshalledSize();  // _entityId
   marshalSize = marshalSize + 2;  // _radioId
   marshalSize = marshalSize + 2;  // _encodingScheme
   marshalSize = marshalSize + 2;  // _tdlType
   marshalSize = marshalSize + 4;  // _sampleRate
   marshalSize = marshalSize + 2;  // _dataLength
   marshalSize = marshalSize + 2;  // _samples
   marshalSize = marshalSize + _data.getMarshalledSize();  // _data
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
