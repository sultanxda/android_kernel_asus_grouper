/*
 * include/linux/tegra_nvavp.h
 *
 * Copyright (C) 2011 NVIDIA Corp.
 *
 * This file is licensed under the terms of the GNU General Public License
 * version 2. This program is licensed "as is" without any warranty of any
 * kind, whether express or implied.
 */

#ifndef __LINUX_TEGRA_NVAVP_H
#define __LINUX_TEGRA_NVAVP_H

#include <linux/ioctl.h>
#include <linux/types.h>

#define NVAVP_MAX_RELOCATION_COUNT 64

struct nvavp_cmdbuf {
	__u32 mem;
	__u32 offset;
	__u32 words;
};

struct nvavp_reloc {
	__u32 cmdbuf_mem;
	__u32 cmdbuf_offset;
	__u32 target;
	__u32 target_offset;
};

struct nvavp_syncpt {
	__u32 id;
	__u32 value;
};

struct nvavp_pushbuffer_submit_hdr {
	struct nvavp_cmdbuf	cmdbuf;
	struct nvavp_reloc	*relocs;
	__u32			num_relocs;
	struct nvavp_syncpt	*syncpt;
};

struct nvavp_set_nvmap_fd_args {
	__u32 fd;
};

#define NVAVP_IOCTL_MAGIC		'n'

#define NVAVP_IOCTL_SET_NVMAP_FD	_IOW(NVAVP_IOCTL_MAGIC, 0x60, \
					struct nvavp_set_nvmap_fd_args)
#define NVAVP_IOCTL_PUSH_BUFFER_SUBMIT	_IOWR(NVAVP_IOCTL_MAGIC, 0x63, \
					struct nvavp_pushbuffer_submit_hdr)

#define NVAVP_IOCTL_MIN_NR		_IOC_NR(NVAVP_IOCTL_SET_NVMAP_FD)
#define NVAVP_IOCTL_MAX_NR		_IOC_NR(NVAVP_IOCTL_PUSH_BUFFER_SUBMIT)

#endif /* __LINUX_TEGRA_NVAVP_H */