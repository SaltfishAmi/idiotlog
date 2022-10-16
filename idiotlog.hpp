/* idiotlog - C++ header-only logging for idiots like me
 *
 * Copyright (C) 2022 SaltfishAmi <ami@saltfish.moe>
 * This program is free software. It comes without any warranty, to
 * the extent permitted by applicable law. You can redistribute it
 * and/or modify it under the terms of the Do What The Fuck You Want
 * To Public License, Version 2, as published by Sam Hocevar. See
 * http://www.wtfpl.net/ for more details.
 * 
 */

#ifndef IDIOTLOG_HPP_
#define IDIOTLOG_HPP_
#pragma once

#if __cplusplus >= 201103L || (defined(_MSC_VER) && _MSC_VER >= 1900)
#define IDIOTLOG_CPP11 1
#endif 

// Turn this on, and yay! You disabled verbose outputting.
#ifndef IDIOTLOG_KEEP_IT_SIMPLE
#include <ctime>
#endif

#include <iostream>

namespace idiotlog {

class idiot_logger {
private:
  bool enable_;
public:
  idiot_logger(bool enable = true) : enable_(enable) {}
  void enable() { enable_ = true; }
  void disable() { enable_ = false; }
  bool enabled() const { return enable_; }
public:
  template <class Coutable>
  idiot_logger const & operator<<(Coutable const & msg) const {
    if (enable_) {
      std::cout << msg;
    }

    return *this;
  }
};

class too_complex_logger {
private:
  bool enable_;
  int level_;
#ifndef IDIOTLOG_KEEP_IT_SIMPLE
  bool verbose_;
#endif // IDIOTLOG_KEEP_IT_SIMPLE
  idiot_logger const idiot_logger_;
  idiot_logger const dummy_logger_;
public:
  too_complex_logger(int level = 0)
  : enable_(true), level_(level), idiot_logger_(true), dummy_logger_(false) {}
  too_complex_logger(bool enable, int level = 0)
  : enable_(enable), level_(level), idiot_logger_(true), dummy_logger_(false) {}
  void enable() { enable_ = true; }
  void disable() { enable_ = false; }
  bool enabled() const { return enable_; }
  void set_level(int level = 0) { level_ = level; }
  int get_level() const { return level_; }
#ifndef IDIOTLOG_KEEP_IT_SIMPLE
  bool verbose() const { return verbose_; }
  void verbose(bool verbose = true) { verbose_ = verbose; }
#endif // IDIOTLOG_KEEP_IT_SIMPLE

#ifndef IDIOTLOG_KEEP_IT_SIMPLE
private:
  std::string const timestamp() const {
    std::time_t const now = std::time(0);
    char buf[25] = {0};
#ifdef IDIOTLOG_CPP11
    std::strftime(buf, 25, "%Y-%m-%dT%H:%M:%S%z", std::localtime(&now)); // C++11
#else // IDIOTLOG_CPP11
    std::strftime(buf, 20, "%Y-%m-%dT%H:%M:%S", std::localtime(&now));
#endif // IDIOTLOG_CPP11
    buf[25] = 0;
    return std::string(buf);
  }
#endif // IDIOTLOG_KEEP_IT_SIMPLE

public:
  template <class Coutable>
  idiot_logger const & operator<<(Coutable const & msg) const {
    if (!enable_) {
      return dummy_logger_;
    }
#ifndef IDIOTLOG_KEEP_IT_SIMPLE
    if (verbose_) {
      idiot_logger_ << timestamp() << " ";
    }
#endif // IDIOTLOG_KEEP_IT_SIMPLE
    return (idiot_logger_ << msg);
  }

  idiot_logger const & level(int level) const {
    if (!enable_ || level < level_) {
      return dummy_logger_;
    }
#ifndef IDIOTLOG_KEEP_IT_SIMPLE
    if (verbose_) {
      idiot_logger_ << timestamp() << " [" << level << "] ";
    }
#endif // IDIOTLOG_KEEP_IT_SIMPLE
    return idiot_logger_;
  }

  idiot_logger const & operator()(int level) const {
    return this->level(level);
  }
};

} // namespace idiotlog

#endif // IDIOTLOG_HPP_