#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "dsa-verify.h"

// This is a simple tool that allows anyone to easily verify DSA signatures from
// the command line

char* read_file(const char* path, size_t* len)
{
    FILE* f = fopen(path, "rb");
    fseek(f, 0, SEEK_END);
    size_t fsize = ftell(f);
    fseek(f, 0, SEEK_SET);

    char* contents = malloc(fsize + 1);
    fread(contents, 1, fsize, f);
    fclose(f);

    if (len != NULL)
        *len = fsize;

    contents[fsize] = '\0';
    return contents;
}

int verify_result(const char* filename, const char* sig_file, const char* pub_key_file)
{

    size_t file_len;
    char* file_contents = read_file(filename, &file_len);
    char* public_key = read_file(pub_key_file, NULL);
    char* signature = read_file(sig_file, NULL);

    int ret = dsa_verify_blob((const unsigned char*)file_contents, file_len, public_key, signature);


    free(file_contents);
    free(public_key);
    free(signature);

    if (ret == DSA_VERIFICATION_OK) return 0;
    else return -1;
}

