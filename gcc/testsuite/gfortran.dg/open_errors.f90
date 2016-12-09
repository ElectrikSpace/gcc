! { dg-do run { target { ! { *-*-mingw* *-*-cygwin* spu-*-* k1-*-* } } } }
! PR30005 Enhanced error messages for OPEN
! Submitted by Jerry DeLisle  <jvdelisle@gcc.gnu.org>
! See PR38956.  Test fails on cygwin when user has Administrator rights
! As of the fix for PR 65200, the error message is partly generated by
! strerror*(), so can depend on the target and the locale, so check
! only the beginning of the error string, which should be constant.
character(60) :: msg
character(25) :: n = "temptestfile"
logical :: there
inquire(file=n, exist=there)
if (.not.there) then
  open(77,file=n,status="new")
  close(77, status="keep")
endif
msg=""
open(77,file=n,status="new", iomsg=msg, iostat=i)
if (i == 0) call abort()
if (msg(1:33) /= "Cannot open file 'temptestfile': ") call abort()

open(77,file=n,status="old")
close(77, status="delete")
open(77,file=n,status="old", iomsg=msg, iostat=i)
if (i == 0) call abort()
if (msg(1:33) /= "Cannot open file 'temptestfile': ") call abort()

open(77,file="./", iomsg=msg, iostat=i)
if (msg(1:23) /= "Cannot open file './': " &
     .and. msg /= "Invalid argument") call abort()

open(77,file=n,status="new")
i = chmod(n, "-w")
if (i == 0 .and. getuid() /= 0) then
 close(77, status="keep")
 open(77,file=n, iomsg=msg, iostat=i, action="write")
 if (i == 0) call abort()
 if (msg(1:33) /= "Cannot open file 'temptestfile': ") call abort()
endif

i = chmod(n,"+w")
open(77,file=n, iomsg=msg, iostat=i, action="read")
close(77, status="delete")
end
