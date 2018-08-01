/** @file
 *  @brief      ts_audiofix.cc
 *  @copyright  Copyright (c) 2017 tSoniq. All rights reserved.
 */

#include "libkern/version.h"
#include "ts_audiofix.h"



#define super IOService
OSDefineMetaClassAndStructors(com_tsoniq_driver_TSAudioFixDriver, IOService);



#define kDarwinVersionHighSierra    (17)                                        //!< The OS version code for Sierra (10.13).



/** Probe request.
 *
 *  @param  provider    The service provider for this driver.
 *  @param  score       Returns the updated probe score.
 *  @return             The driver to use with this device.
 */
IOService* com_tsoniq_driver_TSAudioFixDriver::probe(IOService* provider, SInt32* score)
{
    // Refuse to load if this is not high sierra.
    if (version_major != kDarwinVersionHighSierra)
    {
        IOLog("This driver is not supported under OS %u.%u\n", (unsigned)version_major, (unsigned)version_minor);
        return NULL;
    }
    
    super::probe(provider, score);
    if (score) *score = 100000;
    return this;
}


/** Start the driver.
 *
 *  @param  provider    The provider service.
 *  @return             Logical true for success, false if we are unable to start.
 */
bool com_tsoniq_driver_TSAudioFixDriver::start(IOService* provider)
{
    IOLog("Disablimg IO power management\n");
    provider->requireMaxBusStall(5000);
    provider->requireMaxInterruptDelay(10000);
    return super::start(provider);
}


/** Stop the driver.
 *
 *  @param  provider    The provider service.
 */
void com_tsoniq_driver_TSAudioFixDriver::stop(IOService* provider)
{
    IOLog("Re-enabling IO power management\n");
    provider->requireMaxBusStall(0);
    provider->requireMaxInterruptDelay(0);
    return super::stop(provider);
}

