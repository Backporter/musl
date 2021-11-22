#include <sys/uio.h>
#include "syscall.h"

#ifndef PS4
ssize_t readv(int fd, const struct iovec *iov, int count)
{
	return syscall_cp(SYS_readv, fd, iov, count);
}
#endif
