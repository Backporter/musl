#include <unistd.h>
#include <fcntl.h>
#include "syscall.h"

#ifndef PS4
int access(const char *filename, int amode)
{
#ifdef SYS_access
	return syscall(SYS_access, filename, amode);
#else
	return syscall(SYS_faccessat, AT_FDCWD, filename, amode, 0);
#endif
}
#endif
