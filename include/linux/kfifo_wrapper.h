#ifndef _LINUX_KFIFO_WRAPPER_H
#define _LINUX_KFIFO_WRAPPER_H

#include <linux/kfifo.h>

struct kfifo_wrapper {
  DECLARE_KFIFO(fifo, char, 2048);
  // DECLARE_KFIFO_PTR(fifo, char);
  // struct kfifo* fifo;
};

#endif
