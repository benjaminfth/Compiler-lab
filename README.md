# Compiler Lab Programs

A small collection of C programs for basic compiler construction labs:
- la.c — lexical analyzer for C-like input (reads input.txt)
- rdp.c — recursive descent parser for arithmetic expressions
- srp.c — shift-reduce parsing demo (a, b, c as identifiers)
- fnf.c — FIRST and FOLLOW set calculator

## Build

Windows (MSYS2 UCRT64):
```bash
cd "/mnt/d/CODING/random/compiler lab"   # from WSL; or use MSYS shell with /d/...
gcc -std=c11 -Wall -Wextra -O2 la.c  -o la
gcc -std=c11 -Wall -Wextra -O2 rdp.c -o rdp
gcc -std=c11 -Wall -Wextra -O2 srp.c -o srp
gcc -std=c11 -Wall -Wextra -O2 fnf.c -o fnf
```

WSL/Linux:
```bash
cd "/mnt/d/CODING/random/compiler lab"
gcc -std=c11 -Wall -Wextra -O2 la.c  -o la
# ...same for the others as above
```

Notes:
- Do not link with -mwindows; these are console apps. If you see “undefined reference to WinMain”, rebuild without GUI flags.
- Quote paths that contain spaces.

## Run
```bash
./la     # reads tokens from input.txt in the same folder
./rdp    # prompts for an arithmetic expression
./srp    # prompts for an input like a+b*c/a
./fnf    # prompts for number of productions, then productions, then a variable
```

## la.c (Lexical Analyzer)
- Input file: input.txt (C-like code or snippets).
- Classifies numbers, identifiers, C keywords, operators (+ - * / % & | = < >), and other symbols.
- Whitespace handling: spaces/tabs/CR are skipped; line count increases on newline (\n).

Example input.txt:
```c
#include <stdio.h>
int main(){ int x=4; float y=30; if(x>y){ printf("Sum=%d", x+y); } }
```

## rdp.c (Recursive Descent Parser)
Parses expressions over grammar:
- E → T E'
- E' → + T E' | ε
- T → F T'
- T' → * F T' | ε
- F → id | ( E )

In code, id is a single alphabetic letter (A–Z or a–z). Examples:
- a+a*a
- (a+b)*c

## srp.c (Shift-Reduce Parser Demo)
- Identifiers: single letters a, b, or c (each reduces to E).
- Operators: +, *, /.
- Prints a table: STACK | INPUT | ACTION (Shift/Reduce steps).

Example: a+b*c/a

## fnf.c (FIRST/FOLLOW)
- Enter number of productions n.
- Enter productions using ‘=’ and ‘$’ for epsilon, one per line, no spaces. Example:
```
E=E+T
E=T
T=T*F
T=F
F=(E)
F=a
```
- Then enter a single nonterminal (e.g., E) to compute First/Follow.
- Enter 1 to continue, 0 to stop.

## Troubleshooting
- Paths with spaces: use quotes.
- CRLF files: la.c skips '\r' to avoid blank lines in output.
- If an input is rejected in rdp/srp, ensure it matches the supported grammar and tokens.
