#include <linux/types.h>

#ifndef LINUX_SEND_DATA_H
#define LINUX_SEND_DATA_H

struct process_identifier {
	union IdType {
		pid_t pid;
		const char *process_alias;
	} id_type;
};

#endif
