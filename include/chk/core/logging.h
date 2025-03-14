#pragma once

#ifndef LOG_BASEDIR
#define LOG_BASEDIR NULL
#endif

#include <chk/core/types.h>

typedef enum LogSev {
  LogSev_Unknown = 0,

  LogSev_Debug,
  LogSev_Trace,
  LogSev_Info,
  LogSev_Warn,
  LogSev_Error,
  LogSev_Fatal,

  LogSev_Count,
} LogSev;

CStr LogSev_ToString(LogSev sev);
CStr LogSev_ToANSICode(LogSev sev);

B32 Log_Raw(LogSev sev, CStr msg, CStr base, CStr file, S32 line, CStr func);
B32 Log_RawF(LogSev sev, CStr msg, CStr base, CStr file, S32 line, CStr func,
             ...);
B32 Log_RawV(LogSev sev, CStr msg, CStr base, CStr file, S32 line, CStr func,
             VaArgs args);

#define Log_Debug(msg, ...)                                                    \
  Log_Raw##__VA_OPT__(F)(LogSev_Debug, msg, LOG_BASEDIR, __FILE__, __LINE__,   \
                         __func__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Trace(msg, ...)                                                    \
  Log_Raw##__VA_OPT__(F)(LogSev_Trace, msg, LOG_BASEDIR, __FILE__, __LINE__,   \
                         __func__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Info(msg, ...)                                                     \
  Log_Raw##__VA_OPT__(F)(LogSev_Info, msg, LOG_BASEDIR, __FILE__, __LINE__,    \
                         __func__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Warn(msg, ...)                                                     \
  Log_Raw##__VA_OPT__(F)(LogSev_Warn, msg, LOG_BASEDIR, __FILE__, __LINE__,    \
                         __func__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Error(msg, ...)                                                    \
  Log_Raw##__VA_OPT__(F)(LogSev_Error, msg, LOG_BASEDIR, __FILE__, __LINE__,   \
                         __func__ __VA_OPT__(, ) __VA_ARGS__)
#define Log_Fatal(msg, ...)                                                    \
  Log_Raw##__VA_OPT__(F)(LogSev_Fatal, msg, LOG_BASEDIR, __FILE__, __LINE__,   \
                         __func__ __VA_OPT__(, ) __VA_ARGS__)
