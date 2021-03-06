/** ###################################################################
**     THIS COMPONENT MODULE IS GENERATED BY THE TOOL and modified by RG.
**     Filename    : TPM1_TP1.c
**     Project     : ProcessorExpert
**     Processor   : MKL25Z128VLK4
**     Component   : TPM_Handler
**     Version     : Component 01.000, Driver 01.00, CPU db: 3.00.000
**     Compiler    : GNU C Compiler
**     Date/Time   : 2013-03-19, 16:32, # CodeGen: 40
**     Edited:     : 2013-03-20, 13:20, # Reiner Geiger
**     Abstract    :
**          This file implements the TPM (TPM1) module initialization
**          according to the Peripheral Initialization settings, and
**          defines interrupt service routines prototypes.
**          
**          This file is necessary because the original TU1_setPeriodTick()
**          function contains errors; It is possible to generate 24 MHz
**          Clocks, but the old function prohibits this;
**          
**     Settings    :
**          Component name                                 : TU1
**          Device                                         : TP1
**          Settings                                       : 
**            Clock gate                                   : Enabled
**            Clock settings                               : 
**              Clock source                               : Counter clock
**              Prescaler                                  : divide by 1
**              Modulo counter                             : 0
**              Period                                     : (1 * 65536) / External Clock Source
**            BDM mode                                     : TPM counter running; output pins operational
**            Global time base                             : Enabled
**            Counter reload on trigger                    : Enabled
**            Counter start on trigger                     : Disabled
**            Counter stop on overflow                     : Disabled
**          Channels                                       : 
**            Channel 0                                    : Enabled
**              Channel mode                               : Output compare
**                Output action                            : Toggle output
**                Channel value register                   : 0
**              Pin                                        : Enabled
**                Pin                                      : PTA12/TPM1_CH0
**                Pin signal                               : 
**              Interrupt/DMA                              : 
**                Interrupt                                : INT_TPM1
**                Channel interrupt                        : Disabled
**                DMA request                              : Enabled
**            Channel 1                                    : Disabled
**          Pins                                           : 
**            External clock pin                           : Disabled
**            HW Synchronization trigger                   : Disabled
**          Interrupts                                     : 
**            Channels / Timer overflow / Fault            : 
**              Interrupt                                  : INT_TPM1
**              Interrupt request                          : Disabled
**              Interrupt priority                         : 0 (Highest)
**              ISR Name                                   : 
**              Channels interrupt/DMA                     : See the respective Channel settings
**              Timer overflow interrupt                   : Disabled
**          Initialization                                 : 
**            Call Init method                             : yes
**     Contents    :
**         Init - void TP1_Init(void);
**
**     Copyright : 1997 - 2012 Freescale, Inc. All Rights Reserved.
**     
**     http      : www.freescale.com
**     mail      : support@freescale.com
** ###################################################################*/

/* MODULE TP1. */

#include "TPM0_TP1.h"

  /* Including shared modules, which are used in the whole project */
#include "PE_Types.h"
#include "PE_Error.h"
#include "PE_Const.h"
#include "IO_Map.h"
#include "Cpu.h"
#include "TU1.h"
#include "TPM0_TP1.h"

LDD_TDeviceData* TP1_initTimer(void)
{
	return TU1_Init(NULL);
}

void TP1_disableTimer(LDD_TDeviceData *TU1Handl)
{
	TU1_Disable(TU1Handl);
	//TPM1_SC &= ~TPM_SC_DMA_MASK;
}

void TP1_enableTimer(LDD_TDeviceData *TU1Handl)
{
	TU1_Enable(TU1Handl);
	//TPM1_SC |= TPM_SC_DMA_MASK;
}

LDD_TError TP1_setTimerValue(LDD_TDeviceData *TU1Handl, uint32_t Ticks)
{
	  (void)TU1Handl;                 /* Parameter is not used, suppress unused argument warning */
	  /* Parameter test - this test can be disabled by setting the "Ignore range checking"
	     property to the "yes" value in the "Configuration inspector" */
	  if ((Ticks > 65535U) || (Ticks == 0U)) { /* Is the given value out of range? */
	    return ERR_PARAM_TICKS;            /* If yes then error */
	  }
	  TPM_PDD_WriteModuloReg(TPM0_BASE_PTR, (uint16_t)(--Ticks));
	  return ERR_OK;                       /* OK */
	//TPM1_MOD = (uint32_t)(TPM_MOD_MOD(brg&0xFFFF));
}


/* END TP1. */
/*
** ###################################################################
**
**     This file was created by Processor Expert 10.0 [05.03]
**     for the Freescale Kinetis series of microcontrollers.
**
** ###################################################################
*/
