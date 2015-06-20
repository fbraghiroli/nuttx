/********************************************************************************************
 * arch/arm/src/samdl/chip/saml_usb.h
 *
 *   Copyright (C) 2015 Gregory Nutt. All rights reserved.
 *   Author: Gregory Nutt <gnutt@nuttx.org>
 *
 * References:
 *   "Atmel SAM L21E / SAM L21G / SAM L21J Smart ARM-Based Microcontroller
 *   Datasheet", Atmel-42385C-SAML21_Datasheet_Preliminary-03/20/15
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 * 3. Neither the name NuttX nor the names of its contributors may be
 *    used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 * ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 *
 ********************************************************************************************/

#ifndef __ARCH_ARM_SRC_SAMDL_CHIP_SAML_USB_H
#define __ARCH_ARM_SRC_SAMDL_CHIP_SAML_USB_H

/********************************************************************************************
 * Included Files
 ********************************************************************************************/

#include <nuttx/config.h>

#include "chip.h"

#ifdef CONFIG_ARCH_FAMILY_SAML21

/********************************************************************************************
 * Pre-processor Definitions
 ********************************************************************************************/
/* USB register offsets ********************************************************************/

/* Common USB Device/Host Register Offsets */

#define SAM_USB_CTRLA_OFFSET           0x0000 /* Control A Register */
#define SAM_USB_SYNCBUSY_OFFSET        0x0002 /* Synchronization Busy Register */
#define SAM_USB_QOSCTRL_OFFSET         0x0003 /* QOS Control Register */
#define SAM_USB_FSMSTATUS_OFFSET       0x000d /* Finite State Machine Register */
#define SAM_USB_DESCADD_OFFSET         0x0024 /* Descriptor Address Register */
#define SAM_USB_PADCAL_OFFSET          0x0028 /* Pad Calibration Register */

/* USB Device Register Offsets */

#define SAM_USBDEV_CTRLB_OFFSET        0x0008 /* Control B Register */
#define SAM_USBDEV_DADD_OFFSET         0x000a /* Device Address Register */
#define SAM_USBDEV_STATUS_OFFSET       0x000c /* Status Register */
#define SAM_USBDEV_FNUM_OFFSET         0x0010 /* Device Frame Number Register */
#define SAM_USBDEV_INTENCLR_OFFSET     0x0014 /* Device Ineterrupt Enable Clear Register */
#define SAM_USBDEV_INTENSET_OFFSET     0x0018 /* Device interrupt Enable Set Register */
#define SAM_USBDEV_INTFLAG_OFFSET      0x001c /* Device Interrupt Flag Register */
#define SAM_USBDEV_EPINTSMRY_OFFSET    0x0020 /* Endpoint Interrupt Summary Register */

/* Endpoint Register n offset */

#define SAM_USBDEV_EP_OFFSET(n)        (0x0100 + ((n) << 4))

/* The following are then relative to the endpoint register n offset */

#define SAM_USBDEV_EPCFG_OFFSET        0x0000 /* Device Endpoint Configuration Register */
#define SAM_USBDEV_EPSTATUSCLR_OFFSET  0x0004 /* Endpoint Status Clear Register */
#define SAM_USBDEV_EPSTATUSSET_OFFSET  0x0005 /* Endpoint Status Set Register */
#define SAM_USBDEV_EPSTATUS_OFFSET     0x0006 /* Endpoint Status Register */
#define SAM_USBDEV_EPINTFLAG_OFFSET    0x0007 /* Device Endpoint Interrupt Flag Register */
#define SAM_USBDEV_EPINTENCLR_OFFSET   0x0008 /* Device Endpoint Interrupt Enable Register */
#define SAM_USBDEV_EPINTENSET_OFFSET   0x0009 /* Device Endpoint Interrupt Set Register */

#define SAM_USBDEV_EPnCFG_OFFSET(n)       (SAM_USBDEV_EP_OFFSET(n)+SAM_USBDEV_EPCFG_OFFSET)
#define SAM_USBDEV_EPnSTATUSCLR_OFFSET(n) (SAM_USBDEV_EP_OFFSET(n)+SAM_USBDEV_EPSTATUSCLR_OFFSET)
#define SAM_USBDEV_EPnSTATUSSET_OFFSET(n) (SAM_USBDEV_EP_OFFSET(n)+SAM_USBDEV_EPSTATUSSET_OFFSET)
#define SAM_USBDEV_EPnSTATUS_OFFSET(n)    (SAM_USBDEV_EP_OFFSET(n)+SAM_USBDEV_EPSTATUS_OFFSET)
#define SAM_USBDEV_EPnINTFLAG_OFFSET(n)   (SAM_USBDEV_EP_OFFSET(n)+SAM_USBDEV_EPINTFLAG_OFFSET)
#define SAM_USBDEV_EPnINTENCLR_OFFSET(n)  (SAM_USBDEV_EP_OFFSET(n)+SAM_USBDEV_EPINTENCLR_OFFSET)
#define SAM_USBDEV_EPnINTENSET_OFFSET(n)  (SAM_USBDEV_EP_OFFSET(n)+SAM_USBDEV_EPINTENSET_OFFSET)

/* Device Endpoint Descriptor */

#define SAM_USBDEV_ADDR_OFFSET         0x0000 /* Address of Data buffer (Both banks) */
#define SAM_USBDEV_PKTSIZE_OFFSET      0x0004 /* Packet Size (Both banks) */
#define SAM_USBDEV_EXTREG_OFFSET       0x0008 /* Extended Register (Bank 0 only) */
#define SAM_USBDEV_STATUSBK_OFFSET     0x000a /* Device Status Bank (Both banks) */

/* USB Host Register Offsets */

/* USB register addresses ******************************************************************/

/* Common USB Device/Host Register Addresses */

#define SAM_USB_CTRLA                  (SAM_USB_BASE+SAM_USB_CTRLA_OFFSET)
#define SAM_USB_SYNCBUSY               (SAM_USB_BASE+SAM_USB_SYNCBUSY_OFFSET)
#define SAM_USB_QOSCTRL                (SAM_USB_BASE+SAM_USB_QOSCTRL_OFFSET)
#define SAM_USB_FSMSTATUS              (SAM_USB_BASE+SAM_USB_FSMSTATUS_OFFSET)
#define SAM_USB_DESCADD                (SAM_USB_BASE+SAM_USB_DESCADD_OFFSET)
#define SAM_USB_PADCAL                 (SAM_USB_BASE+SAM_USB_PADCAL_OFFSET)

/* USB Device Register Addresses */

#define SAM_USBDEV_CTRLB               (SAM_USB_BASE+SAM_USBDEV_CTRLB_OFFSET)
#define SAM_USBDEV_DADD                (SAM_USB_BASE+SAM_USBDEV_DADD_OFFSET)
#define SAM_USBDEV_STATUS              (SAM_USB_BASE+SAM_USBDEV_STATUS_OFFSET)
#define SAM_USBDEV_FNUM                (SAM_USB_BASE+SAM_USBDEV_FNUM_OFFSET)
#define SAM_USBDEV_INTENCLR            (SAM_USB_BASE+SAM_USBDEV_INTENCLR_OFFSET)
#define SAM_USBDEV_INTENSET            (SAM_USB_BASE+SAM_USBDEV_INTENSET_OFFSET)
#define SAM_USBDEV_INTFLAG             (SAM_USB_BASE+SAM_USBDEV_INTFLAG_OFFSET)
#define SAM_USBDEV_EPINTSMRY           (SAM_USB_BASE+SAM_USBDEV_EPINTSMRY_OFFSET)

/* Endpoint Register n Base Address */

#define SAM_USBDEV_EP_BASE(n)          (SAM_USB_BASE+SAM_USBDEV_EP_OFFSET(n))

/* The following are then relative to the endpoint register n offset */

#define SAM_USBDEV_EPCFG(n)            (SAM_USBDEV_EP_BASE(n)+SAM_USBDEV_EPCFG_OFFSET)
#define SAM_USBDEV_EPSTATUSCLR(n)      (SAM_USBDEV_EP_BASE(n)+SAM_USBDEV_EPSTATUSCLR_OFFSET)
#define SAM_USBDEV_EPSTATUSSET(n)      (SAM_USBDEV_EP_BASE(n)+SAM_USBDEV_EPSTATUSSET_OFFSET)
#define SAM_USBDEV_EPSTATUS(n)         (SAM_USBDEV_EP_BASE(n)+SAM_USBDEV_EPSTATUS_OFFSET)
#define SAM_USBDEV_EPINTFLAG(n)        (SAM_USBDEV_EP_BASE(n)+SAM_USBDEV_EPINTFLAG_OFFSET)
#define SAM_USBDEV_EPINTENCLR(n)       (SAM_USBDEV_EP_BASE(n)+SAM_USBDEV_EPINTENCLR_OFFSET)
#define SAM_USBDEV_EPINTENSET(n)       (SAM_USBDEV_EP_BASE(n)+SAM_USBDEV_EPINTENSET_OFFSET)

/* USB Host Register Addresses */

/* USB register bit definitions ************************************************************/

/* Common USB Device/Host Register Offsets */

/* Control A Register */

#define USB_CTRLA_SWRST                (1 << 0)  /* Bit 0:  Software reset */
#define USB_CTRLA_ENABLE               (1 << 1)  /* Bit 1:  Enable */
#define USB_CTRLA_RUNSTBY              (1 << 2)  /* Bit 2:  Run in standby */
#define USB_CTRLA_MODE                 (1 << 7)  /* Bit 7:  Operating mode */
#  define USB_CTRLA_MODE_DEVICE        (0)       /*         0 = USB device mode */
#   define USB_CTRLA_MODE              (1 << 7)  /*         1 = USB hose mode */

/* Synchronization Busy Register */

#define USB_SYNCBUSY_SWRST             (1 << 0)  /* Bit 0:  Software reset status */
#define USB_SYNCBUSY_ENABLE            (1 << 1)  /* Bit 1:  Enable status */

/* QOS Control Register */

#define USB_QOSCTRL_CQOS_SHIFT         (0)       /* Bit 0-1: Data quality of service */
#define USB_QOSCTRL_CQOS_MASK          (3 << USB_QOSCTRL_CQOS_SHIFT)
#  define USB_QOSCTRL_CQOS(n)          ((uint8_t)(n) << USB_QOSCTRL_CQOS_SHIFT)
#define USB_QOSCTRL_DQOS_SHIFT         (2)       /* Bit 2-3: Configuration qualilty of service */
#define USB_QOSCTRL_DQOS_MASK          (3 << USB_QOSCTRL_DQOS_SHIFT)
#  define USB_QOSCTRL_DQOS(n)          ((uint8_t)(n) << USB_QOSCTRL_DQOS_SHIFT)

/* Finite State Machine Register */

#define USB_FSMSTATUS_SHIFT            (0)       /* Bits 0-6:  Finite state machine status */
#define USB_FSMSTATUS_MASK             (0x7f  << USB_FSMSTATUS_SHIFT)
#  define USB_FSMSTATUS_OFF            (0x01  << USB_FSMSTATUS_SHIFT) /* Powered-off, disconnect, disabled state */
#  define USB_FSMSTATUS_ON             (0x02  << USB_FSMSTATUS_SHIFT) /* Idle and Active states */
#  define USB_FSMSTATUS_SUSPEND        (0x04  << USB_FSMSTATUS_SHIFT)
#  define USB_FSMSTATUS_SLEEP          (0x08  << USB_FSMSTATUS_SHIFT)
#  define USB_FSMSTATUS_DNRESUME       (0x10  << USB_FSMSTATUS_SHIFT) /* Down stream resume */
#  define USB_FSMSTATUS_UPRESUME       (0x20  << USB_FSMSTATUS_SHIFT) /* Up stream resume */
#  define USB_FSMSTATUS_RESET          (0x40  << USB_FSMSTATUS_SHIFT) /* USB lines reset */

/* Descriptor Address Register (32-bit address) */

/* Pad Calibration Register */

#define USB_PADCAL_TRANSP_SHIFT        (0)       /* Bit 0-4: Trimmable output driver impedance P */
#define USB_PADCAL_TRANSP_MASK         (31 << USB_PADCAL_TRANSP_SHIFT)
#  define USB_PADCAL_TRANSP(n)         ((uint16_t)(n) << USB_PADCAL_TRANSP_SHIFT)
#define USB_PADCAL_TRANSN_SHIFT        (6)       /* Bit 7-9: Trimmable output driver impedance N */
#define USB_PADCAL_TRANSN_MASK         (31 << USB_PADCAL_TRANSN_SHIFT)
#  define USB_PADCAL_TRANSN(n)         ((uint16_t)(n) << USB_PADCAL_TRANSN_SHIFT)
#define USB_PADCAL_TRIM_SHIFT          (12)      /* Bit 12-14: Trim bits for DP/DM */
#define USB_PADCAL_TRIM_MASK           (7 << USB_PADCAL_TRIM_SHIFT)
#  define USB_PADCAL_TRIM(n)           ((uint16_t)(n) << USB_PADCAL_TRIM_SHIFT)

/* USB Device Register Offsets */

/* Control B Register */

#define USBDEV_CTRLB_DETACH            (1 << 0)  /* Bit 0:  Detach */
#define USBDEV_CTRLB_UPRSM             (1 << 1)  /* Bit 1:  Upstresm resume */
#define USBDEV_CTRLB_SPDCONF_SHIFT     (2)       /* Bits 2-3: Speed configuration */
#define USBDEV_CTRLB_SPDCONF_MASK      (3 << USBDEV_CTRLB_SPDCONF_SHIFT)
#  define USBDEV_CTRLB_SPDCONF_LOW     (0 << USBDEV_CTRLB_SPDCONF_SHIFT) /* Low speed */
#  define USBDEV_CTRLB_SPDCONF_FULL    (1 << USBDEV_CTRLB_SPDCONF_SHIFT) /* Full speed */
#define USBDEV_CTRLB_NREPLY            (1 << 4)  /* Bit 4:  No reply except SETUP token */
#define USBDEV_CTRLB_GNAK              (1 << 9)  /* Bit 9:  Global NAK */
#define USBDEV_CTRLB_LPMHDSK_SHIFT     (10)      /* Bits 10-11: Link power management handshake */
#define USBDEV_CTRLB_LPMHDSK_MASK      (3 << USBDEV_CTRLB_LPMHDSK_SHIFT)
#  define USBDEV_CTRLB_LPMHDSK_NONE    (0 << USBDEV_CTRLB_LPMHDSK_SHIFT) /* No handshake, LPM not supported */
#  define USBDEV_CTRLB_LPMHDSK_ACK     (1 << USBDEV_CTRLB_LPMHDSK_SHIFT)
#  define USBDEV_CTRLB_LPMHDSK_NYET    (2 << USBDEV_CTRLB_LPMHDSK_SHIFT)

/* Device Address Register */

#define USBDEV_DADD_SHIFT              (0)       /* Bits 0-6: Device address */
#define USBDEV_DADD_MASK               (0x7f << USBDEV_DADD_SHIFT)
#  define USBDEV_DADD(n)               ((uint8_t)(n) << USBDEV_DADD_SHIFT)
#define USBDEV_DADD_ADDEN              (1 << 7)  /* Bit 7:  Device address enable */

/* Status Register */

#define USBDEV_STATUS_SPEED_SHIFT      (0)       /* Bits 0-1: Speed status */
#define USBDEV_STATUS_SPEED_MASK       (3 << USBDEV_STATUS_SPEED_SHIFT)
#  define USBDEV_STATUS_SPEED_LOW      (0 << USBDEV_STATUS_SPEED_SHIFT) /* Low speed */
#  define USBDEV_STATUS_SPEED_FULL     (1 << USBDEV_STATUS_SPEED_SHIFT) /* Full speed */
#define USBDEV_STATUS_LNSTATE_SHIFT    (6)       /* Bits 6-7:  USB line status */
#define USBDEV_STATUS_LNSTATE_MASK     (3 << USBDEV_STATUS_LNSTATE_SHIFT)
#  define USBDEV_STATUS_LNSTATE_SE0    (0 << USBDEV_STATUS_LNSTATE_SHIFT) /* SE0/RESET */
#  define USBDEV_STATUS_LNSTATE_LJFK   (1 << USBDEV_STATUS_LNSTATE_SHIFT) /* LS-J or FS-K */
#  define USBDEV_STATUS_LNSTATE_LKFJ   (2 << USBDEV_STATUS_LNSTATE_SHIFT) /* LS-K or FS-L */

/* Device Frame Number Register */

#define USBDEV_MFNUM_SHIFT             (0)      /* Bits 0-2: Micro-frame number */
#define USBDEV_MFNUM_MASK              (7 << USBDEV_MFNUM_SHIFT)
#define USBDEV_FNUM_SHIFT              (3)      /* Bits 3-13: Frame number */
#define USBDEV_FNUM_MASK               (0x7ff << USBDEV_FNUM_SHIFT)
#define USBDEV_FNUM_FNCERR             (1 << 15) /* Bit 15: Frame number CRC error */

/* Common definitions for  Device Ineterrupt Enable Clear Register, Device interrupt
 * Enable Set Register, and SAM_USBDEV_INTFLAG_OFFSET
 */

#define USBDEV_INT_SUSPEND             (1 << 0)  /* Bit 0:  Suspend interrupt */
#define USBDEV_INT_SOF                 (1 << 2)  /* Bit 2:  Start of frame interrupt */
#define USBDEV_INT_EORST               (1 << 3)  /* Bit 3:  End of reset interrupt */
#define USBDEV_INT_WAKEUP              (1 << 4)  /* Bit 4:  Wake-up interrupt */
#define USBDEV_INT_EORSM               (1 << 5)  /* Bit 5:  End of resume interrupt */
#define USBDEV_INT_UPRSM               (1 << 6)  /* Bit 6:  Upstream resume interrupt */
#define USBDEV_INT_RAMACER             (1 << 7)  /* Bit 7:  RAM access interrupt */
#define USBDEV_INT_LPMNYET             (1 << 8)  /* Bit 8:  Link power NotYet interrupt */
#define USBDEV_INT_LPMSUSP             (1 << 9)  /* Bit 9:  Link power suspend interrupt */

/* Endpoint Interrupt Summary Register */

#define USBDEV_EPINTSMRY_EPINT(n)      (1 << (n))

/* Device Endpoint Configuration Register */

#define USBDEV_EPCFG_EPTYPE0_SHIFT       (0)       /* Bits 0-2: Endpoint type for OUT direction */
#define USBDEV_EPCFG_EPTYPE0_MASK        (7 << USBDEV_EPCFG_EPTYPE0_SHIFT)
#  define USBDEV_EPCCFG_EPTYPE0_DISABLED (0 << USBDEV_EPCFG_EPTYPE0_SHIFT) /* Bank 0 disabled */
#  define USBDEV_EPCCFG_EPTYPE0_CTRLOUT  (1 << USBDEV_EPCFG_EPTYPE0_SHIFT) /* Bank 0 control SETUP/OUT */
#  define USBDEV_EPCCFG_EPTYPE0_ISOCOUT  (2 << USBDEV_EPCFG_EPTYPE0_SHIFT) /* Bank 0 isochronous OUT */
#  define USBDEV_EPCCFG_EPTYPE0_BULKOUT  (3 << USBDEV_EPCFG_EPTYPE0_SHIFT) /* Bank 0 bulk OUT */
#  define USBDEV_EPCCFG_EPTYPE0_INTOUT   (4 << USBDEV_EPCFG_EPTYPE0_SHIFT) /* Bank 0 interrupt OUT */
#  define USBDEV_EPCCFG_EPTYPE0_DBIN     (5 << USBDEV_EPCFG_EPTYPE0_SHIFT) /* Bank 0 dual bank IN */
#define USBDEV_EPCFG_EPTYPE1_SHIFT       (4)       /* Bits 4-6: Endpoint type for IN direction */
#define USBDEV_EPCFG_EPTYPE1_MASK        (7 << USBDEV_EPCFG_EPTYPE1_SHIFT)
#  define USBDEV_EPCCFG_EPTYPE1_DISABLED (0 << USBDEV_EPCFG_EPTYPE1_SHIFT) /* Bank 1 disabled */
#  define USBDEV_EPCCFG_EPTYPE1_CTRLIN   (1 << USBDEV_EPCFG_EPTYPE1_SHIFT) /* Bank 1 control IN */
#  define USBDEV_EPCCFG_EPTYPE1_ISOCIN   (2 << USBDEV_EPCFG_EPTYPE1_SHIFT) /* Bank 1 isochronous IN */
#  define USBDEV_EPCCFG_EPTYPE1_BULKIN   (3 << USBDEV_EPCFG_EPTYPE1_SHIFT) /* Bank 1 bulk IN */
#  define USBDEV_EPCCFG_EPTYPE1_INTIN    (4 << USBDEV_EPCFG_EPTYPE1_SHIFT) /* Bank 1 interrupt IN */
#  define USBDEV_EPCCFG_EPTYPE1_DBOUT    (5 << USBDEV_EPCFG_EPTYPE1_SHIFT) /* Bank 1 dual bank OUT */

/* Common definitions for Endpoint Status Clear Register, Endpoint Status Set
 * Register, and Endpoint Status Set Register
 */

#define USBDEV_EPSTATUS_DTGLOUT        (1 << 0)  /* Bit 0:  Data toggle OUT */
#define USBDEV_EPSTATUS_DTGLIN         (1 << 1)  /* Bit 1:  Data toggle IN */
#define USBDEV_EPSTATUS_CURBK          (1 << 2)  /* Bit 2:  Current bank */
#define USBDEV_EPSTATUS_STALLRQ0       (1 << 4)  /* Bit 4:  Stall bank 0 request */
#define USBDEV_EPSTATUS_STALLRQ1       (1 << 5)  /* Bit 5:  Stall bank 1 request */
#define USBDEV_EPSTATUS_BK0RDY         (1 << 6)  /* Bit 6:  Bank 0 ready */
#define USBDEV_EPSTATUS_BK1RDY         (1 << 7)  /* Bit 7:  Bank 1 ready */

/* Common definitions for Device Endpoint Interrupt Flag Register, Device Endpoint
 * Interrupt Enable Register, and Device Endpoint Interrupt Set Register
 */

#define USBDEV_EPINT_TRCPT0            (1 << 0)  /* Bit 0:  Transmit complete 0 interrupt */
#define USBDEV_EPINT_TRCPT1            (1 << 1)  /* Bit 1:  Transmit complete 1 interrupt */
#define USBDEV_EPINT_TRFAIL0           (1 << 2)  /* Bit 2:  Transmit fail 0 interrupt */
#define USBDEV_EPINT_TRFAIL1           (1 << 3)  /* Bit 3:  Transmit fail 1 interrupt */
#define USBDEV_EPINT_RXSTP             (1 << 4)  /* Bit 4:  Received SETUP interrupt */
#define USBDEV_EPINT_STALL0            (1 << 5)  /* Bit 5:  Transmit stall 0 interrupt */
#define USBDEV_EPINT_STALL1            (1 << 6)  /* Bit 5:  Transmit stall 1 interrupt */

/* Device Endpoint Descriptor */

/* Address of Data buffer (Both banks, 32-bit address) */

/* Packet Size (Both banks) */

#define USBDEV_PKTSIZE_BYTECOUNT_SHIFT (0)      /* Bits 0-5:  */
#define USBDEV_PKTSIZE_BYTECOUNT_MASK  (0x3f << USBDEV_PKTSIZE_BYTECOUNT_SHIFT)
#  define USBDEV_PKTSIZE_BYTECOUNT(n)  ((uint32_t)(n) << USBDEV_PKTSIZE_BYTECOUNT_SHIFT)
#define USBDEV_PKTSIZE_MPKTSIZE_SHIFT  (14)      /* Bits 14-27:  Multi-packet size */
#define USBDEV_PKTSIZE_MPKTSIZE_MASK   (0x3fff << USBDEV_PKTSIZE_MPKTSIZE_SHIFT)
#  define USBDEV_PKTSIZE_MPKTSIZE(n)   ((uint32_t)(n) << USBDEV_PKTSIZE_MPKTSIZE_SHIFT)
#define USBDEV_PKTSIZE_SIZE_SHIFT      (28)      /* Bits 28-30: Endpoint size */
#define USBDEV_PKTSIZE_SIZE_MASK       (7 << USBDEV_PKTSIZE_SIZE_SHIFT)
#  define USBDEV_PKTSIZE_SIZE_8B       (0 << USBDEV_PKTSIZE_SIZE_SHIFT) /* 8 bytes */
#  define USBDEV_PKTSIZE_SIZE_16B      (1 << USBDEV_PKTSIZE_SIZE_SHIFT) /* 16 bytes */
#  define USBDEV_PKTSIZE_SIZE_32B      (2 << USBDEV_PKTSIZE_SIZE_SHIFT) /* 32 bytes */
#  define USBDEV_PKTSIZE_SIZE_64B      (3 << USBDEV_PKTSIZE_SIZE_SHIFT) /* 64 bytes */
#  define USBDEV_PKTSIZE_SIZE_128B     (4 << USBDEV_PKTSIZE_SIZE_SHIFT) /* 128 bytes (isoc only) */
#  define USBDEV_PKTSIZE_SIZE_256B     (5 << USBDEV_PKTSIZE_SIZE_SHIFT) /* 256 bytes (isoc only) */
#  define USBDEV_PKTSIZE_SIZE_512B     (6 << USBDEV_PKTSIZE_SIZE_SHIFT) /* 512 bytes (isoc only) */
#  define USBDEV_PKTSIZE_SIZE_1023B    (7 << USBDEV_PKTSIZE_SIZE_SHIFT) /* 1023 bytes (isoc only) */
#define USBDEV_PKTSIZE_AUTOZLP         (1 << 31) /* Bit 31: Automatic zero length packet */

/* Extended Register (Bank 0 only) */

#define USBDEV_EXTREG_SUBPID_SHIFT     (0)       /* Bits 0-3: Sub PID */
#define USBDEV_EXTREG_SUBPID_MASK      (15 << USBDEV_EXTREG_SUBPID_SHIFT)
#  define USBDEV_EXTREG_SUBPID(n)      ((uint16_t)(n) << USBDEV_EXTREG_SUBPID_SHIFT)
#define USBDEV_EXTREG_VARIABLE_SHIFT   (4)       /* Bits 4-14:  Variable */
#define USBDEV_EXTREG_VARIABLE_MASK    (0x7ff << USBDEV_EXTREG_VARIABLE_SHIFT)
#  define USBDEV_EXTREG_VARIABLE(n)    ((uint16_t)(n) << USBDEV_EXTREG_VARIABLE_SHIFT)

/* Device Status Bank (Both banks) */

#define USBDEV_STATUSBK_CRCERR         (1 << 0)  /* Bit 0:  CRC error */
#define USBDEV_STATUSBK_ERRORFLOW      (1 << 1)  /* Bit 1:  Error flow status */

/* USB Host Register Offsets */

/********************************************************************************************
 * Public Types
 ********************************************************************************************/

/* Device Endpoint Descriptor */

struct usbdev_epdesc_s
{
  uint32_t addr;        /* 0x0000-0x0003: Address of Data buffer (Both banks) */
  uint32_t pktsize;     /* 0x0004-0x0007: Packet Size (Both banks) */
  uint16_t extreg;      /* 0x0008-0x0009: Extended Register (Bank 0 only) */
  uint8_t  stausbk;     /* 0x000a-0x000a: Device Status Bank (Both banks) */
  uint8_t  reserved[5]; /* 0x000b-0x000f: Both banks */
};

/********************************************************************************************
 * Public Data
 ********************************************************************************************/

/********************************************************************************************
 * Public Functions
 ********************************************************************************************/

#endif /* CONFIG_ARCH_FAMILY_SAML21 */
#endif /* __ARCH_ARM_SRC_SAMDL_CHIP_SAML_USB_H */
