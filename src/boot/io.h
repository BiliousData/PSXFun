/*
  This Source Code Form is subject to the terms of the Mozilla Public
  License, v. 2.0. If a copy of the MPL was not distributed with this
  file, You can obtain one at http://mozilla.org/MPL/2.0/.
*/

#ifndef PSXF_GUARD_IO_H
#define PSXF_GUARD_IO_H

#include "psx.h"

typedef u32* IO_Data;

//IO functions
void IO_Init(void);
void IO_Quit(void);
void IO_FindFile(CdlFILE *file, const char *path);
void IO_SeekFile(CdlFILE *file);
IO_Data IO_ReadFile(CdlFILE *file);
IO_Data IO_Read(const char *path);

#endif
