#!/bin/sh
#
# Trivial script to manage driver loading, installation and removal.
#

COMMAND=$1
KEXT_NAME="TSAudioFixDriver.kext"
KEXT_PATH="./${KEXT_NAME}"
KEXT_BUNDLE=com.tsoniq.driver.TSAudioFixDriver


if [ ! -d "${KEXT_PATH}" ] ; then
echo "Unable to find the driver ${KEXT_PATH}"
exit -1
fi


if [ "${COMMAND}" = "try" ] ; then
    sudo kextunload -q -b ${KEXT_BUNDLE}
    sudo kextload "${KEXT_PATH}"
elif [ "${COMMAND}" = "install" ] ; then
    sudo kextunload -q -b ${KEXT_BUNDLE}
    sudo cp -R "${KEXT_PATH}" "/Library/Extensions/"
    sudo kextload -b ${KEXT_BUNDLE}
elif [ "${COMMAND}" = "remove" ] ; then
    sudo kextunload -q -b ${KEXT_BUNDLE}
    if [ -d "/Library/Extensions/${KEXT_NAME}/Contents/MacOS/TSAudioFixDriver" ] ; then
        sudo rm -r "/Library/Extensions/${KEXT_NAME}"
    fi
else
    echo "Usage:"
    echo "  $0 try       --    load the driver temporarily. Reboot or use 'remove' to disable."
    echo "  $0 install   --    install the driver. Use 'remove' to uninstall."
    echo "  $0 remove    --    stop the driver and remove any installed instance."
fi

exit 0
