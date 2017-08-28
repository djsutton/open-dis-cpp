#ifndef DATAQUERYPDU_H
#define DATAQUERYPDU_H

#include <DIS/UnsignedIntegerWrapper.h>
#include <DIS/UnsignedIntegerWrapper.h>
#include <DIS/SimulationManagementFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Section 5.3.6.8. Request for data from an entity. COMPLETE

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO DataQueryPdu : public SimulationManagementFamilyPdu
{
protected:
  /** ID of request */
  unsigned int _requestID; 

  /** time issues between issues of Data PDUs. Zero means send once only. */
  unsigned int _timeInterval; 

  /** Number of fixed datum records */
  unsigned int _numberOfFixedDatumRecords; 

  /** Number of variable datum records */
  unsigned int _numberOfVariableDatumRecords; 

  /** variable length list of fixed datums */
  UnsignedIntegerWrapper _fixedDatums; 

  /** variable length list of variable length datums */
  UnsignedIntegerWrapper _variableDatums; 


 public:
    DataQueryPdu();
    virtual ~DataQueryPdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned int getRequestID() const; 
    void setRequestID(unsigned int pX); 

    unsigned int getTimeInterval() const; 
    void setTimeInterval(unsigned int pX); 

    unsigned int getNumberOfFixedDatumRecords() const; 
    void setNumberOfFixedDatumRecords(unsigned int pX); 

    unsigned int getNumberOfVariableDatumRecords() const; 
    void setNumberOfVariableDatumRecords(unsigned int pX); 

    UnsignedIntegerWrapper& getFixedDatums(); 
    const UnsignedIntegerWrapper&  getFixedDatums() const; 
    void setFixedDatums(const UnsignedIntegerWrapper    &pX);

    UnsignedIntegerWrapper& getVariableDatums(); 
    const UnsignedIntegerWrapper&  getVariableDatums() const; 
    void setVariableDatums(const UnsignedIntegerWrapper    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const DataQueryPdu& rhs) const;
};
}

#endif
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
