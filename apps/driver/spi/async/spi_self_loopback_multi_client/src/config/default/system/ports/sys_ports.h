/*******************************************************************************
  PORTS Service

  Company:
    Microchip Technology Inc.

  File Name:
    sys_ports.h

  Summary:
    PORTS Service Header File

  Description:
    This library provides an interface to control and interact with PORTS
    System Service.

*******************************************************************************/

/*******************************************************************************
* Copyright (C) 2018 Microchip Technology Inc. and its subsidiaries.
*
* Subject to your compliance with these terms, you may use Microchip software
* and any derivatives exclusively with Microchip products. It is your
* responsibility to comply with third party license terms applicable to your
* use of third party software (including open source software) that may
* accompany Microchip software.
*
* THIS SOFTWARE IS SUPPLIED BY MICROCHIP "AS IS". NO WARRANTIES, WHETHER
* EXPRESS, IMPLIED OR STATUTORY, APPLY TO THIS SOFTWARE, INCLUDING ANY IMPLIED
* WARRANTIES OF NON-INFRINGEMENT, MERCHANTABILITY, AND FITNESS FOR A
* PARTICULAR PURPOSE.
*
* IN NO EVENT WILL MICROCHIP BE LIABLE FOR ANY INDIRECT, SPECIAL, PUNITIVE,
* INCIDENTAL OR CONSEQUENTIAL LOSS, DAMAGE, COST OR EXPENSE OF ANY KIND
* WHATSOEVER RELATED TO THE SOFTWARE, HOWEVER CAUSED, EVEN IF MICROCHIP HAS
* BEEN ADVISED OF THE POSSIBILITY OR THE DAMAGES ARE FORESEEABLE. TO THE
* FULLEST EXTENT ALLOWED BY LAW, MICROCHIP'S TOTAL LIABILITY ON ALL CLAIMS IN
* ANY WAY RELATED TO THIS SOFTWARE WILL NOT EXCEED THE AMOUNT OF FEES, IF ANY,
* THAT YOU HAVE PAID DIRECTLY TO MICROCHIP FOR THIS SOFTWARE.
*******************************************************************************/

#ifndef SYS_PORTS_H
#define SYS_PORTS_H

#include "device.h"
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>


// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    extern "C" {

#endif
// DOM-IGNORE-END



// *****************************************************************************
// *****************************************************************************
// Section: Data types and constants
// *****************************************************************************
// *****************************************************************************


// *****************************************************************************
/* Sys Port

  Summary:
    Identifies the available Port Channels.

  Description:
    This enumeration identifies the available Port Channels.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all ports are available on all devices.  Refer to the specific
    device data sheet to determine which ports are supported.
*/


typedef enum
{
    SYS_PORT_A = 0,
    SYS_PORT_B = 1,
    SYS_PORT_C = 2,
    SYS_PORT_D = 3,
    SYS_PORT_E = 4,

} SYS_PORT;


// *****************************************************************************
/* Sys Port Pins

  Summary:
    Identifies the available port pins.

  Description:
    This enumeration identifies the available port pins.

  Remarks:
    The caller should not rely on the specific numbers assigned to any of
    these values as they may change from one processor to the next.

    Not all pins are available on all devices.  Refer to the specific
    device data sheet to determine which pins are supported.
*/

typedef enum
{

    SYS_PORT_PIN_RA0 = 0,
    SYS_PORT_PIN_RA1 = 1,
    SYS_PORT_PIN_RA2 = 2,
    SYS_PORT_PIN_RA3 = 3,
    SYS_PORT_PIN_RA4 = 4,
    SYS_PORT_PIN_RA5 = 5,
    SYS_PORT_PIN_RA6 = 6,
    SYS_PORT_PIN_RA7 = 7,
    SYS_PORT_PIN_RA8 = 8,
    SYS_PORT_PIN_RA9 = 9,
    SYS_PORT_PIN_RA10 = 10,
    SYS_PORT_PIN_RA11 = 11,
    SYS_PORT_PIN_RA12 = 12,
    SYS_PORT_PIN_RA13 = 13,
    SYS_PORT_PIN_RA14 = 14,
    SYS_PORT_PIN_RA15 = 15,
    SYS_PORT_PIN_RB0 = 16,
    SYS_PORT_PIN_RB1 = 17,
    SYS_PORT_PIN_RB2 = 18,
    SYS_PORT_PIN_RB3 = 19,
    SYS_PORT_PIN_RB4 = 20,
    SYS_PORT_PIN_RB5 = 21,
    SYS_PORT_PIN_RB6 = 22,
    SYS_PORT_PIN_RB7 = 23,
    SYS_PORT_PIN_RB8 = 24,
    SYS_PORT_PIN_RB9 = 25,
    SYS_PORT_PIN_RB10 = 26,
    SYS_PORT_PIN_RB11 = 27,
    SYS_PORT_PIN_RB12 = 28,
    SYS_PORT_PIN_RB13 = 29,
    SYS_PORT_PIN_RB14 = 30,
    SYS_PORT_PIN_RB15 = 31,
    SYS_PORT_PIN_RC0 = 32,
    SYS_PORT_PIN_RC1 = 33,
    SYS_PORT_PIN_RC7 = 39,
    SYS_PORT_PIN_RC8 = 40,
    SYS_PORT_PIN_RC9 = 41,
    SYS_PORT_PIN_RC10 = 42,
    SYS_PORT_PIN_RC11 = 43,
    SYS_PORT_PIN_RD0 = 48,
    SYS_PORT_PIN_RD1 = 49,
    SYS_PORT_PIN_RD2 = 50,
    SYS_PORT_PIN_RD3 = 51,
    SYS_PORT_PIN_RD4 = 52,
    SYS_PORT_PIN_RD5 = 53,
    SYS_PORT_PIN_RD6 = 54,
    SYS_PORT_PIN_RD7 = 55,
    SYS_PORT_PIN_RE0 = 64,
    SYS_PORT_PIN_RE1 = 65,
    SYS_PORT_PIN_RE2 = 66,
    SYS_PORT_PIN_RE3 = 67,
    SYS_PORT_PIN_RE4 = 68,
    SYS_PORT_PIN_RE5 = 69,
    SYS_PORT_PIN_RE6 = 70,

    /* This element should not be used in any of the PORTS APIs.
       It will be used by other modules or application to denote that none of the PORT Pin is used */
    SYS_PORT_PIN_NONE = -1
} SYS_PORT_PIN;



// *****************************************************************************
// *****************************************************************************
// Section: SYS PORT Functions which operates on one pin at a time
// *****************************************************************************
// *****************************************************************************

// *****************************************************************************
/* Function:
    void SYS_PORT_PinWrite(SYS_PORT_PIN pin, bool value)

  Summary:
    Writes to the selected pin.

  Description:
    This function writes/drives the "value" on the selected I/O line/pin.

  Precondition:
    Port Initialization must have been done using appropriate Initialize API call.

  Parameters:
    pin       - One of the IO pins from the enum SYS_PORT_PIN
    value     - value to be written on the selected pin:
                true  = set pin to high (1).
                false = clear pin to low (0).

  Returns:
    None.

  Example:
    <code>
    SYS_PORT_PinWrite(SYS_PORT_PIN_PB3, true);
    </code>

  Remarks:
    None.
*/
static inline void SYS_PORT_PinWrite(SYS_PORT_PIN pin, bool value);

// *****************************************************************************
/* Function:
    bool SYS_PORT_PinRead(SYS_PORT_PIN pin)

  Summary:
    Read the selected pin value.

  Description:
    This function reads the selected pin value.
    it reads the value regardless of pin configuration, whether uniquely as an
    input, or driven by the PIO Controller, or driven by peripheral.

  Precondition:
    Reading the I/O line levels requires the clock of the PIO Controller to be
    enabled, otherwise this API reads the levels present on the I/O line at the
    time the clock was disabled.

  Parameters:
    pin - One of the IO pins from the enum SYS_PORT_PIN

  Returns:
    Returns the read value of the selected I/O pin.

  Example:
    <code>

    bool value;
    value = SYS_PORT_PinRead(SYS_PORT_PIN_PB3);

    </code>

  Remarks:
       To read the latched value on this pin, SYS_PORT_PinLatchRead API should be used.
*/
static inline bool SYS_PORT_PinRead(SYS_PORT_PIN pin);

// *****************************************************************************
/* Function:
    bool SYS_PORT_PinLatchRead ( SYS_PORT_PIN pin )

  Summary:
    Read the value driven on the selected pin.

  Description:
    This function reads the data driven on the selected I/O line/pin.
    Whatever data is written/driven on I/O line by using any of the PORTS
    APIs, will be read by this API.

  Precondition:
    None.

  Parameters:
    pin - One of the IO pins from the enum SYS_PORT_PIN

  Returns:
    Returns the value driven on the selected I/O pin.

  Example:
    <code>

    bool value;
    value = SYS_PORT_PinLatchRead(SYS_PORT_PIN_PB3);

    </code>

  Remarks:
    To read actual pin value, SYS_PORT_PinRead API should be used.
*/
static inline bool SYS_PORT_PinLatchRead(SYS_PORT_PIN pin);

// *****************************************************************************
/* Function:
    void SYS_PORT_PinToggle(SYS_PORT_PIN pin)

  Summary:
    Toggles the selected pin.

  Description:
    This function toggles/inverts the value on the selected I/O line/pin.

  Precondition:
    Port Initialization must have been done using appropriate Initialize API call.

  Parameters:
    pin - One of the IO pins from the enum SYS_PORT_PIN

  Returns:
    None.

  Example:
    <code>

    SYS_PORT_PinToggle(SYS_PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void SYS_PORT_PinToggle(SYS_PORT_PIN pin);

// *****************************************************************************
/* Function:
    void SYS_PORT_PinSet(SYS_PORT_PIN pin)

  Summary:
    Sets the selected pin.

  Description:
    This function drives '1' on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin - One of the IO pins from the enum SYS_PORT_PIN

  Returns:
    None.

  Example:
    <code>

    SYS_PORT_PinSet(SYS_PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void SYS_PORT_PinSet(SYS_PORT_PIN pin);

// *****************************************************************************
/* Function:
    void SYS_PORT_PinClear(SYS_PORT_PIN pin)

  Summary:
    Clears the selected pin.

  Description:
    This function drives '0' on the selected I/O line/pin.

  Precondition:
    None.

  Parameters:
    pin - One of the IO pins from the enum SYS_PORT_PIN

  Returns:
    None.

  Example:
    <code>

    SYS_PORT_PinClear(SYS_PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void SYS_PORT_PinClear(SYS_PORT_PIN pin);

// *****************************************************************************
/* Function:
    void SYS_PORT_PinInputEnable(SYS_PORT_PIN pin)

  Summary:
    Enables selected IO pin as input.

  Description:
    This function enables selected IO pin as input.

  Precondition:
    None.

  Parameters:
    pin - One of the IO pins from the enum SYS_PORT_PIN

  Returns:
    None.

  Example:
    <code>

    SYS_PORT_PinInputEnable(SYS_PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void SYS_PORT_PinInputEnable(SYS_PORT_PIN pin);

// *****************************************************************************
/* Function:
    void SYS_PORT_PinOutputEnable(SYS_PORT_PIN pin)

  Summary:
    Enables selected IO pin as output.

  Description:
    This function enables selected IO pin as output.

  Precondition:
    None.

  Parameters:
    pin - One of the IO pins from the enum SYS_PORT_PIN

  Returns:
    None.

  Example:
    <code>

    SYS_PORT_PinOutputEnable(SYS_PORT_PIN_PB3);

    </code>

  Remarks:
    None.
*/
static inline void SYS_PORT_PinOutputEnable(SYS_PORT_PIN pin);


#include "sys_ports_mapping.h"

// DOM-IGNORE-BEGIN
#ifdef __cplusplus  // Provide C++ Compatibility

    }

#endif
// DOM-IGNORE-END
#endif // SYS_PORTS_H
