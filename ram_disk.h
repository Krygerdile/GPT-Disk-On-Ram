#ifndef RAMDISK_H
#define RAMDISK_H

#include <linux/types.h>
#include "partition.h"

#define RD_DISK_SIZE DISK_SIZE
#define RD_SECTOR_SIZE 512
#define RD_SECTOR_NUM (DISK_SIZE / SECTOR_SIZE)

extern int ramdisk_init(void);

extern void ramdisk_cleanup(void);

extern void ramdisk_write(sector_t off, u8 *buffer, unsigned int blocks);

extern void ramdisk_read(sector_t off, u8 *buffer, unsigned int blocks);

#endif
