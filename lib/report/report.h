/*
 * Copyright (C) 2002-2004 Sistina Software, Inc. All rights reserved.
 * Copyright (C) 2004-2009 Red Hat, Inc. All rights reserved.
 *
 * This file is part of LVM2.
 *
 * This copyrighted material is made available to anyone wishing to use,
 * modify, copy, or redistribute it subject to the terms and conditions
 * of the GNU Lesser General Public License v.2.1.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef _LVM_REPORT_H
#define _LVM_REPORT_H

#include "metadata-exported.h"
#include "label.h"
#include "activate.h"

typedef enum {
	LVS		= 1,
	LVSINFO		= 2,
	LVSSTATUS	= 4,
	PVS		= 8,
	VGS		= 16,
	SEGS		= 32,
	SEGSSTATUS	= 64,
	PVSEGS		= 128,
	LABEL		= 256,
	DEVTYPES	= 512
} report_type_t;

struct field;
struct report_handle;

typedef int (*field_report_fn) (struct report_handle * dh, struct field * field,
				const void *data);

void *report_init(struct cmd_context *cmd, const char *format, const char *keys,
		  report_type_t *report_type, const char *separator,
		  int aligned, int buffered, int headings, int field_prefixes,
		  int quoted, int columns_as_rows, const char *selection);
void report_free(void *handle);
int report_object(void *handle, const struct volume_group *vg,
		  const struct logical_volume *lv, const struct physical_volume *pv,
		  const struct lv_segment *seg, const struct pv_segment *pvseg,
		  const struct lvinfo *lvinfo, const struct lv_seg_status *lv_seg_status,
		  const struct label *label);
int report_devtypes(void *handle);
int report_output(void *handle);

#endif
