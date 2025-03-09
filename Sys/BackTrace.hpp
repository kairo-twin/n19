/*
* Copyright (c) 2025 Diago Lima
* SPDX-License-Identifier: BSD-3-Clause
*/

#ifndef N19_BACKTRACE_HPP
#define N19_BACKTRACE_HPP
#define N19_BACKTRACE_MAX_FRAMES 42
#include <Core/Platform.hpp>
#include <Core/Result.hpp>
#include <Sys/File.hpp>
#include <Sys/IODevice.hpp>
#include <IO/Console.hpp>
#include <array>
#include <cstdint>
#include <utility>
BEGIN_NAMESPACE(n19::sys);

struct BacktraceFrame {
  std::string name_;
  void* addr_ = nullptr;
};

struct BackTrace {
  static auto dump_to(OStream& = outs()) -> Result<void>;
  static auto dump_to(File& file)        -> Result<void>;

  NODISCARD_ auto get() -> Result<void>;
  std::array<BacktraceFrame, N19_BACKTRACE_MAX_FRAMES> frames_;
};

END_NAMESPACE(n19::sys);
#endif //N19_BACKTRACE_HPP
