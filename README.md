AudioFix
========

This is an experimental work-around for a possible cause of audio dropouts with
the 2018 MacBookPros under 10.13.6. Please be warned that this works by disabling
some forms of low level power management, and therefore the driver may impact
battery life.

To use the software you will need to compile either with a kernel signing certificate,
or disable signing checks via csrutil while booted to recovery mode.

A pre-built package is included, with a simple terminal based installation script. See
the readme for instructions.
