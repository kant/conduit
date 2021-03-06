//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//
// Copyright (c) 2014-2019, Lawrence Livermore National Security, LLC.
// 
// Produced at the Lawrence Livermore National Laboratory
// 
// LLNL-CODE-666778
// 
// All rights reserved.
// 
// This file is part of Conduit. 
// 
// For details, see: http://software.llnl.gov/conduit/.
// 
// Please also read conduit/LICENSE
// 
// Redistribution and use in source and binary forms, with or without 
// modification, are permitted provided that the following conditions are met:
// 
// * Redistributions of source code must retain the above copyright notice, 
//   this list of conditions and the disclaimer below.
// 
// * Redistributions in binary form must reproduce the above copyright notice,
//   this list of conditions and the disclaimer (as noted below) in the
//   documentation and/or other materials provided with the distribution.
// 
// * Neither the name of the LLNS/LLNL nor the names of its contributors may
//   be used to endorse or promote products derived from this software without
//   specific prior written permission.
// 
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL LAWRENCE LIVERMORE NATIONAL SECURITY,
// LLC, THE U.S. DEPARTMENT OF ENERGY OR CONTRIBUTORS BE LIABLE FOR ANY
// DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL 
// DAMAGES  (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
// OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
// HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, 
// STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING
// IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE 
// POSSIBILITY OF SUCH DAMAGE.
// 
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~//

//-----------------------------------------------------------------------------
///
/// file: conduit_relay_io.hpp
///
//-----------------------------------------------------------------------------


#ifndef CONDUIT_RELAY_IO_HPP
#define CONDUIT_RELAY_IO_HPP

//-----------------------------------------------------------------------------
// conduit lib include 
//-----------------------------------------------------------------------------
#include "conduit.hpp"
#include "conduit_relay_exports.h"
#include "conduit_relay_config.h"

//-----------------------------------------------------------------------------
// -- begin conduit:: --
//-----------------------------------------------------------------------------
namespace conduit
{

//-----------------------------------------------------------------------------
// -- begin conduit::relay --
//-----------------------------------------------------------------------------
namespace relay
{

//-----------------------------------------------------------------------------
// -- begin conduit::relay::io --
//-----------------------------------------------------------------------------
namespace io
{

//-----------------------------------------------------------------------------
/// The about methods construct human readable info about how relay io was
/// configured.
//-----------------------------------------------------------------------------
std::string CONDUIT_RELAY_API about();
void        CONDUIT_RELAY_API about(conduit::Node &res);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API identify_protocol(const std::string &path,
                                         std::string &io_type);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API initialize();

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API finalize();

///
/// ``save`` works like a 'set' to the file.
///

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API save(const Node &node,
                            const std::string &path);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API save(const Node &node,
                            const std::string &path,
                            const std::string &protocol);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API save(const Node &node,
                            const std::string &path,
                            const std::string &protocol,
                            const Node &options);

///
/// ``save_merged`` works like an update to the file.
///

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API save_merged(const Node &node,
                                   const std::string &path);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API save_merged(const Node &node,
                                   const std::string &path,
                                   const std::string &protocol);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API save_merged(const Node &node,
                                   const std::string &path,
                                   const std::string &protocol,
                                   const Node &options);


///
/// ``add_step`` adds a new time step of data to the file.
///

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API add_step(const Node &node,
                                const std::string &path);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API add_step(const Node &node,
                                const std::string &path,
                                const std::string &protocol);


//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API add_step(const Node &node,
                                const std::string &path,
                                const std::string &protocol,
                                const Node &options);

///
/// ``load`` works like a 'set', the node is reset and then populated
///

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API load(const std::string &path,
                            Node &node);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API load(const std::string &path,
                            const std::string &protocol,
                            Node &node);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API load(const std::string &path,
                            const std::string &protocol,
                            const Node &options,
                            Node &node);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API load(const std::string &path,
                            const std::string &protocol,
                            int step,
                            int domain,
                            Node &node);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API load(const std::string &path,
                            const std::string &protocol,
                            int step,
                            int domain,
                            const Node &options,
                            Node &node);

///
/// ``load_merged`` works like an update, for the object case, entries are read
///  into the node. If the node is already in the OBJECT_T role, children are 
///  added
///

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API load_merged(const std::string &path,
                                   Node &node);

//-----------------------------------------------------------------------------
void CONDUIT_RELAY_API load_merged(const std::string &path,
                                   const std::string &protocol,
                                   Node &node);

///
/// ``query_number_of_steps`` return the number of steps.
///
//-----------------------------------------------------------------------------
int CONDUIT_RELAY_API query_number_of_steps(const std::string &path);

///
/// ``query_number_of_domains`` return the number of domains.
///
//-----------------------------------------------------------------------------
int CONDUIT_RELAY_API query_number_of_domains(const std::string &path);

}
//-----------------------------------------------------------------------------
// -- end conduit::relay::io --
//-----------------------------------------------------------------------------

}
//-----------------------------------------------------------------------------
// -- end conduit::relay --
//-----------------------------------------------------------------------------


}
//-----------------------------------------------------------------------------
// -- end conduit:: --
//-----------------------------------------------------------------------------


#endif

