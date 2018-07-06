To use it during a test, you can simply do the following from your std partition:

```
bash
su root
mkdir /exam
mount /dev/sda6 /exam
mkdir /exam/cheat
cp . /exam/cheat/exam-c-tek-2 -R
umount /exam
rmdir /exam
```
