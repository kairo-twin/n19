/*
* Copyright (c) 2024 Diago Lima
* All rights reserved.
*
* This software is licensed under the BSD 3-Clause "New" or "Revised" license
* found in the LICENSE file in the root directory of this project's source tree.
*/

#ifndef CONMANIP_H
#define CONMANIP_H
#include <Core/Fmt.h>
#include <Core/Concepts.h>
#include <string>
#include <cstdint>
#include <print>

namespace n19 {
  enum class Con : uint16_t {
    Reset      = 0,
    Bold       = 1,
    Underline  = 4,
    Green      = 32,
    Yellow     = 33,
    Blue       = 34,
    Magenta    = 35,
    Cyan       = 36,
    White      = 37,
    Red        = 91,
  };

  #if defined(N19_WIN32)
  auto are_vsequences_enabled()  -> bool;
  auto enable_vsequences()       -> void;
  auto maybe_enable_vsequences() -> void;
  #endif

  template<::n19::AreAll<n19::Con> ...Args>
  auto manip_string(Args... values) -> std::string;

  template<::n19::AreAll<n19::Con> ...Args>
  auto set_console(Args... values) -> void;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<::n19::AreAll<n19::Con> ...Args>
auto n19::set_console(Args... values) -> void {
  #if defined(N19_WIN32)
    maybe_enable_vsequences();
  #endif

  const uint16_t to_u16[] = {
    (static_cast<uint16_t>(values))...
  };

  for(const auto& val : to_u16)
    std::print("\x1b[{}m", val);
}

template<::n19::AreAll<n19::Con> ...Args>
auto n19::manip_string(Args... values) -> std::string {
  #if defined(N19_WIN32)
    maybe_enable_vsequences();
  #endif

  std::string buff;
  const uint16_t to_u16[] = {
    (static_cast<uint16_t>(values))...
  };

  for(const auto& val : to_u16)
    buff += fmt("\x1b[{}m", val);

  return buff;
}

#endif //CONMANIP_H
