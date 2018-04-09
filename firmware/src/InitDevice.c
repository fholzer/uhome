//=========================================================
// src/InitDevice.c: generated by Hardware Configurator
//
// This file will be regenerated when saving a document.
// leave the sections inside the "$[...]" comment tags alone
// or they will be overwritten!
//=========================================================

// USER INCLUDES
#include <SI_EFM8SB1_Register_Enums.h>
#include "InitDevice.h"

// USER PROTOTYPES
// USER FUNCTIONS

// $[Library Includes]
// [Library Includes]$

//==============================================================================
// enter_DefaultMode_from_RESET
//==============================================================================
extern void enter_DefaultMode_from_RESET(void) {
	// $[Config Calls]
	// Save the SFRPAGE
	uint8_t SFRPAGE_save = SFRPAGE;
	PCA_0_enter_DefaultMode_from_RESET();
	PORTS_0_enter_DefaultMode_from_RESET();
	PORTS_1_enter_DefaultMode_from_RESET();
	PBCFG_0_enter_DefaultMode_from_RESET();
	VDDMON_0_enter_DefaultMode_from_RESET();
	RTC_0_enter_DefaultMode_from_RESET();
	CLOCK_0_enter_DefaultMode_from_RESET();
	TIMER01_0_enter_DefaultMode_from_RESET();
	TIMER_SETUP_0_enter_DefaultMode_from_RESET();
	SMBUS_0_enter_DefaultMode_from_RESET();
	INTERRUPT_0_enter_DefaultMode_from_RESET();
	PMU_0_enter_DefaultMode_from_RESET();
	// Restore the SFRPAGE
	SFRPAGE = SFRPAGE_save;
	// [Config Calls]$

}

//================================================================================
// PORTS_1_enter_DefaultMode_from_RESET
//================================================================================
extern void PORTS_1_enter_DefaultMode_from_RESET(void) {
	// $[P1 - Port 1 Pin Latch]
	// [P1 - Port 1 Pin Latch]$

	// $[P1MDOUT - Port 1 Output Mode]
	// [P1MDOUT - Port 1 Output Mode]$

	// $[P1MDIN - Port 1 Input Mode]
	/***********************************************************************
	 - P1.0 pin is configured for digital mode
	 - P1.1 pin is configured for analog mode
	 - P1.2 pin is configured for analog mode
	 - P1.3 pin is configured for analog mode
	 - P1.5 pin is configured for analog mode
	 - P1.6 pin is configured for analog mode
	 - P1.7 pin is configured for analog mode
	 ***********************************************************************/
	P1MDIN = P1MDIN_B0__DIGITAL | P1MDIN_B1__ANALOG | P1MDIN_B2__ANALOG
			| P1MDIN_B3__ANALOG | P1MDIN_B5__ANALOG | P1MDIN_B6__ANALOG
			| P1MDIN_B7__ANALOG;
	// [P1MDIN - Port 1 Input Mode]$

	// $[P1SKIP - Port 1 Skip]
	/***********************************************************************
	 - P1.0 pin is not skipped by the crossbar
	 - P1.1 pin is skipped by the crossbar
	 - P1.2 pin is skipped by the crossbar
	 - P1.3 pin is skipped by the crossbar
	 - P1.5 pin is skipped by the crossbar
	 - P1.6 pin is skipped by the crossbar
	 - P1.7 pin is skipped by the crossbar
	 ***********************************************************************/
	P1SKIP = P1SKIP_B0__NOT_SKIPPED | P1SKIP_B1__SKIPPED | P1SKIP_B2__SKIPPED
			| P1SKIP_B3__SKIPPED | P1SKIP_B5__SKIPPED | P1SKIP_B6__SKIPPED
			| P1SKIP_B7__SKIPPED;
	// [P1SKIP - Port 1 Skip]$

	// $[Missing Pin Skip]
	// Skip any pins that are not available on this package
	P1SKIP |= P1SKIP_B4__SKIPPED;
	// [Missing Pin Skip]$

	// $[P1MASK - Port 1 Mask]
	// [P1MASK - Port 1 Mask]$

	// $[P1MAT - Port 1 Match]
	// [P1MAT - Port 1 Match]$

	// $[P1DRV - Port 1 Drive Strength]
	// [P1DRV - Port 1 Drive Strength]$

}

extern void PBCFG_0_enter_DefaultMode_from_RESET(void) {
	// $[XBR2 - Port I/O Crossbar 2]
	/***********************************************************************
	 - Weak Pullups enabled 
	 - Crossbar enabled
	 ***********************************************************************/
	XBR2 = XBR2_WEAKPUD__PULL_UPS_ENABLED | XBR2_XBARE__ENABLED;
	// [XBR2 - Port I/O Crossbar 2]$

	// $[XBR0 - Port I/O Crossbar 0]
	/***********************************************************************
	 - UART I/O unavailable at Port pin
	 - SPI I/O unavailable at Port pins
	 - SMBus 0 I/O routed to Port pins
	 - CP0 unavailable at Port pin
	 - Asynchronous CP0 unavailable at Port pin
	 - SYSCLK unavailable at Port pin
	 ***********************************************************************/
	XBR0 = XBR0_URT0E__DISABLED | XBR0_SPI0E__DISABLED | XBR0_SMB0E__ENABLED
			| XBR0_CP0E__DISABLED | XBR0_CP0AE__DISABLED
			| XBR0_SYSCKE__DISABLED;
	// [XBR0 - Port I/O Crossbar 0]$

	// $[XBR1 - Port I/O Crossbar 1]
	// [XBR1 - Port I/O Crossbar 1]$

}

extern void PORTS_0_enter_DefaultMode_from_RESET(void) {
	// $[P0 - Port 0 Pin Latch]
	// [P0 - Port 0 Pin Latch]$

	// $[P0MDOUT - Port 0 Output Mode]
	// [P0MDOUT - Port 0 Output Mode]$

	// $[P0MDIN - Port 0 Input Mode]
	/***********************************************************************
	 - P0.0 pin is configured for digital mode
	 - P0.1 pin is configured for digital mode
	 - P0.2 pin is configured for analog mode
	 - P0.3 pin is configured for analog mode
	 - P0.4 pin is configured for analog mode
	 - P0.5 pin is configured for analog mode
	 - P0.6 pin is configured for analog mode
	 - P0.7 pin is configured for analog mode
	 ***********************************************************************/
	P0MDIN = P0MDIN_B0__DIGITAL | P0MDIN_B1__DIGITAL | P0MDIN_B2__ANALOG
			| P0MDIN_B3__ANALOG | P0MDIN_B4__ANALOG | P0MDIN_B5__ANALOG
			| P0MDIN_B6__ANALOG | P0MDIN_B7__ANALOG;
	// [P0MDIN - Port 0 Input Mode]$

	// $[P0SKIP - Port 0 Skip]
	/***********************************************************************
	 - P0.0 pin is not skipped by the crossbar
	 - P0.1 pin is not skipped by the crossbar
	 - P0.2 pin is skipped by the crossbar
	 - P0.3 pin is skipped by the crossbar
	 - P0.4 pin is skipped by the crossbar
	 - P0.5 pin is skipped by the crossbar
	 - P0.6 pin is skipped by the crossbar
	 - P0.7 pin is skipped by the crossbar
	 ***********************************************************************/
	P0SKIP = P0SKIP_B0__NOT_SKIPPED | P0SKIP_B1__NOT_SKIPPED
			| P0SKIP_B2__SKIPPED | P0SKIP_B3__SKIPPED | P0SKIP_B4__SKIPPED
			| P0SKIP_B5__SKIPPED | P0SKIP_B6__SKIPPED | P0SKIP_B7__SKIPPED;
	// [P0SKIP - Port 0 Skip]$

	// $[P0MASK - Port 0 Mask]
	// [P0MASK - Port 0 Mask]$

	// $[P0MAT - Port 0 Match]
	// [P0MAT - Port 0 Match]$

	// $[P0DRV - Port 0 Drive Strength]
	// [P0DRV - Port 0 Drive Strength]$

}

extern void HFOSC_0_enter_DefaultMode_from_RESET(void) {
	// $[HFO#CAL - High Frequency Oscillator Calibration]
	// [HFO#CAL - High Frequency Oscillator Calibration]$

	// $[HFO#CN - High Frequency Oscillator Control]
	/***********************************************************************
	 - High Frequency Oscillator enabled
	 ***********************************************************************/
	HFO0CN |= HFO0CN_IOSCEN__ENABLED;
	// [HFO#CN - High Frequency Oscillator Control]$

	// $[Oscillator Ready]
	while ((HFO0CN & HFO0CN_IFRDY__BMASK) == HFO0CN_IFRDY__NOT_SET)
		;
	// [Oscillator Ready]$

}

extern void CLOCK_0_enter_DefaultMode_from_RESET(void) {
	// $[CLKSEL - Clock Select]
	/***********************************************************************
	 - SYSCLK is equal to selected clock source divided by 1
	 - Clock derived from the Internal Low Power Oscillator
	 ***********************************************************************/
	CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__LPOSC;
	// Wait for the clock to be ready
	while ((CLKSEL & CLKSEL_CLKRDY__BMASK) != CLKSEL_CLKRDY__SET)
		;
	// [CLKSEL - Clock Select]$

}

extern void VREG_0_enter_DefaultMode_from_RESET(void) {
	// $[REG0CN - Voltage Regulator Control]
	/***********************************************************************
	 - Enable the precision High Frequency Oscillator bias
	 ***********************************************************************/
	REG0CN = REG0CN_OSCBIAS__DISABLED;
	// [REG0CN - Voltage Regulator Control]$

}

extern void PCA_0_enter_DefaultMode_from_RESET(void) {
	// $[PCA0MD - PCA Mode]
	/***********************************************************************
	 - Disable Watchdog Timer
	 - System clock divided by 12
	 - PCA continues to function normally while the system controller is in
	 Idle Mode
	 - Disable the CF interrupt
	 - Disable Watchdog Timer
	 - Watchdog Timer Enable unlocked
	 ***********************************************************************/
	SFRPAGE = 0x00;
	PCA0MD &= ~PCA0MD_WDTE__BMASK;
	PCA0MD = PCA0MD_CPS__SYSCLK_DIV_12 | PCA0MD_CIDL__NORMAL
			| PCA0MD_ECF__OVF_INT_DISABLED | PCA0MD_WDTE__DISABLED
			| PCA0MD_WDLCK__UNLOCKED;
	// [PCA0MD - PCA Mode]$

	// $[PCA0H - PCA Counter/Timer High Byte]
	// [PCA0H - PCA Counter/Timer High Byte]$

	// $[PCA0L - PCA Counter/Timer Low Byte]
	// [PCA0L - PCA Counter/Timer Low Byte]$

	// $[PCA0PWM - PCA PWM Configuration]
	// [PCA0PWM - PCA PWM Configuration]$

	// $[PCA0CN0 - PCA Control 0]
	// [PCA0CN0 - PCA Control 0]$

}

extern void TIMER_SETUP_0_enter_DefaultMode_from_RESET(void) {

	// $[CKCON0 - Clock Control 0]
	/***********************************************************************
	 - System clock divided by 4
	 - Counter/Timer 0 uses the clock defined by the prescale field, SCA
	 - Timer 2 high byte uses the clock defined by T2XCLK in TMR2CN0
	 - Timer 2 low byte uses the clock defined by T2XCLK in TMR2CN0
	 - Timer 3 high byte uses the clock defined by T3XCLK in TMR3CN0
	 - Timer 3 low byte uses the clock defined by T3XCLK in TMR3CN0
	 - Timer 1 uses the system clock
	 ***********************************************************************/
	CKCON0 = CKCON0_SCA__SYSCLK_DIV_4 | CKCON0_T0M__PRESCALE
			| CKCON0_T2MH__EXTERNAL_CLOCK | CKCON0_T2ML__EXTERNAL_CLOCK
			| CKCON0_T3MH__EXTERNAL_CLOCK | CKCON0_T3ML__EXTERNAL_CLOCK
			| CKCON0_T1M__SYSCLK;
	// [CKCON0 - Clock Control 0]$

	// $[TMOD - Timer 0/1 Mode]
	/***********************************************************************
	 - Mode 0, 13-bit Counter/Timer
	 - Mode 2, 8-bit Counter/Timer with Auto-Reload
	 - Timer Mode
	 - Timer 0 enabled when TR0 = 1 irrespective of INT0 logic level
	 - Timer Mode
	 - Timer 1 enabled when TR1 = 1 irrespective of INT1 logic level
	 ***********************************************************************/
	TMOD = TMOD_T0M__MODE0 | TMOD_T1M__MODE2 | TMOD_CT0__TIMER
			| TMOD_GATE0__DISABLED | TMOD_CT1__TIMER | TMOD_GATE1__DISABLED;
	// [TMOD - Timer 0/1 Mode]$

	// $[TCON - Timer 0/1 Control]
	/***********************************************************************
	 - Start Timer 1 running
	 ***********************************************************************/
	TCON |= TCON_TR1__RUN;
	// [TCON - Timer 0/1 Control]$

}

extern void SMBUS_0_enter_DefaultMode_from_RESET(void) {

	// $[SMB0ADR - SMBus 0 Slave Address]
	// [SMB0ADR - SMBus 0 Slave Address]$

	// $[SMB0ADM - SMBus 0 Slave Address Mask]
	// [SMB0ADM - SMBus 0 Slave Address Mask]$

	// $[SMB0CF - SMBus 0 Configuration]
	/***********************************************************************
	 - Timer 1 Overflow
	 - Slave states are inhibited
	 - Enable the SMBus module
	 ***********************************************************************/
	SMB0CF &= ~SMB0CF_SMBCS__FMASK;
	SMB0CF |= SMB0CF_SMBCS__TIMER1 | SMB0CF_INH__SLAVE_DISABLED
			| SMB0CF_ENSMB__ENABLED;
	// [SMB0CF - SMBus 0 Configuration]$

}

extern void TIMER01_0_enter_DefaultMode_from_RESET(void) {
	// $[Timer Initialization]
	//Save Timer Configuration
	uint8_t TCON_save;
	TCON_save = TCON;
	//Stop Timers
	TCON &= ~TCON_TR0__BMASK & ~TCON_TR1__BMASK;

	// [Timer Initialization]$

	// $[TH0 - Timer 0 High Byte]
	// [TH0 - Timer 0 High Byte]$

	// $[TL0 - Timer 0 Low Byte]
	// [TL0 - Timer 0 Low Byte]$

	// $[TH1 - Timer 1 High Byte]
	// [TH1 - Timer 1 High Byte]$

	// $[TL1 - Timer 1 Low Byte]
	/***********************************************************************
	 - Timer 1 Low Byte = 0x34
	 ***********************************************************************/
	TL1 = (0x34 << TL1_TL1__SHIFT);
	// [TL1 - Timer 1 Low Byte]$

	// $[Timer Restoration]
	//Restore Timer Configuration
	TCON |= (TCON_save & TCON_TR0__BMASK) | (TCON_save & TCON_TR1__BMASK);

	// [Timer Restoration]$

}

extern void INTERRUPT_0_enter_DefaultMode_from_RESET(void) {
	// $[EIE1 - Extended Interrupt Enable 1]
	/***********************************************************************
	 - Disable ADC0 Conversion Complete interrupt
	 - Disable ADC0 Window Comparison interrupt
	 - Disable CP0 interrupts
	 - Disable all PCA0 interrupts
	 - Disable RTC Alarm interrupts
	 - Enable interrupt requests generated by SMB0
	 - Disable Timer 3 interrupts
	 ***********************************************************************/
	EIE1 = EIE1_EADC0__DISABLED | EIE1_EWADC0__DISABLED | EIE1_ECP0__DISABLED
			| EIE1_EPCA0__DISABLED | EIE1_ERTC0A__DISABLED | EIE1_ESMB0__ENABLED
			| EIE1_ET3__DISABLED;
	// [EIE1 - Extended Interrupt Enable 1]$

	// $[EIP1 - Extended Interrupt Priority 1]
	// [EIP1 - Extended Interrupt Priority 1]$

	// $[IE - Interrupt Enable]
	/***********************************************************************
	 - Enable each interrupt according to its individual mask setting
	 - Disable external interrupt 0
	 - Disable external interrupt 1
	 - Disable all SPI0 interrupts
	 - Disable all Timer 0 interrupt
	 - Disable all Timer 1 interrupt
	 - Disable Timer 2 interrupt
	 - Disable UART0 interrupt
	 ***********************************************************************/
	IE = IE_EA__ENABLED | IE_EX0__DISABLED | IE_EX1__DISABLED
			| IE_ESPI0__DISABLED | IE_ET0__DISABLED | IE_ET1__DISABLED
			| IE_ET2__DISABLED | IE_ES0__DISABLED;
	// [IE - Interrupt Enable]$

	// $[IP - Interrupt Priority]
	// [IP - Interrupt Priority]$

	// $[EIE2 - Extended Interrupt Enable 2]
	// [EIE2 - Extended Interrupt Enable 2]$

	// $[EIP2 - Extended Interrupt Priority 2]
	// [EIP2 - Extended Interrupt Priority 2]$

}

extern void RTC_0_enter_DefaultMode_from_RESET(void) {
	// $[RTC Initialization]
	// [RTC Initialization]$

	// $[RTC0XCN0 - RTC Oscillator Control: Initial start-up setting]
	// [RTC0XCN0 - RTC Oscillator Control: Initial start-up setting]$

	// $[RTC0XCN - RTC Oscillator Control]
	/***********************************************************************
	 - Self-Oscillate Mode selected
	 - Disable AGC
	 - Disable the Bias Double feature
	 - LFOSC0 enabled and selected as RTC oscillator source
	 ***********************************************************************/
	RTC0ADR = RTC0XCN0;
	RTC0DAT = RTC0XCN0_XMODE__SELF_OSCILLATE | RTC0XCN0_AGCEN__DISABLED
			| RTC0XCN0_BIASX2__DISABLED | RTC0XCN0_LFOEN__ENABLED;
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit
	// [RTC0XCN - RTC Oscillator Control]$

	// $[RTC0XCF - RTC Oscillator Configuration]
	// [RTC0XCF - RTC Oscillator Configuration]$

	// $[CAPTURE0 - RTC Timer Capture 0]
	// [CAPTURE0 - RTC Timer Capture 0]$

	// $[CAPTURE1 - RTC Timer Capture 1]
	// [CAPTURE1 - RTC Timer Capture 1]$

	// $[CAPTURE2 - RTC Timer Capture 2]
	// [CAPTURE2 - RTC Timer Capture 2]$

	// $[CAPTURE3 - RTC Timer Capture 3]
	// [CAPTURE3 - RTC Timer Capture 3]$

	// $[ALARM0 - RTC Alarm Programmed Value 0]
	// [ALARM0 - RTC Alarm Programmed Value 0]$

	// $[ALARM1 - RTC Alarm Programmed Value 1]
	// [ALARM1 - RTC Alarm Programmed Value 1]$

	// $[ALARM2 - RTC Alarm Programmed Value 2]
	/***********************************************************************
	 - RTC Alarm Programmed Value 2 = 0x05
	 ***********************************************************************/
	RTC0ADR = ALARM2;
	RTC0DAT = (0x05 << ALARM2_ALARM2__SHIFT);
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit
	// [ALARM2 - RTC Alarm Programmed Value 2]$

	// $[ALARM3 - RTC Alarm Programmed Value 3]
	// [ALARM3 - RTC Alarm Programmed Value 3]$

	// $[RTC0CN - RTC Control]
	/***********************************************************************
	 - Enable RTC oscillator
	 - RTC timer is running
	 - Enable missing RTC detector
	 - Enable RTC alarm
	 - Alarm event flag is set or enable the auto reset function
	 - Do not start a capture operation
	 - Do not start a set operation
	 ***********************************************************************/
	RTC0ADR = RTC0CN0;
	RTC0DAT = RTC0CN0_RTC0EN__ENABLED | RTC0CN0_RTC0TR__RUN
			| RTC0CN0_MCLKEN__ENABLED | RTC0CN0_RTC0AEN__ENABLED
			| RTC0CN0_ALRM__SET | RTC0CN0_RTC0CAP__NOT_SET
			| RTC0CN0_RTC0SET__NOT_SET;
	while ((RTC0ADR & RTC0ADR_BUSY__BMASK) == RTC0ADR_BUSY__SET)
		;    //Poll Busy Bit

	// [RTC0CN - RTC Control]$

	// $[External Oscillator Setup]
	// [External Oscillator Setup]$

}

extern void PMU_0_enter_DefaultMode_from_RESET(void) {
	// $[Clock Setup]

	// We must switch to the LPOSC before going into sleep mode
	// Save the clock settings
	uint8_t CLKSEL_save;
	uint8_t HFO0CN_save;
	CLKSEL_save = CLKSEL;
	HFO0CN_save = HFO0CN;

	// Switch to the LPOSC divided by 1
	CLKSEL = CLKSEL_CLKDIV__SYSCLK_DIV_1 | CLKSEL_CLKSL__LPOSC;
	while (!((CLKSEL & CLKSEL_CLKRDY__BMASK) == CLKSEL_CLKRDY__SET))
		;
	HFO0CN &= ~HFO0CN_IOSCEN__BMASK;

	// [Clock Setup]$

	// $[PMU0MD - Power Management Unit Mode]
	// [PMU0MD - Power Management Unit Mode]$

	// $[PMU0FL - Power Management Unit Flag]
	/***********************************************************************
	 - A Capacitive Sensing event did not cause the last wake-up
	 ***********************************************************************/
	PMU0FL = PMU0FL_CS0WK__NOT_SET;
	// [PMU0FL - Power Management Unit Flag]$

	// $[PCON0 - Power Control 0]
	// [PCON0 - Power Control 0]$

	// $[Clear PMU Wake-up flags]
	// [Clear PMU Wake-up flags]$

	// $[PMU0CF - Power Management Unit Configuration]
	/***********************************************************************
	 - Sleep mode not activated
	 - Suspend mode not activated
	 - Clear all wake-up flags
	 - Comparator 0 rising edge did not cause the last wake-up
	 - A Port Match event did not cause the last wake-up
	 - A RTC Alarm caused the last wake-up
	 - An RTC oscillator fail event caused the last wake-up
	 ***********************************************************************/
	PMU0CF = PMU0CF_SLEEP__NORMAL | PMU0CF_SUSPEND__NORMAL
			| PMU0CF_CLEAR__ALL_FLAGS | PMU0CF_CPT0WK__NOT_SET
			| PMU0CF_PMATWK__NOT_SET | PMU0CF_RTCAWK__SET | PMU0CF_RTCFWK__SET;
	NOP();
	NOP(); // Delay to update wake-up flags
	// [PMU0CF - Power Management Unit Configuration]$

	// $[Clock Restore]

	// Restore clock settings
	HFO0CN |= (HFO0CN_save & HFO0CN_IOSCEN__BMASK);
	CLKSEL = CLKSEL_save;
	while (!((CLKSEL & CLKSEL_CLKRDY__BMASK) == CLKSEL_CLKRDY__SET))
		;

	// [Clock Restore]$

}

extern void enter_Sleep_from_DefaultMode(void) {

}

extern void PORTS_1_enter_Sleep_from_DefaultMode(void) {

}

extern void enter_DefaultMode_from_Sleep(void) {

}

extern void PORTS_1_enter_DefaultMode_from_Sleep(void) {

}

extern void VDDMON_0_enter_DefaultMode_from_RESET(void) {
	// $[VDM0CN - VDD Supply Monitor Control]
	/***********************************************************************
	 - Disable the VDD Early Warning interrupt
	 - Disable the VDD supply monitor
	 ***********************************************************************/
	VDM0CN &= ~(VDM0CN_VDDOKIE__BMASK | VDM0CN_VDMEN__BMASK);
	// [VDM0CN - VDD Supply Monitor Control]$

}

