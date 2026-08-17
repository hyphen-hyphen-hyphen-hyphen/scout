# Security policy

## Reporting

If you find any vulnerabilities that arent documented here or in any other documentation you can report it, i guess. Information on how to do so will be at the bottom.

## Known vulnerabilities

### Command injection in `sha256` and `strinin`

While i have tried  to fix this, there is still some risk that this is possible, howeaver, i could not give you an example command, as i have not figured out a way.
Shouldn't be used in secure enviroments.

### General buffer overflow issues
Dont even bother with these, also a feature called "memmory usage reduction"

### UB in `lnsha`
a pointer is cast to `long long` and then later `long double`. This is UB, but i call this dynamic code, youre never really sure what will happen


## Security best practices

- Dont run as root
- Dont run on files with malicious filenames
- Dont let other people run it on your computer
- Use strings instead

## Reporting
- PR with a fix (please, i dont have time or energy to fix it myself)
- Add issue on GitHub
