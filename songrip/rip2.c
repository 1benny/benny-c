#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/stat.h>
#include <dirent.h>

#ifdef _WIN32
#define PATH_SEP "\\"
#else
#define PATH_SEP "/"
#endif

void clean_mp3_name(const char *oldname, char *newname, size_t size) {
    strncpy(newname, oldname, size);
    newname[size - 1] = '\0';

    char *ext = strrchr(newname, '.');
    if (!ext || strcmp(ext, ".mp3") != 0) {
        return;
    }

    char *end = ext;

    while (end > newname) {
        char *close = end - 1;

        while (close > newname && *(close - 1) == ' ') {
            close--;
        }

        if (close <= newname || *(close - 1) != ']') {
            break;
        }

        char *open = close - 1;

        while (open > newname && *open != '[') {
            open--;
        }

        if (*open != '[') {
            break;
        }

        while (open > newname && *(open - 1) == ' ') {
            open--;
        }

        end = open;
    }

    strcpy(end, ext);
}

void rename_new_mp3s(time_t start_time) {
    DIR *dir = opendir(".");

    if (!dir) {
        perror("opendir failed");
        return;
    }

    struct dirent *entry;

    while ((entry = readdir(dir)) != NULL) {
        const char *name = entry->d_name;

        char *ext = strrchr(name, '.');
        if (!ext || strcmp(ext, ".mp3") != 0) {
            continue;
        }

        struct stat st;
        if (stat(name, &st) != 0) {
            continue;
        }

        if (st.st_mtime < start_time) {
            continue;
        }

        char cleaned[1024];
        clean_mp3_name(name, cleaned, sizeof(cleaned));

        if (strcmp(name, cleaned) != 0) {
            printf("Renaming:\n  %s\n  -> %s\n", name, cleaned);

            if (rename(name, cleaned) != 0) {
                perror("rename failed");
            }
        }
    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <SoundCloud URL>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];

    time_t start_time = time(NULL);

    char command[4096];

    snprintf(command, sizeof(command),
        "yt-dlp -x --audio-format mp3 --audio-quality 0 "
        "--embed-metadata --embed-thumbnail "
        "-o \"%%(title)s.%%(ext)s\" "
        "\"%s\"",
        url
    );

    printf("Running command:\n%s\n\n", command);

    int result = system(command);

    if (result != 0) {
        fprintf(stderr, "Error: yt-dlp command failed.\n");
        return 1;
    }

    rename_new_mp3s(start_time);

    printf("Download completed successfully.\n");
    return 0;
}