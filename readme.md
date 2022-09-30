# idiotlog

C++ simplistic header-only logging library ~~of the idiots, by the idiots, for the idiots~~.

## Features

This logging library only passes through every parameter to `std::cout`. Logging to file is ***NOT*** supported because idiots don't need these.

Yes, you have to do line breaks by yourself.

This library provides:

* An `idiot_logger` with only an on/off switch

  Example:

```c++
  idiotlog::idiot_logger logger;

  logger << "I am an " << 'i' << 'd' << 'i' << 0 << "t_logger\n";
  // "I am an idi0t_logger\n"

  logger.disable();                   // turn it off
```

* A `too_complex_logger` with an on/off switch and logging level control
  - logging level is represented as integers
  - the logger only output logs when the log's level is >= the logger's level
  - optional date/time and log level information in output
    * If this feature seems overkill to your project, define macro `IDIOTLOG_KEEP_IT_SIMPLE` to disable it absolutely
  - it can also function like an idiot_logger if you desire so

  Example:

```c++
  idiotlog::too_complex_logger log(true, 5); // setting the logger's level to 5 and enable it
  log << "I am an idiot_logger\n";
  // "I am an idiot_logger\n" (outputs regardless of level, but with respect to on/off)
  log.level(0) << "I am complex!\n";
  // outputs nothing, because the log's level is 0 which is < 5
  log.level(5) << "I am complex!\n";
  // "I am complex\n"
  // or
  log(5) << "I am complex!\n";
  // "I am complex\n"

  log.verbose(true);                  // give me more detail
  log(5) << "I am complex!\n";
  // "1953-06-15T11:45:14+0800 [5] I am complex!\n"
  log << "I am an idiot_logger\n";
  // "1953-06-15T11:45:14+0800 I am an idiot_logger\n"
```

## Compatibility

Timestamps will contain timezone information (`+0800` as in `1953-06-15T11:45:14+0800`) only when you compile it on C++11 or newer standards.

Otherwise, it may be simply `1953-06-15T11:45:14`. I don't know. I haven't tested this very heavily.

## Disclaimer

This library is written in 45 minutes and comes with absolutely no warranty. (Even this `readme.md` took me 30 minutes.) I didn't review the code thoroughly. It is heavily un-tested and may have bugs that nobody knows. It should only be used in simple and unimportant projects where acting like an idiot won't cause any problem.

## License

Copyright (C) 2022 SaltfishAmi <<ami@saltfish.moe>>

This library is free software. You can redistribute it and/or modify it under the terms of the Do What The Fuck You Want To Public License, Version 2, as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.