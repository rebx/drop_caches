# drop_caches

setuid program to forcibly free inactive pages in linux. Works similar to doing this in the command, line but without having to use sudo.

```bash
sync; echo 3 > /proc/sys/vm/drop_caches
```

## Example

```bash
[rebel@doveglion ~]$ free -m
              total        used        free      shared  buff/cache   available
Mem:           7675        5975         432          74        1267        1383
Swap:          2047         532        1515
[rebel@doveglion ~]$ purge
[rebel@doveglion ~]$ free -m
              total        used        free      shared  buff/cache   available
Mem:           7675        5530        1788          68         355        1839
Swap:          2047         532        1515
```

