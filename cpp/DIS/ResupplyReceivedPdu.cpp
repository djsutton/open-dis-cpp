#include <DIS/ResupplyReceivedPdu.h> 

using namespace DIS;


ResupplyReceivedPdu::ResupplyReceivedPdu() : LogisticsFamilyPdu(),
   _receivingEntityID(), 
   _supplyingEntityID(), 
   _numberOfSupplyTypes(0), 
   _padding1(0), 
   _padding2(0), 
   _supplies()
{
    setPduType( 7 );
}

ResupplyReceivedPdu::~ResupplyReceivedPdu()
{
}

EntityID& ResupplyReceivedPdu::getReceivingEntityID() 
{
    return _receivingEntityID;
}

const EntityID& ResupplyReceivedPdu::getReceivingEntityID() const
{
    return _receivingEntityID;
}

void ResupplyReceivedPdu::setReceivingEntityID(const EntityID &pX)
{
    _receivingEntityID = pX;
}

EntityID& ResupplyReceivedPdu::getSupplyingEntityID() 
{
    return _supplyingEntityID;
}

const EntityID& ResupplyReceivedPdu::getSupplyingEntityID() const
{
    return _supplyingEntityID;
}

void ResupplyReceivedPdu::setSupplyingEntityID(const EntityID &pX)
{
    _supplyingEntityID = pX;
}

unsigned char ResupplyReceivedPdu::getNumberOfSupplyTypes() const
{
    return _numberOfSupplyTypes;
}

void ResupplyReceivedPdu::setNumberOfSupplyTypes(unsigned char pX)
{
    _numberOfSupplyTypes = pX;
}

short ResupplyReceivedPdu::getPadding1() const
{
    return _padding1;
}

void ResupplyReceivedPdu::setPadding1(short pX)
{
    _padding1 = pX;
}

char ResupplyReceivedPdu::getPadding2() const
{
    return _padding2;
}

void ResupplyReceivedPdu::setPadding2(char pX)
{
    _padding2 = pX;
}

SupplyQuantity& ResupplyReceivedPdu::getSupplies() 
{
    return _supplies;
}

const SupplyQuantity& ResupplyReceivedPdu::getSupplies() const
{
    return _supplies;
}

void ResupplyReceivedPdu::setSupplies(const SupplyQuantity &pX)
{
    _supplies = pX;
}

void ResupplyReceivedPdu::marshal(DataStream& dataStream) const
{
    LogisticsFamilyPdu::marshal(dataStream); // Marshal information in superclass first
    _receivingEntityID.marshal(dataStream);
    _supplyingEntityID.marshal(dataStream);
    dataStream << _numberOfSupplyTypes;
    dataStream << _padding1;
    dataStream << _padding2;
    _supplies.marshal(dataStream);
}

void ResupplyReceivedPdu::unmarshal(DataStream& dataStream)
{
    LogisticsFamilyPdu::unmarshal(dataStream); // unmarshal information in superclass first
    _receivingEntityID.unmarshal(dataStream);
    _supplyingEntityID.unmarshal(dataStream);
    dataStream >> _numberOfSupplyTypes;
    dataStream >> _padding1;
    dataStream >> _padding2;
    _supplies.unmarshal(dataStream);
}


bool ResupplyReceivedPdu::operator ==(const ResupplyReceivedPdu& rhs) const
 {
     bool ivarsEqual = true;

     ivarsEqual = LogisticsFamilyPdu::operator==(rhs);

     if( ! (_receivingEntityID == rhs._receivingEntityID) ) ivarsEqual = false;
     if( ! (_supplyingEntityID == rhs._supplyingEntityID) ) ivarsEqual = false;
     if( ! (_numberOfSupplyTypes == rhs._numberOfSupplyTypes) ) ivarsEqual = false;
     if( ! (_padding1 == rhs._padding1) ) ivarsEqual = false;
     if( ! (_padding2 == rhs._padding2) ) ivarsEqual = false;
     if( ! (_supplies == rhs._supplies) ) ivarsEqual = false;

    return ivarsEqual;
 }

int ResupplyReceivedPdu::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = LogisticsFamilyPdu::getMarshalledSize();
   marshalSize = marshalSize + _receivingEntityID.getMarshalledSize();  // _receivingEntityID
   marshalSize = marshalSize + _supplyingEntityID.getMarshalledSize();  // _supplyingEntityID
   marshalSize = marshalSize + 1;  // _numberOfSupplyTypes
   marshalSize = marshalSize + 2;  // _padding1
   marshalSize = marshalSize + 1;  // _padding2
   marshalSize = marshalSize + _supplies.getMarshalledSize();  // _supplies
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
