#include <chk/core/format.h>
#include <chk/core/logging.h>
#include <chk/core/utils.h>

#include <cwalk.h>

#include <stdio.h>

CStr LogSev_ToString(LogSev sev) {
  CStr result = NULL;

  switch (sev) {
  default:
  case LogSev_Unknown:
    result = "Unknown";
    break;
  case LogSev_Debug:
    result = "Debug";
    break;
  case LogSev_Trace:
    result = "Trace";
    break;
  case LogSev_Info:
    result = "Info";
    break;
  case LogSev_Warn:
    result = "Warn";
    break;
  case LogSev_Error:
    result = "Error";
    break;
  case LogSev_Fatal:
    result = "Fatal";
    break;
  }

  return result;
}

CStr LogSev_ToANSICode(LogSev sev) {
  CStr result = NULL;

  switch (sev) {
  default:
  case LogSev_Unknown:
    result = "\x1b[2;39m"; // Faded Gray
    break;
  case LogSev_Debug:
    result = "\x1b[2;39m"; // Faded Gray
    break;
  case LogSev_Trace:
    result = "\x1b[2;34m"; // Faded Blue
    break;
  case LogSev_Info:
    result = "\x1b[34m"; // Blue
    break;
  case LogSev_Warn:
    result = "\x1b[33m"; // Yellow
    break;
  case LogSev_Error:
    result = "\x1b[31m"; // Red
    break;
  case LogSev_Fatal:
    result = "\x1b[1;31m"; // Bold Red
    break;
  }

  return result;
}

B32 Log_Raw(LogSev sev, CStr msg, CStr base, CStr file, S32 line, CStr func) {
  static Char buf[1024];
  static Char rel_buf[260];

  B32 result = false;

  // Short file path
  CStr rel_file = file;
  if (base) {
    S32 written = cwk_path_get_relative(base, file, rel_buf, CountOf(rel_buf));
    if (written && written <= CountOf(rel_buf)) {
      rel_file = rel_buf;
    }
  }

  // Log Severity stuff
  CStr sev_name = LogSev_ToString(sev);
  CStr sev_code = LogSev_ToANSICode(sev);
  CStr col_beg = sev_code ? sev_code : "";
  CStr col_end = sev_code ? "\x1b[0m" : "";

  // Format the message
  result = Str_Format(buf, CountOf(buf), "%s[%s] [%s:%d:%s] %s%s\n", //
                      col_beg, sev_name, rel_file, line, func, msg, col_end);
  if (result) {
    fputs(buf, stderr);
  }

  return result;
}

B32 Log_RawF(LogSev sev, CStr msg, CStr base, CStr file, S32 line, CStr func,
             ...) {
  B32 result = false;

  VaArgs args;
  va_start(args, func);
  result = Log_RawV(sev, msg, base, file, line, func, args);
  va_end(args);

  return result;
}

B32 Log_RawV(LogSev sev, CStr msg, CStr base, CStr file, S32 line, CStr func,
             VaArgs args) {
  static Char buf[1024];

  B32 result = false;

  VaArgs args_copy;
  va_copy(args_copy, args);
  result = Str_FormatV(buf, CountOf(buf), msg, args_copy);
  va_end(args_copy);

  result = result && Log_Raw(sev, buf, base, file, line, func);

  return result;
}
