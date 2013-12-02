====================================================================
OS/2 INFORMATIONS
Compiled using EMX.
Shipped in two versions: 
	cjbclient.exe        no need for emx runtime
	cjbclient_emx.exe    needs emx runtime

For any problem related to the OS/2 port: gm.romanato@bitman.cjb.net
====================================================================
FOLLOWS THE ORIGINAL README FILE
====================================================================
CJB Ip Forwarder version 1.0b (and..maybe final :P) by wC

Hi! :)

This is the *nix cjb *automatic* ip forwarding'client!
This client will *automaticly* forward your account
at cjb.net for your dinamic ip!

Something like:

If you want to update your account at .cjb.net to your ip...and...
your username is "egocentric" and password is "whatever"

then you just have to write at the shell prompt:

[shell/]# ./cjbclient egocentric whatever

and it would automaticly forward your host.cjb.net (egocentric.cjb.net)
to your dinamic ip! =)

And...what if you want to forward you account to a *off-line* url?
Easy! =)

just type:

[shell/]# ./cjbclient egocentric whatever http://www.hackers-pt.org/whatever/

Simple hein? =)

So, how do i compile the client?

Easy, just write on the shell

[shell/]# ./configure

And then...follow the instructions! =)


note: the *automatic* forwarding...is done by hading a line to your
      *on_boot_execute_file* :P
      this changes from *nix distribution to distribution!
      Off course...this *auto* forwarding will only work
      if when you boot, you are *allready* connected to the net...

                                                   regardz, wC

                                       Contact info:

                                       http://egocentric.cjb.net
                                       MailTo: wildcoyote@hackers-pt.org
                                       IrcAt: irc.ptnet.org
                                       Nick: wildcoyote
