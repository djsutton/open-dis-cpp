#include <DIS/Marking.h> 

#include <cstring>

using namespace DIS;


Marking::Marking():
   _characterSet(0)
{
     // Initialize fixed length array
     for(int idx = 0; idx < sizeof(_characters); idx++)
     {
         _characters[idx] = 0;
     }

}

Marking::~Marking()
{
}

unsigned char Marking::getCharacterSet() const
{
    return _characterSet;
}

void Marking::setCharacterSet(unsigned char pX)
{
    _characterSet = pX;
}

char* Marking::getCharacters() 
{
    return _characters;
}

const char* Marking::getCharacters() const
{
    return _characters;
}

void Marking::setCharacters(const char* x)
{
   for(int i = 0; i < sizeof(_characters); i++)
   {
        _characters[i] = x[i];
   }
}

// An alternate method to set the value if this could be a string. This is not strictly comnpliant with the DIS standard.
void Marking::setByStringCharacters(const char* x)
{
   std::strncpy(_characters, x, sizeof(_characters)-1);
   _characters[sizeof(_characters) -1] = '\0';
}

void Marking::marshal(DataStream& dataStream) const
{
    dataStream << _characterSet;

     for(size_t idx = 0; idx < sizeof(_characters); idx++)
     {
        dataStream << _characters[idx];
     }

}

void Marking::unmarshal(DataStream& dataStream)
{
    dataStream >> _characterSet;

     for(size_t idx = 0; idx < sizeof(_characters); idx++)
     {
        dataStream >> _characters[idx];
     }

}


bool Marking::operator ==(const Marking& rhs) const
 {
     bool ivarsEqual = true;

     if( ! (_characterSet == rhs._characterSet) ) ivarsEqual = false;

     for(char idx = 0; idx < sizeof(_characters); idx++)
     {
          if(!(_characters[idx] == rhs._characters[idx]) ) ivarsEqual = false;
     }


    return ivarsEqual;
 }

int Marking::getMarshalledSize() const
{
   int marshalSize = 0;

   marshalSize = marshalSize + 1;  // _characterSet
   marshalSize = marshalSize + sizeof(_characters);  // _characters
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
