#define PAM_SM_ACCOUNT
#define PAM_SM_AUTH
#define PAM_SM_PASSWORD
#define PAM_SM_SESSION

#include <security/pam_appl.h>
#include <security/pam_modules.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <pwd.h>

void	new_container(const struct passwd *pwd, const char *containerName, const char *password, const char *user_name)
{
  char          cmd[128];

  snprintf(cmd, 128, "dd if=/dev/zero of=%s/%s bs=1 count=0 seek=10G", pwd->pw_dir, containerName); /* creation of a file that will be converted into a cipher container */
  system(cmd);
  snprintf(cmd, 128, "echo %s | cryptsetup luksFormat %s/%s", password, pwd->pw_dir,containerName); /* creation of a cipher container */
  system(cmd);
  snprintf(cmd, 128, "mkdir %s/secure_data-rw", pwd->pw_dir); /* creation of a mounting folder */
  system(cmd);
  snprintf(cmd, 128, "echo %s | cryptsetup luksOpen %s/%s %s", password,
	   pwd->pw_dir, containerName, containerName); /* opening of the cipher container */
  system(cmd);
  snprintf(cmd, 128, "mkfs.ext4 /dev/mapper/%s", containerName); /* format the container on Ext4 */
  system(cmd);
  snprintf(cmd, 128, "mount /dev/mapper/%s %s/secure_data-rw", containerName, pwd->pw_dir); /* create the mount point */
  system(cmd);
  snprintf(cmd, 128, "chown %s:%s -R %s/secure_data-rw", user_name, user_name, pwd->pw_dir); /* give rights to the appropriate user */
  system(cmd);
}

void	secure_container(const struct passwd *pwd, const char *containerName, const char *password, const char *user_name)
{
  char          cmd[128];

  system("mkdir secure_data-rw");
  snprintf(cmd, 128, "echo %s | cryptsetup luksOpen %s/%s %s", password,
	   pwd->pw_dir, containerName, containerName); /* opening of the cipher container */
  system(cmd);
  snprintf(cmd, 128, "mount /dev/mapper/%s %s/secure_data-rw", containerName, pwd->pw_dir); /* create the mount point */
  system(cmd);
  snprintf(cmd, 128, "chown %s:%s -R %s/secure_data-rw", user_name, user_name, pwd->pw_dir); /* give the rights to the appropriate user */
  system(cmd);
}

int	pam_sm_open_session(pam_handle_t *pamh, int flags, int ac, const char **av)
{
  const char    *user_name = NULL;
  struct passwd	*pwd = NULL;
  struct passwd result;
  char		buffer[1024];
  char		*password;
  char		containerName[256];
  char		to_check[256];

  (void)flags;
  (void)ac;
  (void)av;
  if (pam_get_user(pamh, &user_name, NULL) != PAM_SUCCESS || user_name == NULL) /* get the right user */
    return (PAM_IGNORE);
  if (!strcmp(user_name, strdup("root"))) /* check if the selected user is currently root */
    return (PAM_IGNORE);
  pam_get_data(pamh, "user_password", (const void **)(&password)); /* get the selected user's password */
  if (getpwnam_r(user_name, &result, buffer, sizeof(buffer), &pwd) != 0 || pwd == NULL || pwd->pw_dir == NULL || pwd->pw_dir[0] != '/') /* get the selected user's home path */
    return (PAM_IGNORE);
  snprintf(containerName, 256, "%sContainer", user_name);
  snprintf(to_check, 256, "%s/%s", pwd->pw_dir, containerName);
  if (access(to_check, F_OK) == -1) /* check if the selected user's container already exist */
    new_container(pwd, containerName, password, user_name); /* create a new container */
  else
    secure_container(pwd, containerName, password, user_name); /* secure the container */
  return (PAM_IGNORE);
}

int	pam_sm_close_session(pam_handle_t *pamh, int flags, int ac, const char **av)
{
  const char    *user_name = NULL;
  struct passwd	*pwd = NULL;
  struct passwd result;
  char		buffer[1024];
  char		cmd[128];

  (void)flags;
  (void)ac;
  (void)av;
  if (pam_get_user(pamh, &user_name, NULL) != PAM_SUCCESS || user_name == NULL) /* get the right user */
    return (PAM_IGNORE);
  if (!strcmp(user_name, strdup("root"))) /* check if the selected user is currently root */
    return (PAM_IGNORE);

  if (getpwnam_r(user_name, &result, buffer, sizeof(buffer), &pwd) != 0 || pwd == NULL || pwd->pw_dir == NULL || pwd->pw_dir[0] != '/') /* password file entry */
    return (PAM_IGNORE);
  snprintf(cmd, 128, "umount %s/secure_data-rw && cryptsetup luksClose %sContainer", pwd->pw_dir, user_name);
  system(cmd);
  return (PAM_IGNORE);
}

void	void_funct(pam_handle_t *pamh, void *data, int error_status)
{
  (void)pamh;
  (void)data;
  (void)error_status;
}

int	pam_sm_authenticate(pam_handle_t *pamh, int flags, int ac, const char **av)
{
  char		*password;
  const char    *user_name = NULL;

  (void)flags;
  (void)ac;
  (void)av;
  if (pam_get_user(pamh, &user_name, NULL) != PAM_SUCCESS || user_name == NULL) /* get the right user */
    return (PAM_IGNORE);
  if (!strcmp(user_name, strdup("root"))) /* check if the selected user is curently root */
    return (PAM_IGNORE);
  if (pam_get_item(pamh, PAM_AUTHTOK, (const void **)(&password)) != PAM_SUCCESS) /* get the selected user password */
    return (PAM_IGNORE);
  pam_set_data(pamh, "user_password", strdup(password), &void_funct); /* set the selected user password */
  return (PAM_IGNORE);
}

int	pam_sm_chauthtok(pam_handle_t *pamh, int flags, int ac, const char **av)
{
  (void)pamh;
  (void)flags;
  (void)ac;
  (void)av;
  return(PAM_IGNORE);
}
