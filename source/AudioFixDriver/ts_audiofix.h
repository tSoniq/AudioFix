/** @file
 *  @brief      ts_audiofix.h
 *  @copyright  Copyright (c) 2018 tSoniq. All rights reserved.
 */

#pragma once

#include <IOKit/IOLib.h>
#include <IOKit/IOService.h>


/** Class controlling a single USB device.
 */
class com_tsoniq_driver_TSAudioFixDriver : public IOService
{
private:
    
    OSDeclareDefaultStructors(com_tsoniq_driver_TSAudioFixDriver);
    
public:
    
    // IOService methods.
    virtual IOService* probe(IOService* provider, SInt32* score) override;
    virtual bool start(IOService* provider) override;
    virtual void stop(IOService* provider) override;
    
private:
    
    com_tsoniq_driver_TSAudioFixDriver(const com_tsoniq_driver_TSAudioFixDriver&);              // Prevent copy constructor
    com_tsoniq_driver_TSAudioFixDriver& operator=(const com_tsoniq_driver_TSAudioFixDriver&);   // Prevent assignment
};

