rem EMX+GCC required
rem This builds an executable which does not require EMX runtime

gcc -s -O2 -m486 -Zomf -Zlinker /EXEPACK:2 cjbclient.c -lsocket

rem EMX+GCC required
rem This builds an executable which requires EMX runtime

gcc -s -O2 -m486 -Zcrtdll cjbclient.c -lsocket -o cjbclient_emx.exe

lxlite *.exe
