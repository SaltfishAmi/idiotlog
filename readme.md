# idiotlog

C++ simplistic header-only logging library ~~of the idiots, by the idiots, for the idiots~~.

## Features

This logging library only passes through every parameter to `std::cout`. Logging to file is ***NOT*** supported because idiots don't need these.

This library provides:

* An `idiot_logger` with only an on/off switch

  Example:

```c++
  idiotlog::idiot_logger logger;
  logger << "I am an " << 'i' << 'd' << 'i' << 0 << "t_logger\n";    // outputs "I am an idi0t_logger\n"
  logger.disable();                   // turn it off
```

* A `too_complex_logger` with an on/off switch and logging level control
  - logging level is represented as integers
  - the logger only output logs when the log's level is >= the logger's level
  - it can also function like an idiot_logger if you desire so

  Example:

```c++
  idiotlog::too_complex_logger log(true, 5); // setting the logger's level to 5 and enable it
  log << "I am an idiot_logger\n";    // outputs "I am an idiot_logger\n";
  log.level(0) << "I am complex!\n"   // outputs nothing, because the log's level is 0 which is < 5
  log.level(5) << "I am complex!\n"   // outputs "I am complex\n"
  log.level(6) << "I am complex!\n"   // outputs "I am complex\n"
  log.disable();                      // turn it off
```

## Roadmap

* Add optional timestamp and log level indicator to `too_complex_logger::level() << ` outputs

## Disclaimer

This library is written in 15 minutes and comes with absolutely no warranty. (Even this `readme.md` took me more than 15 minutes.) I didn't review the code thoroughly. It is heavily un-tested and may have bugs that nobody knows. It should only be used in simple and unimportant projects where acting like an idiot won't cause any problem.

## License

Copyright (C) 2022 SaltfishAmi <<ami@saltfish.moe>>

This library is free software. You can redistribute it and/or modify it under the terms of the Do What The Fuck You Want To Public License, Version 2, as published by Sam Hocevar. See http://www.wtfpl.net/ for more details.