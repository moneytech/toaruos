/* vim: tabstop=4 shiftwidth=4 noexpandtab
 * Null Device
 */

#include <system.h>
#include <fs.h>

uint32_t read_null(fs_node_t *node, uint32_t offset, uint32_t size, uint8_t *buffer);
uint32_t write_null(fs_node_t *node, uint32_t offset, uint32_t size, uint8_t *buffer);
void open_null(fs_node_t *node, uint8_t read, uint8_t write);
void close_null(fs_node_t *node);

uint32_t read_null(fs_node_t *node, uint32_t offset, uint32_t size, uint8_t *buffer) {
	if (size < 1) {
		return 0;
	}
	memset(buffer, 0x00, 1);
	return 1;
}

uint32_t write_null(fs_node_t *node, uint32_t offset, uint32_t size, uint8_t *buffer) {
	return size;
}

void open_null(fs_node_t * node, uint8_t read, uint8_t write) {
	return;
}

void close_null(fs_node_t * node) {
	return;
}

fs_node_t * null_device_create() {
	fs_node_t * fnode = malloc(sizeof(fnode));
	fnode->inode = 0;
	fnode->name[0] = 'n';
	fnode->name[1] = 'u';
	fnode->name[2] = 'l';
	fnode->name[3] = 'l';
	fnode->name[4] = '\0';
	fnode->uid = 0;
	fnode->gid = 0;
	fnode->flags = 0;
	fnode->read    = read_null;
	fnode->write   = write_null;
	fnode->open    = open_null;
	fnode->close   = close_null;
	fnode->readdir = NULL;
	fnode->finddir = NULL;
	return fnode;
}