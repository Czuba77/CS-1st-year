#!/bin/bash
cut -d ' ' -f 1,6,7,9 cdlinux.www.log |grep GET |grep 200$ |cut -d ' ' -f 1,3 |sort |uniq | cut -d ' ' -f 2|rev|cut -d '/' -f 1|rev|sort|grep '.iso\|.deb\|tgz'|grep -v '.sh'|sed "s#?.*##"|sed 's/^/F/'|rev|cut -d 'F' -f 1|rev>skrypt1wynik.txt
grep "OK" cdlinux.ftp.log| cut -d '"' -f 2,4 |sort |uniq |cut -d '"' -f 2 |sed "s#.*/##">>skrypt1wynik.txt
cat skrypt1wynik.txt|sort |uniq -c|sort -nr

