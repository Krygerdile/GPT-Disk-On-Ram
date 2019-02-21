#include <linux/vmalloc.h> 
#include <linux/types.h>
#include <linux/module.h>
#include "partition.h"
#include "ram_disk.h"

#define DISK_SIZE 0x100000
#define BLOCK_SIZE 512
#define DISK_BLOCKS (DISK_SIZE / BLOCK_SIZE)

static u8 *disk;

int ramdisk_init(void)
{
	disk = vmalloc(DISK_SIZE);
	if (disk == NULL)
		return -ENOMEM;

	write_headers(disk);
		
	return DISK_BLOCKS;
}

void ramdisk_cleanup(void)
{
	vfree(disk);
}

void ramdisk_write(sector_t off, u8 *buffer, unsigned int blocks)
{
	memcpy(disk + (off * BLOCK_SIZE), buffer,
	       blocks * BLOCK_SIZE);
}

void ramdisk_read(sector_t off, u8 *buffer, unsigned int blocks)
{
	memcpy(buffer, disk + (off * BLOCK_SIZE), 
	       blocks * BLOCK_SIZE);
}


MODULE_LICENSE("GPL");