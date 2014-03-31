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
//  int oldval[8];
  int error;
//  size_t len = sizeof(oldval);
//  int i, error;
  int newval[1] = {3};
  int newlen = sizeof(newval);
  uid_t super_user = 0;

  if (0 != setuid(super_user)) {
    perror("Unable to switch to super user");
    exit(1);
  }

//  error = sysctl(name, namelen, (void*)oldval, &len, NULL, 0);
//  if (error) {
//    fprintf(stderr,"%s: sysctl(): %s\n",
//            argv[0],strerror(errno));
//    exit(1);
//  }
////  printf("len is %i bytes\n", len);
//  for (i = 0; i < len/(sizeof(int)); i++)
//    printf("%i\t", oldval[i]);
//  printf("\n");
  error = sysctl(name, namelen, NULL, 0, newval, newlen);
  if (error) {
    fprintf(stderr,"%s: sysctl(): %s\n",
            argv[0],strerror(errno));
    exit(1);
  }
  exit(0);
}

