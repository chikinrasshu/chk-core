#pragma once

#include <chk/core/types.h>

B32 Str_Format(Str buf, Size size, CStr msg, ...);
B32 Str_FormatV(Str buf, Size size, CStr msg, VaArgs args);
