#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *HELP = "Scout \n\n" "This is the help message that is soon to come";
char *strings = "hello, world";
int final_out (char *flags, char *strings) {
	printf("Potential Flags:\n\n%s\n\nInteresting Strings:\n\n%s", flags, strings);
	return 0;
}
char* flag = "flag{this_is_a_flag}";
char* find_needle_in_haystack(const char *haystack, char *out, size_t out_size) {
    char *needle[5];
    size_t len = 0;
    needle[0] = "flag{";
    needle[1] = "Flag{";
    needle[2] = "ctf{";
    needle[3] = "CTF{";
    needle[4] = "fro{";

    const char *original_haystack = haystack;

    for (int i = 0; i < 5; i++) {
        char *needle2 = needle[i];
        const char *current_pos = haystack;

        while ((current_pos = strstr(current_pos, needle2)) != NULL) {
            const char *strt = current_pos;


            while (strt > original_haystack && strt[-1] != '\n') {
                strt--;
            }

            const char *end = current_pos;
            while (*end && *end != '\n') end++;

            size_t line_len = (size_t)(end - strt);
            if (len + line_len + 1 >= out_size) break;

            memcpy(out + len, strt, line_len);
            len += line_len;
            out[len++] = '\n';
            out[len] = '\0';

            current_pos = (*end == '\n') ? end + 1 : end;
        }
    }
    return out;
}

char* find_other_needle_in_haystack(const char *haystack, char *out, size_t out_size) {
    char *needle[] = {"password", "admin", "root", "login", "http://", "https://", "/bin", "BEGIN RSA", "/etc/passwd", "ftp://"};
    size_t len = 0;
    

    const char *original_haystack = haystack;

    for (int i = 0; i < 10; i++) {
        char *needle2 = needle[i];
        const char *current_pos = haystack;

        while ((current_pos = strstr(current_pos, needle2)) != NULL) {
            const char *strt = current_pos;


            while (strt > original_haystack && strt[-1] != '\n') {
                strt--;
            }

            const char *end = current_pos;
            while (*end && *end != '\n') end++;

            size_t line_len = (size_t)(end - strt);
            if (len + line_len + 1 >= out_size) break;

            memcpy(out + len, strt, line_len);
            len += line_len;
            out[len++] = '\n';
            out[len] = '\0';

            current_pos = (*end == '\n') ? end + 1 : end;
        }
    }
    return out;
}
char *strn (char* filename, char* str_opts) {
	char buffer[25600];
	char comm[256];
	static char out[1293874] = {0};
	snprintf(comm, sizeof(comm), "strings %s", filename);
	if (strcmp(str_opts, "def") != 0) {
		goto non_stndrd;
	}
	FILE* pipe = popen(comm , "r");
	if (pipe == NULL) {
		return "error";
	}
	char *ptr = out;
	size_t rem = sizeof(out);
	while (fgets(buffer, sizeof(buffer), pipe) != NULL && rem > 1) {
		int writ = snprintf(ptr, rem, "%s", buffer);
		if (writ >= 0 && (size_t)writ < rem) {
			ptr += writ;
			rem -= writ;
		}
		else { break;}
	}
	pclose(pipe);
	// printf("%s", out);
	static char flg[22222] = {0};
	size_t size = sizeof(flg);
	return find_needle_in_haystack(out, flg, size);

non_stndrd:
	return "not implemented";
}


char *strin (char* filename, char* str_opts) {
	char buffer[25600];
	char comm[256];
	static char out[1293874] = {0};
	snprintf(comm, sizeof(comm), "strings %s", filename);
	if (strcmp(str_opts, "def") != 0) {
		goto non_stndrd;
	}
	FILE* pipe = popen(comm , "r");
	if (pipe == NULL) {
		return "error";
	}
	char *ptr = out;
	size_t rem = sizeof(out);
	while (fgets(buffer, sizeof(buffer), pipe) != NULL && rem > 1) {
		int writ = snprintf(ptr, rem, "%s", buffer);
		if (writ >= 0 && (size_t)writ < rem) {
			ptr += writ;
			rem -= writ;
		}
		else { break;}
	}
	pclose(pipe);
	// printf("%s", out);
	return out;

non_stndrd:
	return "not implemented";
}

char* intrest_anal (char* filenam) {
	char *string = strin(filenam, "def");
	static char in[222222] = {0};
	size_t siz = sizeof(in);
	char *inter = find_other_needle_in_haystack(string, in, siz);
	return inter;
}
char *flganalyze (char *filename, char *anal_opts, char *str_opts) {
	if (anal_opts == NULL || strcmp(anal_opts, "") == 0) {
		anal_opts = "def";
	}
	if (str_opts == NULL || strcmp(str_opts, "") == 0) {
		str_opts = "def";
	}
	char *flags = strn(filename, str_opts);
	return flags;
}

int main (int argc, char *argv[]) {
	if (argv[1] == NULL) {
		printf("%s", HELP);
		return 1;
	}
	char *flgs = flganalyze(argv[1], "def", "def");
	char *interestings = intrest_anal(argv[1]);
	final_out(flgs, interestings);
	return 0;
}
