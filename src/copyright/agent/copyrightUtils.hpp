/*
 * Copyright (C) 2014, Siemens AG
 * Author: Daniele Fognini, Johannes Najjar
 *
 * This program is free software; you can redistribute it and/or modify it under the terms of the GNU General Public License version 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along with this program; if not, write to the Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 */

#ifndef COPYRIGHTUTILS_HPP
#define COPYRIGHTUTILS_HPP

#include "identity.hpp"

#define AGENT_NAME IDENTITY ///< the name of the agent, used to get agent key
#define AGENT_DESC IDENTITY " agent" ///< what program this is
#define AGENT_ARS  IDENTITY "_ars"

#include <string>
#include <vector>

#include "regexMatcher.hpp"
#include "copyrightState.hpp"
#include "files.hpp"
#include "regTypes.hpp"
#include "database.hpp"
#include "cleanEntries.hpp"

extern "C"{
#include "libfossology.h"
}

void queryAgentId(int& agent, PGconn* dbConn);

void bail(CopyrightState* state, int exitval);

int writeARS(CopyrightState* state, int arsId, long uploadId, int success);

CopyrightState* getState(DbManager* dbManager, int verbosity);

void fillMatchers(CopyrightState* state);

std::vector<CopyrightMatch> matchStringToRegexes(const std::string& content, std::vector<RegexMatcher> matchers);

bool saveToDatabase(const std::vector<CopyrightMatch>& matches, CopyrightState* state, long pFileId);

void matchFileWithLicenses(long pFileId, fo::File* file, CopyrightState* state);

void matchPFileWithLicenses(CopyrightState* state, long pFileId);

bool processUploadId(CopyrightState* state, int uploadId);

#endif // COPYRIGHTUTILS_HPP
