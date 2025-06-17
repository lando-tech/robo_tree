#ifndef LS_CPY_H
#define LS_CPY_H

#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdbool.h>

void format_permissons(mode_t file_mode_t);
int read_directory_entries(const char* dir_path);

#endif