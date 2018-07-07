# Pamela
![badge1](https://img.shields.io/badge/license-MIT-brightgreen.svg)
![badge2](https://img.shields.io/badge/language-C-lightgrey.svg)
## What's that ?
Pamela is a security project that create a pam module to open cipher containers (directories) when a user open his session.
## How to use it ?
Use the "make install" rule of the Makefile to install the dependencies needed.</br>
This rule will also install the module and configure it.
```
>>> make install
```
Now you can check if the module is correctly installed (or not) by using these Makefile rules:
```
>>> make check
```
```
>>> make test
```
If you don't want to use this module you can uninstall it by this rule:
```
>>> make uninstall
```
## How to test it ?
So now you know how to install it, then you have to know how to test it.</br>
First you need to create a new user to test this module by this command:
```
>>> sudo adduser toto
```
If you quit yout currently user cession you can now connect with the new user.</br>
After you have logged in you can see that a private container is created.</br>
In this container, only the right user can use it.</br></br>
You have to write something inside like by creating a "test" file then log out of this cession, reconnect you with an other user and try to go in /home/toto/secure_data-rw.</br>
Normally the access of this folder is not allowed by other user than toto.</br>
If you check inside your private container /home/$you/secure_data-rw, the content is different because the folder is not shared between user.</br></br>
Not reconnect you with toto and access to his private container.</br>Everything is here ? Right ! It's working.
## Some important information:
### Common files:
As you have noticed, some files have been modified by the module:<br>
* /etc/pam.d/common-auth </br>
* /etc/pam.d/common-session </br>
* /etc/pam.d/common-account </br>
* /etc/pam.d/password </br>

It's important to know why and what these files doing.</br></br>
The /etc/pam.d/ directory generally has a configuration file for each application that will request PAM authentication.</br>
If an application calls PAM but there is no associated configuration file, the "other" configuration file is applied.</br>
Inside the configuration files, there are usually calls to include the configuration files that begin with "common-".</br>
These are general configuration files whose rules should be applied in most situations.</br></br>
The modules that are referenced in the configuration files can be located with this command:</br>
```
>>> ls /lib/*/security
```
### Want to know more about PAM ?
* [Digital Ocean](https://www.digitalocean.com/community/tutorials/how-to-use-pam-to-configure-authentication-on-an-ubuntu-12-04-vps)</br>
* [Debian.org](https://www.debian.org/doc/manuals/debian-reference/ch04.fr.html)</br>
