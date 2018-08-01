AudioFix
========

This is work-around for some causes of audio dropouts with the 2018 MacBookPros under 10.13.6.

The software consists of a trivial kernel driver that reduces IO subsystem power management.
This may improve audio quality by reducing drop-outs, but be aware that it will also increase
idle power consumption, reducing the battery life while installed or running.

Because this is a temporary patch, the driver will do nothinhg unless run under macOS
High Sierra - on the assumption that Mojave will fix the audio problems in the audio
drivers themselves.





**** IMPORTANT ****

On the first time that the driver is used you will need to approve the loading of the
driver in system preferences. To do this run the script with either "try" or "install",
then open System Preferences > Security & Privacy > General. In the tab if you see a
message that system software from Mark Moore was blocked, you will need to follow the
instructions to allow the driver to be loaded.



Usage
-----

To use, open a terminal and change to the directory with this readme. eg:

    cd /Volumes/AudioFix

The use the audiofix.sh script to try or install the driver. The script has three options:

    ./audiofix try

        This will perform a one-off load of the driver. The driver will remain active
        until either "./audiofix remove" is run or the computer is restarted.

    ./audiofix install

        This will install the driver so that it is loaded automatically on boot.

    ./audiofix remove

        Uninstall and/or unload the driver.

Please note that you will need to enter an administrator password to run the commands.
