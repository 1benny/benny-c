// Sun Jul 16 03:02:11 2023
// bdxves
//
// understanding.c
//
//
#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>


int main(void)
{
    CURL *curl;
    CURLcode res;
    curl = curl_easy_init();

    // Handle curl failure
    if (!curl) {
        fprintf(stderr, "Init failed.\n");
        return EXIT_FAILURE;
    }

    // Setting options
    curl_easy_setopt(curl, CURLOPT_URL, "http://127.0.0.1:5500/bdives-c/");

    // Perform out action
    res = curl_easy_perform(curl);
    if (res != CURLE_OK) {
        fprintf(stderr, "Download problem: %s.\n", curl_easy_strerror(res));
    }

    // Cleanup
    curl_easy_cleanup(curl);
	
	return EXIT_SUCCESS;
}