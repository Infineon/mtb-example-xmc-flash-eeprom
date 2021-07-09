/******************************************************************************
* File Name:   main.c
*
* Description: This is the source code for the XMC MCU: Empty Application
*              Template for ModusToolbox.
*
* Related Document: See README.md
*
******************************************************************************
*
* Copyright (c) 2015-2021, Infineon Technologies AG
* All rights reserved.                        
*                                             
* Boost Software License - Version 1.0 - August 17th, 2003
* 
* Permission is hereby granted, free of charge, to any person or organization
* obtaining a copy of the software and accompanying documentation covered by
* this license (the "Software") to use, reproduce, display, distribute,
* execute, and transmit the Software, and to prepare derivative works of the
* Software, and to permit third-parties to whom the Software is furnished to
* do so, all subject to the following:
* 
* The copyright notices in the Software and this entire statement, including
* the above license grant, this restriction and the following disclaimer,
* must be included in all copies of the Software, in whole or in part, and
* all derivative works of the Software, unless such copies or derivative
* works are solely in the form of machine-executable object code generated by
* a source language processor.
* 
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
* SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
* FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
* ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
* DEALINGS IN THE SOFTWARE.
*                                                                              
*****************************************************************************/
#include "cybsp.h"
#include "cy_utils.h"
#include "print_functions.h"

#ifdef TARGET_KIT_XMC14_BOOT_001
#include "xmc1_e_eeprom_example.h"
#endif
#ifdef TARGET_KIT_XMC47_RELAX_V1
#include "xmc4_e_eeprom_example.h"
#endif

/*******************************************************************************
* Defines
*******************************************************************************/
#define PROJECT_HEADER_COMMON_LINE  "\r\n**************************************************\r\n"
#define PROJECT_HEADER_NAME         "           FLASH EEPROM EXAMPLE APPLICATION"

/*******************************************************************************
* Function Name: retarget_io_init
********************************************************************************
* Summary:
* Initialize printf retarget
*
* Parameters:
*  void
*
* Return:
*  void
*
*******************************************************************************/
int main(void)
{
    cy_rslt_t result;

    /* Initialize the device and board peripherals */
    result = cybsp_init();
    if (result != CY_RSLT_SUCCESS)
    {
        CY_ASSERT(0);
    }

    /* Print project name */
    print_buffer_text((uint8_t *)PROJECT_HEADER_COMMON_LINE, sizeof(PROJECT_HEADER_COMMON_LINE));
    print_buffer_text((uint8_t *)PROJECT_HEADER_NAME, sizeof(PROJECT_HEADER_NAME));
    print_buffer_text((uint8_t *)PROJECT_HEADER_COMMON_LINE, sizeof(PROJECT_HEADER_COMMON_LINE));

    E_EEPROM_example();
    for (;;)
    {
    }
}

/* [] END OF FILE */
