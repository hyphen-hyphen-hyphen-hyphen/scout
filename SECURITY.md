# Security policy

## Reporting

If you find any vulnerabilities that arent documented here or in any other documentation you can report it, i guess. Information on how to do so will be at the bottom.

## Known vulnerabilities

### Command injection in `sha256`
- **Description:** user input from the *filename* argument is passed directly to a shell command without sanitization or escaping.
- **Impact:** if the user inputs a filename like `\&\& rm -rf \*` it would run the command `rm -rf \*`, and that would be bad
- **status:** no forseable fix, i call this "shell integration".

### Command injection in `strinin`
same as in `sha256`, see that

### General buffer overflow issues
Dont even bother with these, also a feature called "memmory usage reduction"

### UB in `lnsha`
a pointer is cast to `long long` and then later `long double`. This is UB, but i call this dynamic code, youre never really sure what will happen

### memmory leaks in `read_config` and other functions
If documented with comments, i already know about it, if not, i also probably know about it

## Security best practices

- Dont run as root
- Dont run on files with malicious filenames
- Dont let other people run it on your computer
- Use strings instead

## Reporting
- PR with a fix (please, i dont have time or energy to fix it myself)
- Add issue on GitHub
