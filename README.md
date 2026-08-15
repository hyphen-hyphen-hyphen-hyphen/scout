# Scout

Scout is a simple CTF analysis program that extracts potential flags and interesting strigs from a file. It also does automatic shannon entropy calculations on strings to identify low and high entropy strings. 

## Features

- Advanced pattern matching with patterns from a json config file
- Extracts potential flags and interesting strings from file, with line context
- Calculates shannon entropy of strings and extracts both high and low entropy strings
  High entropy strings: potential passwords, binary blobs or encrypted data
  Low entropy strings: English(or other languadge) text, buffer overflow padding or patterns
- Custom implemented math and entropy library for efficiency and to reduce dependency bloat
- Automatic malware analysis report writing with `--report` flag
- Helpful help message with `--help` flags or no arguments
- Cutting edge, top of the line features, including `lnsha`, our flagship feature, only one of its kind
- Shell integration
- Efficient memmory usage reduction
- dynamic code
- gcc only

# WARNING

***NEVER*** **under any circumstances use the `--help` flag, it is very unstable and unpredictable due to scout:s shell integration.**
***ALWAYS*** **run scout without command line arguments (like so: `scout`) if you want to see the help message**

# Usage

Run `scout` followed by a filename, and then followed by potential flags, for example `--report`
example:
`scout chall --report`

## Configuration

Scout is configured via a json file by the name of config.json. This file **must** exist in the working directory, and be populated correctly, otherwise scout *will* segfault.

### Configuration guide

The config file should contain two(2) json arrays by the names of flag and interesting.
These arrays should contain strings. The file should be no more than 1024 bytes long, or there will be a buffer overflow in the `read_config` function.
See example configuration for more info and json syntax.

### example configuration

```
{
    "flag": [
        "flag{",
        "FLAG{",
        "ctf{",
        "CTF{",
        "secret{",
        "key{"
    ],
    "interesting": [
        "password",
        "admin",
        "root",
        "login",
        "http://",
        "https://",
        "ftp://",
        "/bin",
        "BEGIN RSA",
        "/etc/passwd"
    ]
}
```

## Compilation (im sorry)

Run in the projects root directory:
`gcc -Isrc -lcjson src/scout.c src/mathyy/mathyy.c src/entropy/entropy.c -o scout`

## gcc *only*

Scout uses GNU extensions that only work with gcc. Other compilers like clang might compile it but we dont support it, reccomend it, or guarantee anything.

## dependencies

Scout depends on the following:
- C standard library (glibc or musl)
- gcc (for compilation, clang and others dont work)
- cJSON library for config file reading
- strings command (usually installed by default on most distros)
- sha224sum command (usually installed by default on most distros)
- Linux (Does **NOT** work on windows(probably works on other unix like OS:s, like the BSD:s or Haiku))

## Known issues

- For a string with shannon entropy 0, the printed entropy will be -0, this isnt some special kind of entropy, its just 0.
- `ln` function retuns constant approximately equal to 10.48 for larger values, this causes the `lnsha` function to usually return the same constant. We call this the scout constant.
- Running with `--help` flag is highly unstable and not supported
- Multiple memmory leaks, don't fix these, they are required.

# Security policy

see `SECURITY.md`

# Licence

This project is licensed under the GNU GPLv3 licence
