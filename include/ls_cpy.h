#ifndef LS_CPY_H
#define LS_CPY_H

#include <stdio.h>
#include <pwd.h>
#include <grp.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

void print_f_permissions(mode_t file_mode_t);
void print_f_timestamp(time_t time_stamp);
void print_f_owner(uid_t owner_uid);
void print_f_size(unsigned int f_size);
int read_directory_entries(const char* dir_path);

#endif