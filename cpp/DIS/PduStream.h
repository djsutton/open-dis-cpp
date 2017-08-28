#ifndef PDUSTREAM_H
#define PDUSTREAM_H

#include <DIS/Pdu.h>
#include <DIS/DataStream.h>
#include <DIS/msLibMacro.h>


namespace DIS
{
// Non-DIS class, used to describe streams of PDUs when logging to SQL databases

// Copyright (c) 2007-2009, MOVES Institute, Naval Postgraduate School. All rights reserved. 
//
// @author DMcG, jkg

class EXPORT_MACRO PduStream
{
protected:
  /** short description of this PDU stream */
  char _shortDescription; 

  /** Longish description of this PDU stream */
  char _longDescription; 

  /** Name of person performing recording */
  char _personRecording; 

  /** Email of person performing recording */
  char _authorEmail; 

  /** Start time of recording, in Unix time */
  long _startTime; 

  /** stop time of recording, in Unix time */
  long _stopTime; 

  /** how many PDUs in this stream */
  unsigned int _pduCount; 

  /** variable length list of PDUs */
  Pdu _pdusInStream; 


 public:
    PduStream();
    virtual ~PduStream();

    virtual void marshal(DataStream& dataStream) const;
    virtual void unmarshal(DataStream& dataStream);

    char getShortDescription() const; 
    void setShortDescription(char pX); 

    char getLongDescription() const; 
    void setLongDescription(char pX); 

    char getPersonRecording() const; 
    void setPersonRecording(char pX); 

    char getAuthorEmail() const; 
    void setAuthorEmail(char pX); 

    long getStartTime() const; 
    void setStartTime(long pX); 

    long getStopTime() const; 
    void setStopTime(long pX); 

    unsigned int getPduCount() const; 
    void setPduCount(unsigned int pX); 

    Pdu& getPdusInStream(); 
    const Pdu&  getPdusInStream() const; 
    void setPdusInStream(const Pdu    &pX);


virtual int getMarshalledSize() const;

     bool operator  ==(const PduStream& rhs) const;
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
