/* idiotlog - C++ header-only logging for idiots like me
 *
 * Copyright (C) 2022 Tianjian Hu <i@tianjian.hu>
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
  void set_level(int level) { level_ = level; }
  int get_level() const { return level_; }
public:
  template <class Coutable>
  too_complex_logger const & operator<<(Coutable const & msg) const {
    if (enable_) {
      std::cout << msg;
    }

    return *this;
  }

  idiot_logger const & level(int level) const {
    if (!enable_ || level < level_) {
      return dummy_logger_;
    }

    return idiot_logger_;
  }
};

} // namespace idiotlog

#endif // IDIOTLOG_HPP_