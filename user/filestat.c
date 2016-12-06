#include "fcntl.h"
#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]) {
  if (argc != 2) {
    printf(1, "Usage: filestat pathname\n");
    exit();
  }

  struct stat st;
  int fd = open(argv[1], O_CREATE|O_RDWR|O_CHECKED);
  fstat(fd, &st);

  printf(1, "Type: %d\n", st.type);
  printf(1, "Device number: %d\n", st.dev);
  printf(1, "Inode number on device: %d\n", st.ino);
  printf(1, "Number of links to file: %d\n", st.nlink);
  printf(1, "Size of file in bytes: %d\n", st.size);
  printf(1, "Checksum of file: %d\n", st.checksum);

  return 0;
}
