/* Copyright (c) 2006-2008, Universities Space Research Association (USRA).
*  All rights reserved.
*
* Redistribution and use in source and binary forms, with or without
* modification, are permitted provided that the following conditions are met:
*     * Redistributions of source code must retain the above copyright
*       notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright
*       notice, this list of conditions and the following disclaimer in the
*       documentation and/or other materials provided with the distribution.
*     * Neither the name of the Universities Space Research Association nor the
*       names of its contributors may be used to endorse or promote products
*       derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY USRA ``AS IS'' AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF
* MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
* DISCLAIMED. IN NO EVENT SHALL USRA BE LIABLE FOR ANY DIRECT, INDIRECT,
* INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
* BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
* OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
* ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
* TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
* USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

// Implementation of the ClientSocket class

#include "ClientSocket.h"
#include "SocketException.h"


ClientSocket::ClientSocket ( std::string host, uint16_t port )
{
   if ( ! Socket::create() )
   {
      throw SocketException ( "Could not create client socket." );
   }
   
   if ( ! Socket::connect ( host, port ) )
   {
      throw SocketException ( "Could not bind to port." );
   }
}

bool ClientSocket::send (char* msg, size_t size ) const
{
   return Socket::send(msg, size);
}


const ClientSocket& ClientSocket::operator << ( const char& c ) const
{
   char buff[] = {c, 0};
   std::string s(buff);

   if ( ! Socket::send ( s ) )
   {
      throw SocketException ( "Could not write to socket." );
   }
   
   return *this;
}


const ClientSocket& ClientSocket::operator << ( const std::string& s ) const
{
   if ( ! Socket::send ( s ) )
   {
      throw SocketException ( "Could not write to socket." );
   }
   
   return *this;
}

const ClientSocket& ClientSocket::operator >> ( std::string& s ) const
{
   if ( ! Socket::recv ( s ) )
   {
      throw SocketException ( "Could not read from socket." );
   }
   
   return *this;
}
