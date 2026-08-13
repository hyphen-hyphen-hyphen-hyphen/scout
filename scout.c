#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <cjson/cJSON.h>
#define cjsGetObjItem cJSON_GetObjectItemCaseSensitive
typedef cJSON cjs;


static char *HELP = "Scout \n\n" "This is the help message that is soon to come";
int final_out (char *flags, char *strings) {
	printf("Potential Flags:\n\n%s\n\nInteresting Strings:\n\n%s", flags, strings);
	return 0;
}
char *flag_pat[20];
int flag_c;
long double lnsha(char *sha);
char *interesting_pat[20];
int interesting_c;
#define GET_JSON_ARR_GEN(name, name_pat, name_c) \
char* get_##name (cjs* arr_name) { \
	int size = cJSON_GetArraySize(arr_name); \
	for (int i = 0; i < size && i < 20; i++) { \
		cjs *item = cJSON_GetArrayItem(arr_name , i); \
		if (cJSON_IsString(item)) { \
			name_pat[i] = item->valuestring; \
 			name_c++; \
		} \
	} \
}
GET_JSON_ARR_GEN(flag, flag_pat, flag_c);
GET_JSON_ARR_GEN(interesting, interesting_pat, interesting_c);
char *strings_out;
void read_config (void) {
	FILE *conf = fopen("conf.json", "r");
	conf ?: exit(EXIT_FAILURE);
	char buf[1024];
	int len = fread(buf, 1, sizeof(buf), conf);
	fclose(conf);
	buf[len] = '\0';
	cjs *conf_json = cJSON_Parse(buf);
	cjs *flag = cjsGetObjItem(conf_json, "flag");
	cjs *interesting = cjsGetObjItem(conf_json, "interesting");
	get_flag(flag);
	get_interesting(interesting);	
}
char* find_needle_in_haystack(const char *haystack, char *out, size_t out_size) {
    size_t len = 0;
    haystack ?: exit(EXIT_FAILURE);

    const char *original_haystack = haystack;

    for (int i = 0; i < 19&&i<flag_c; i++) {
        char *needle2 = flag_pat[i];
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
char* sha256 (char* filnm) {
	char cmd[512];
	static char hash[57];
	snprintf(cmd, sizeof(cmd), "sha224sum \"%s\"", filnm);
	FILE *pip = popen(cmd, "r");
	fgets(hash, sizeof(hash), pip);
	pclose(pip);
	hash[56] = '\0';
	return hash;
}
char* find_other_needle_in_haystack(const char *haystack, char *out, size_t out_size) {
    size_t len = 0;
    haystack ?: exit(EXIT_FAILURE);
    const char *original_haystack = haystack;
    for (int i = 0; i < 19&&i<interesting_c; i++) {
        char *needle2 = interesting_pat[i];
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
long int factorial (int numb) {
	int oth_numb = 1;
	for (int j = 1; j < numb; j++) {
		oth_numb += oth_numb * j;
	}
	oth_numb += oth_numb*numb;
	return oth_numb;
}
long double compute_e() {
	long double e = 2.0L;
	
	for (int i = 1; i < 25; i++) {
		e += 1.0L/ factorial(i);
	}
	printf("%Lf", e);
	return e;
}
char *strinin(char* filename){
	char buffer[25600];
	char comm[256];
	static char out[1293874] = {0};
	snprintf(comm, sizeof(comm), "strings %s", filename);
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
	strings_out = out;
	pclose(pipe);
}
long double lnsha (char*sha) {
	
}
char *strn (char* filename, char* str_opts) {
	if (strcmp(str_opts, "def") != 0) {
		goto non_stndrd;
	}
	// printf("%s", out);
	static char flg[22222] = {0};
	size_t size = sizeof(flg);
	return find_needle_in_haystack(strings_out, flg, size);

non_stndrd:
	return "not implemented";
}


char *strin (char* filename, char* str_opts) {
	if (strcmp(str_opts, "def") != 0) {
		goto non_stndrd;
	}
	// printf("%s", out);
	return strings_out;

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
	read_config();
	strinin(argv[1]);
	char *flgs = flganalyze(argv[1], "def", "def");
	compute_e();
	char *interestings = intrest_anal(argv[1]);
	final_out(flgs, interestings);
	printf("%s", sha256(argv[1]));
	return 0;
}
