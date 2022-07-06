#include "linux/uaccess.h"
#include <linux/syscalls.h>
#include <linux/sched.h>

SYSCALL_DEFINE1(mydouble, int, value)
{
    const struct task_struct* curr;
    int result = value*2;


    printk("MY_SYSCALL: the double of %d is %d\n", value, result);

    printk("My process: \n");
    curr = current;
    printk("Prio: [normal: %d, default: %d, static: %d]\n", curr->normal_prio, curr->prio, curr->static_prio);
    printk("Pids: [cur: %d, parent: %d]\n", curr->pid, curr->parent->pid);

    return result;
}

SYSCALL_DEFINE2(get_children, pid_t*, pids, int, max_count)
{
	struct task_struct *c = NULL;
    const pid_t *src = NULL;
    const struct task_struct* curr = current;
    int n = 0;

	list_for_each_entry(c, &curr->children, sibling) {
        if (n >= max_count) {
            return -ENOMEM;
        }
        src = &c->pid;
        if (copy_to_user(pids+n, src, sizeof(pid_t))) {
            return -EFAULT;
        }
        n++;
	}
    return n;
}
