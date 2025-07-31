// init: The initial user-level program

#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int
main(void)
{
  if(open("console", O_RDWR) < 0){
    mknod("console", 1, 1);
    open("console", O_RDWR);
  }
  dup(0);  // stdout
  dup(0);  // stderr

  // Langsung jalankan "audit" sebagai init
  char *argv[] = { "audit", 0 };
  exec("audit", argv);

  // Kalau gagal, tampilkan error dan exit
  printf(1, "init: exec audit failed\n");
  exit();
}

