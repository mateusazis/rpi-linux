
#include <linux/syscalls.h>
#include <uapi/asm/send_data.h>
#include <linux/kfifo.h>



SYSCALL_DEFINE3(my_send_data,  struct process_identifier __user *, process_id, void  *__user, userData, unsigned int, dataSize)
{
	unsigned int copied;
	long ret;
	const struct task_struct *target = find_task_by_vpid(process_id->id_type.pid);

	if (target == NULL) {
		return -EINVAL;
	}

	
	if ((ret = kfifo_from_user(target->sent_data, userData, dataSize, &copied))) {
		return ret;
	}

	if (copied < dataSize) {
		return -ENOMEM;
	}
	
	return 0;
}

SYSCALL_DEFINE3(my_read_data, struct process_identifier __user *, process_id, void  *__user, userData, unsigned int, dataSize)
{
	unsigned int copied;
	long ret;
	
	if ((ret = kfifo_to_user(current->sent_data, userData, dataSize, &copied))) {
		return ret;
	}
	
	return 0;
}
