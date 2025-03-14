#pragma once

#define CALLBACK_FN(name) void name(void *user_ptr)
typedef CALLBACK_FN(Callback);
