drop_caches
===========

setuid program to forcibly free inactive pages in linux. Works similar to doing this in the command, line but without having to use sudo.

sync; echo 3 > /proc/sys/vm/drop_caches

