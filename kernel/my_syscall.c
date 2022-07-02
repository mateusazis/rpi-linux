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