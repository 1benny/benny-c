// Sun Jun 07 03:37:06 2026
// 1benny
//
// rip.c
//
//
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <SoundCloud URL>\n", argv[0]);
        return 1;
    }

    const char *url = argv[1];

    // Build command string
    char command[2048];

    snprintf(command, sizeof(command),
        "yt-dlp -x --audio-format mp3 --audio-quality 0 "
        "--embed-metadata --embed-thumbnail "
        "-o \"%%(artist)s - %%(title)s.%%(ext)s\" "
        "\"%s\"",
        url
    );

    printf("Running command:\n%s\n\n", command);

    int result = system(command);

    if (result != 0) {
        fprintf(stderr, "Error: yt-dlp command failed.\n");
        return 1;
    }

    printf("Download completed successfully.\n");
    return 0;
}