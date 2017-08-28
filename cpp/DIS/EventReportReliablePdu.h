#ifndef EVENTREPORTRELIABLEPDU_H
#define EVENTREPORTRELIABLEPDU_H

#include <DIS/FixedDatum.h>
#include <DIS/VariableDatum.h>
#include <DIS/SimulationManagementWithReliabilityFamilyPdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Section 5.3.12.11: reports the occurance of a significatnt event to the simulation manager. Needs manual     intervention to fix padding in variable datums. UNFINISHED.

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO EventReportReliablePdu : public SimulationManagementWithReliabilityFamilyPdu
{
protected:
  /** Event type */
  unsigned short _eventType; 

  /** padding */
  unsigned int _pad1; 

  /** Fixed datum record count */
  unsigned int _numberOfFixedDatumRecords; 

  /** variable datum record count */
  unsigned int _numberOfVariableDatumRecords; 

  /** Fixed datum records */
  FixedDatum _fixedDatumRecords; 

  /** Variable datum records */
  VariableDatum _variableDatumRecords; 


 public:
    EventReportReliablePdu();
    virtual ~EventReportReliablePdu();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    unsigned short getEventType() const; 
    void setEventType(unsigned short pX); 

    unsigned int getPad1() const; 
    void setPad1(unsigned int pX); 

    unsigned int getNumberOfFixedDatumRecords() const; 
    void setNumberOfFixedDatumRecords(unsigned int pX); 

    unsigned int getNumberOfVariableDatumRecords() const; 
    void setNumberOfVariableDatumRecords(unsigned int pX); 

    FixedDatum& getFixedDatumRecords(); 
    const FixedDatum&  getFixedDatumRecords() const; 
    void setFixedDatumRecords(const FixedDatum    &pX);

    VariableDatum& getVariableDatumRecords(); 
    const VariableDatum&  getVariableDatumRecords() const; 
    void setVariableDatumRecords(const VariableDatum    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const EventReportReliablePdu& rhs) const;
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
