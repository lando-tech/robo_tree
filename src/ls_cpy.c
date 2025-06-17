#include "ls_cpy.h"

void print_f_permissions(mode_t file_mode_t) {
  /*
   * S_IRUSR: User read permission
   * S_IWUSR: User write permission
   * S_IXUSR: User execute permission
   * S_IRGRP: Group read permission
   * S_IWGRP: Group write permission
   * S_IXGRP: Group execute permission
   * S_IROTH: Others read permission
   * S_IWOTH: Others write permission
   * S_IXOTH: Others execute permission
   */

  printf((S_ISDIR(file_mode_t)) ? "d" : "-");
  printf((file_mode_t & S_IRUSR) ? "r" : "-");
  printf((file_mode_t & S_IWUSR) ? "w" : "-");
  printf((file_mode_t & S_IXUSR) ? "x" : "-");
  printf((file_mode_t & S_IRGRP) ? "r" : "-");
  printf((file_mode_t & S_IWGRP) ? "w" : "-");
  printf((file_mode_t & S_IXGRP) ? "x" : "-");
  printf((file_mode_t & S_IROTH) ? "r" : "-");
  printf((file_mode_t & S_IWOTH) ? "w" : "-");
  printf((file_mode_t & S_IXOTH) ? "x" : "-");
}

void print_f_owner(uid_t owner_uid) {
  struct passwd *owner_info = getpwuid(owner_uid);
  if (owner_info != NULL) {
    printf("  %s  ", owner_info->pw_name);
  }
}

void print_f_size(unsigned int f_size) {
  if (f_size == 1024) {
    f_size = 1;
  } else if (f_size > 1024) {
    f_size = f_size / 1024;
  } else {
    f_size = f_size;
  }
  printf("  %6u", f_size);
}

int read_directory_entries(const char *dir_path) {

  chdir(dir_path);

  DIR *dir;
  struct dirent *entry;
  struct stat file_stat;
  int r;
  mode_t file_permissions;

  dir = opendir(dir_path);

  if (dir != NULL) {
    while ((entry = readdir(dir)) != NULL) {
      r = stat(entry->d_name, &file_stat);
      if (r == -1) {
        perror("stat");
        return -1;
      }

      file_permissions = file_stat.st_mode;
      print_f_permissions(file_permissions);
      print_f_size(file_stat.st_size);
      printf("  %-1s", entry->d_name);
      printf("\n");
    }
  } else {
    perror("opendir");
    return -1;
  }

  closedir(dir);
  return 0;
}