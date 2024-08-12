#include <dirent.h>
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

// ld.lld: error: undefined symbol: fopen64
FILE *fopen64(const char *path, const char *mode) { return fopen(path, mode); }
// ld.lld: error: undefined symbol: stat64
int stat64(const char *path, struct stat *buf) { return stat(path, buf); }
// ld.lld: error: undefined symbol: readdir64
struct dirent *readdir64(DIR *dirp) { return readdir(dirp); }
// ld.lld: error: undefined symbol: lstat64
int lstat64(const char *path, struct stat *buf) { return lstat(path, buf); }
// ld.lld: error: undefined symbol: fstat64
int fstat64(int fd, struct stat *buf) { return fstat(fd, buf); }
// ld.lld: error: undefined symbol: lseek64
off_t lseek64(int fd, off_t offset, int whence) {
  return lseek(fd, offset, whence);
}
// ld.lld: error: undefined symbol: open64
int open64(const char *path, int flags, mode_t mode) {
  return open(path, flags, mode);
}
// ld.lld: error: undefined symbol: gnu_get_libc_version
const char *gnu_get_libc_version(void) { return "glibc"; }
// ld.lld: error: undefined symbol: mmap64
void *mmap64(void *addr, size_t length, int prot, int flags, int fd,
             off_t offset) {
  return mmap(addr, length, prot, flags, fd, offset);
}
// ld.lld: error: undefined symbol: __res_init
int __res_init(void) { return 0; }
// ld.lld: error: undefined symbol: ftruncate64
int ftruncate64(int fd, off_t length) { return ftruncate(fd, length); }
// ld.lld: error: undefined symbol: fcntl64
int fcntl64(int fd, int cmd, ...) {
  va_list ap;
  va_start(ap, cmd);
  int ret = fcntl(fd, cmd, va_arg(ap, void *));
  va_end(ap);
  return ret;
}
// ld.lld: error: undefined symbol: pread64
ssize_t pread64(int fd, void *buf, size_t count, off_t offset) {
  return pread(fd, buf, count, offset);
}
// ld.lld: error: undefined symbol: pwrite64
ssize_t pwrite64(int fd, const void *buf, size_t count, off_t offset) {
  return pwrite(fd, buf, count, offset);
}
