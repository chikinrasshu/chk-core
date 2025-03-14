#include <chk/core/format.h>

#include <stdio.h>

B32 Str_Format(Str buf, Size size, CStr msg, ...) {
  B32 result = false;

  VaArgs args;
  va_start(args, msg);
  result = Str_FormatV(buf, size, msg, args);
  va_end(args);

  return result;
}

B32 Str_FormatV(Str buf, Size size, CStr msg, VaArgs args) {
  B32 result = false;

  VaArgs args_copy;
  va_copy(args_copy, args);
  Size written = vsnprintf(buf, size, msg, args);
  result = written && written <= size;
  va_end(args_copy);

  return result;
}
