#ifndef VERIFY_H_
#define VERIFY_H_

extern "C" {
int verify_result(const char* filename, const char* sig_file, const char* pub_key_file);

}

#endif
