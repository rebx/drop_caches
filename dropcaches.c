/*
 * drop_caches.c
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <linux/sysctl.h>
#include <sys/types.h>

#define DEFAULT_DROP_LEVEL 3

int main(int argc, char **argv) {

  int name[] = {CTL_VM, VM_DROP_PAGECACHE};
  int namelen = 2;
  int error;
  int newval[1] = {3};
  int newlen = sizeof(newval);
  uid_t super_user = 0;

  if (0 != setuid(super_user)) {
    perror("Unable to switch to super user");
    exit(1);
  }

  error = sysctl(name, namelen, NULL, 0, newval, newlen);
  if (error) {
    fprintf(stderr,"%s: sysctl(): %s\n",
            argv[0],strerror(errno));
    exit(1);
  }
  exit(0);
}

