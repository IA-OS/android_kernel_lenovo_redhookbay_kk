/*
 * Support for Intel Camera Imaging ISP subsystem.
 *
 * Copyright (c) 2010 - 2014 Intel Corporation. All Rights Reserved.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License version
 * 2 as published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 *
 */

#ifndef __IA_CSS_ISYS_H__
#define __IA_CSS_ISYS_H__

#include "input_system.h"
#include "ia_css.h"
#include "ia_css_isys_comm.h"

#ifdef USE_INPUT_SYSTEM_VERSION_2401
/**
 * Virtual Input System. (Input System 2401)
 */
typedef input_system_cfg_t	ia_css_isys_descr_t;
/** end of Virtual Input System */
#endif

#if defined(USE_INPUT_SYSTEM_VERSION_2) || defined(USE_INPUT_SYSTEM_VERSION_2401)
input_system_error_t ia_css_isys_init(void);
void ia_css_isys_uninit(void);
#endif

#if defined(USE_INPUT_SYSTEM_VERSION_2401)
enum ia_css_err ia_css_isys_csi_rx_register_stream(
	enum ia_css_csi2_port port,
	uint32_t sp_thread_id);

enum ia_css_err ia_css_isys_csi_rx_unregister_stream(
	enum ia_css_csi2_port port,
	uint32_t sp_thread_id);
#endif

#if !defined(USE_INPUT_SYSTEM_VERSION_2401)
/* CSS Receiver */
void ia_css_isys_rx_configure(
	const rx_cfg_t *config,
	const enum ia_css_input_mode input_mode);

void ia_css_isys_rx_disable(void);

void ia_css_isys_rx_enable_all_interrupts(void);

unsigned int ia_css_isys_rx_get_interrupt_reg(void);
#endif /* #if !defined(USE_INPUT_SYSTEM_VERSION_2401) */

/** @brief Translate format and compression to format type.
 *
 * @param[in]	input_format	The input format.
 * @param[in]	compression	The compression scheme.
 * @param[out]	fmt_type	Pointer to the resulting format type.
 * @return			Error code.
 *
 * Translate an input format and mipi compression pair to the fmt_type.
 * This is normally done by the sensor, but when using the input fifo, this
 * format type must be sumitted correctly by the application.
 */
enum ia_css_err ia_css_isys_convert_stream_format_to_mipi_format(
		enum ia_css_stream_format input_format,
		mipi_predictor_t compression,
		unsigned int *fmt_type);

#ifdef USE_INPUT_SYSTEM_VERSION_2401
/**
 * Virtual Input System. (Input System 2401)
 */
extern ia_css_isys_error_t ia_css_isys_stream_create(
		ia_css_isys_descr_t	*isys_stream_descr,
		ia_css_isys_stream_h	isys_stream);

extern void ia_css_isys_stream_destroy(
		ia_css_isys_stream_h	isys_stream);

extern ia_css_isys_error_t ia_css_isys_stream_calculate_cfg(
		ia_css_isys_stream_h		isys_stream,
		ia_css_isys_descr_t		*isys_stream_descr,
		ia_css_isys_stream_cfg_t	*isys_stream_cfg);

extern void ia_css_isys_csi_rx_lut_rmgr_init(void);

extern void ia_css_isys_csi_rx_lut_rmgr_uninit(void);

extern bool ia_css_isys_csi_rx_lut_rmgr_acquire(
	csi_rx_backend_ID_t		backend,
	csi_mipi_packet_type_t		packet_type,
	csi_rx_backend_lut_entry_t	*entry);

extern void ia_css_isys_csi_rx_lut_rmgr_release(
	csi_rx_backend_ID_t		backend,
	csi_mipi_packet_type_t		packet_type,
	csi_rx_backend_lut_entry_t	*entry);


extern void ia_css_isys_ibuf_rmgr_init(void);

extern void ia_css_isys_ibuf_rmgr_uninit(void);

extern bool ia_css_isys_ibuf_rmgr_acquire(
	uint32_t	size,
	uint32_t	*start_addr);

extern void ia_css_isys_ibuf_rmgr_release(
	uint32_t	*start_addr);

extern void ia_css_isys_dma_channel_rmgr_init(void);

extern void ia_css_isys_dma_channel_rmgr_uninit(void);

extern bool ia_css_isys_dma_channel_rmgr_acquire(
	isys2401_dma_ID_t	dma_id,
	isys2401_dma_channel	*channel);

extern void ia_css_isys_dma_channel_rmgr_release(
	isys2401_dma_ID_t	dma_id,
	isys2401_dma_channel	*channel);

extern void ia_css_isys_stream2mmio_sid_rmgr_init(void);

extern void ia_css_isys_stream2mmio_sid_rmgr_uninit(void);

extern bool ia_css_isys_stream2mmio_sid_rmgr_acquire(
	stream2mmio_ID_t	stream2mmio,
	stream2mmio_sid_ID_t	*sid);

extern void ia_css_isys_stream2mmio_sid_rmgr_release(
	stream2mmio_ID_t	stream2mmio,
	stream2mmio_sid_ID_t	*sid);

/** end of Virtual Input System */
#endif

#endif				/* __IA_CSS_ISYS_H__ */
