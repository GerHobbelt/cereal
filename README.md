arduino-cereal
==============

This is a "port" of the [cereal](https://github.com/USCiLab/cereal) serialization library for Arduino.

Missing Features
================

At the moment, only binary archives are supported. Unless you need human-readable archives, this should not be a problem.

Installation
============

Cereal is a header-only library, so you can just copy the `cereal` folder into your project.

Alternatively, you can use the Arduino Library Manager to install the library from a zip of the latest release.

**IMPORTANT**: You will need to enable Runtime Type Information (RTTI). This is done simply by adding `-frtti` to the `compiler.cpp.flags` line in your `platform.local.txt` file. You can read more about the `platform.local.txt` file [here](https://arduino.github.io/arduino-cli/0.21/platform-specification/#platformlocaltxt). On Ubuntu, the file should be (created) located at `~/.arduino15/packages/<developer>/hardware/<your board>/<version>/platform.local.txt`. At minimum it should be

```
compiler.cpp.extra_flags=-frtti
```

If the above doesn't work, you can try the following:

```
compiler.c.extra_flags=-lstdc++
compiler.c.elf.extra_flags=-lstdc++
compiler.cpp.extra_flags=-std=gnu++11 -lstdc++ -frtti
compiler.S.extra_flags=-std=gnu++11 -lstdc++
compiler.ar.extra_flags=
compiler.libraries.ldflags=-std=gnu++11 -lstdc++
compiler.elf2bin.extra_flags=
compiler.elf2hex.extra_flags=
```

Documentation
=============

There is one simple example in the `examples` folder, you might need to modify it slightly to work with your board. For instance, `Serial` is not available on all boards directly, like many of the `nRF52` boards.

You should also read the [cereal documentation](https://uscilab.github.io/cereal/).
