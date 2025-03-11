/*
* Copyright (c) 2024 Diago Lima
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef SYS_LASTERROR_HPP
#define SYS_LASTERROR_HPP
#include <Sys/String.hpp>
#include <Core/Platform.hpp>

namespace n19::sys {
#ifdef N19_WIN32
  using ErrorCode = DWORD;
#else
  using ErrorCode = int;
#endif
  NODISCARD_ auto last_error() -> String;
  NODISCARD_ auto translate_native_error(ErrorCode) -> String;
}

#endif //SYS_LASTERROR_HPP
