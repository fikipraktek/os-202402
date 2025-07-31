#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(void)
{
  int fd = open("/dev/random", O_RDONLY);
  if(fd < 0){
    printf(1, "error opening /dev/random\n");
    exit();
  }

  char buf[16];
  if(read(fd, buf, sizeof(buf)) != sizeof(buf)){
    printf(1, "error reading /dev/random\n");
    exit();
  }

  printf(1, "random bytes: ");
  for(int i = 0; i < sizeof(buf); i++)
    printf(1, "%d ", (uchar)buf[i]);
  printf(1, "\n");

  close(fd);
  exit();
}
