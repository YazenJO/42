# Libft in 5 Days: A Study and Implementation Plan

Two things in your subject (v19.3) change how you should plan compared with older guides:

1. **Linked lists are mandatory (Part 3), not bonus.** There is no separate bonus part in this version, so all 43 functions go in the main `all` rule.
2. **`ft_lstsize` returns `unsigned int`** in this version. Older libft guides and testers use `int`. Match your subject exactly.

The subject's AI rules also say you should describe how AI was used in your README's "Resources" section. Using this plan for scheduling counts, so note it there.

---

## 5-Day Overview

| Day | Focus | Functions/Topics | Estimated Time | Deliverable |
|---|---|---|---|---|
| 1 | Setup + first functions | Makefile, `libft.h`, Norm, test harness; 7 char functions; `strlen`, `strchr`, `strrchr`, `strncmp` | 6–7 h | Compiling `libft.a` with 11 Norm-clean functions |
| 2 | Memory + bounded strings | `memset`, `bzero`, `memcpy`, `memmove`⚠️, `memchr`, `memcmp`, `strlcpy`, `strlcat`⚠️, `strnstr`⚠️, `atoi`⚠️ | 7–8 h | Part 1 done except `calloc`/`strdup` |
| 3 | Heap allocation + output | `calloc`⚠️, `strdup`, `substr`⚠️, `strjoin`, `strtrim`⚠️, `itoa`⚠️, 4 `_fd` functions | 7–8 h | Part 1 complete, most of Part 2 |
| 4 | The hardest parts | `strmapi`, `striteri`, `split`⚠️⚠️, 9 linked-list functions (`lstclear`⚠️, `lstmap`⚠️⚠️) | 8 h | All 43 functions written |
| 5 | Buffer + verification | Fix leftovers, testers, Valgrind, Norminette, README, rewrite-from-memory drills, mock evaluation | 7–8 h | Submission-ready repo |

⚠️ = tricky, extra time allocated. ⚠️⚠️ = the hardest in the project.

---

## Day 1: Setup, Characters, and Basic Strings

**Main objective:** Get the whole toolchain working (Makefile → `libft.a` → test program) and write the simplest functions so you learn the workflow on easy problems.

### Topics to learn

- How a static library works: `.c` → `.o` (compile) → `.a` (archive with `ar rcs`) → linked into a program
- Makefile basics: targets, prerequisites, variables, pattern rules (`%.o: %.c`), `.PHONY`, and why "no relinking" means `make` twice prints "Nothing to be done"
- Header files: include guards, prototypes, why the struct goes in `libft.h`
- The Norm: 25 lines per function, 5 functions per file, 4 parameters max, 5 variables max, 80 columns, no `for`, declarations at the top of a function, the 42 header comment. Read the official Norm PDF on the intranet.
- ASCII table: know `'0'`=48, `'A'`=65, `'a'`=97, printable range 32–126
- Why `is*` functions take an `int`, not a `char`
- Pointer arithmetic on `char *` and how `const` works on pointers

### Before coding, understand

- Why `char` can be signed, and why `strncmp` compares bytes as `unsigned char`
- What a pointer to the null terminator is, and why `strchr(s, '\0')` is valid
- How to read a man page: prototype, DESCRIPTION, RETURN VALUE

### Session 1: Setup (1.5–2 h)

1. Create the repo with everything at the root.
2. Write `libft.h` with include guards, the `t_list` struct, and needed includes (`<stddef.h>` / `<stdlib.h>` for `size_t`, `<unistd.h>` for `write`).
3. Write the Makefile with `NAME`, `all`, `clean`, `fclean`, `re`, using `cc -Wall -Wextra -Werror` and `ar rcs`.
4. Create a separate test folder outside the repo (or gitignored) for your `main.c` files. The subject forbids submitting unused files.
5. Run `norminette` on an empty function file to confirm it works.

### Session 2: Character functions (1–1.5 h)

The subject requires these to return exactly **1 or 0**.

| Prototype | Description |
|---|---|
| `int ft_isalpha(int c);` | 1 if `c` is a letter (A–Z, a–z) |
| `int ft_isdigit(int c);` | 1 if `c` is '0'–'9' |
| `int ft_isalnum(int c);` | 1 if letter or digit |
| `int ft_isascii(int c);` | 1 if `c` is in 0–127 |
| `int ft_isprint(int c);` | 1 if `c` is printable (32–126) |
| `int ft_toupper(int c);` | Converts a–z to uppercase; otherwise returns `c` unchanged |
| `int ft_tolower(int c);` | Converts A–Z to lowercase; otherwise returns `c` unchanged |

Suggested order: `isdigit` → `isalpha` → `isalnum` (reuse the first two) → `isascii` → `isprint` → `toupper` → `tolower`.

### Session 3: Basic strings (2–2.5 h)

| Prototype | Description |
|---|---|
| `size_t ft_strlen(const char *s);` | Counts characters before `'\0'` |
| `char *ft_strchr(const char *s, int c);` | Pointer to the first occurrence of `(char)c`, or NULL |
| `char *ft_strrchr(const char *s, int c);` | Pointer to the last occurrence of `(char)c`, or NULL |
| `int ft_strncmp(const char *s1, const char *s2, size_t n);` | Compares at most `n` bytes; returns <0, 0, or >0 |

Order: `strlen` → `strchr` → `strrchr` → `strncmp`.

**Edge cases to test**

- `strchr`/`strrchr`: search for `'\0'` (must return a pointer to the terminator, not NULL); `c` not found; `c = 'a' + 256` (the man page says `c` is converted to `char`); empty string
- `strncmp`: `n = 0` → 0; strings differing after `n`; one string shorter; bytes above 127 (e.g. `"\200"` vs `"\0"`) to confirm unsigned comparison
- Character functions: `-1` (EOF), `0`, `127`, `128`, `255`, `300`

### Session 4: Testing and Norm (1 h)

- Compare each `ft_` function against the real one in a loop over `-1` to `300` for the char functions.
- Run `make`, then `make` again (should do nothing), then `make re`, then `make fclean`.
- Run `norminette` and fix everything today so errors don't pile up.

### Common mistakes

- Returning the libc value (libc `isalpha` can return 1024, not 1)
- The Makefile relinking every time because `all` isn't wired to the actual `$(NAME)` file
- `strrchr` forgetting to check the terminator position
- `strncmp` comparing as signed `char`
- Casting away `const` without thinking. You'll need to for `strchr`'s return type, so understand why.

### Checkpoint (answer without notes)

1. What does `ar rcs` do, and what does each letter mean?
2. Why does `ft_strchr("hello", '\0')` return a non-NULL pointer?
3. What does `ft_strncmp("abc", "abd", 2)` return, and why?
4. Why does running `make` twice without changes do nothing?

**Estimated time:** 6–7 hours

---

## Day 2: Memory Functions and Bounded Strings

**Main objective:** Understand raw memory (bytes, not strings) and the size-bounded string functions. Today has four tricky functions, so give each one full attention.

### Topics to learn

- `void *`: why you can't dereference or do arithmetic on it directly, and why you cast to `unsigned char *`
- The difference between memory functions (they ignore `'\0'` and use `n` bytes) and string functions (they stop at `'\0'`)
- Overlapping memory regions, and why `memcpy` and `memmove` both exist
- `size_t` and unsigned underflow: `0 - 1` becomes a huge number
- BSD vs glibc: `strlcpy`/`strlcat` need `<bsd/string.h>` and `-lbsd` on Linux for testing

### Before coding, understand

- Draw memory overlap on paper: when `dst` is inside `src`'s range, copying forward corrupts data. Figure out which direction to copy in each case before you code `memmove`.
- Read the `strlcpy`/`strlcat` man pages twice. Their return value is the length they *tried* to create, so the caller can detect truncation.

### Session 1: Memory functions (2.5 h)

| Prototype | Description |
|---|---|
| `void *ft_memset(void *s, int c, size_t n);` | Fills `n` bytes of `s` with `(unsigned char)c`; returns `s` |
| `void ft_bzero(void *s, size_t n);` | Sets `n` bytes to zero (reuse `memset`) |
| `void *ft_memcpy(void *dest, const void *src, size_t n);` | Copies `n` bytes; regions must not overlap |
| `void *ft_memmove(void *dest, const void *src, size_t n);` ⚠️ | Copies `n` bytes safely even if regions overlap |
| `void *ft_memchr(const void *s, int c, size_t n);` | Finds the first byte equal to `(unsigned char)c` within `n` bytes |
| `int ft_memcmp(const void *s1, const void *s2, size_t n);` | Compares `n` bytes as `unsigned char` |

Order: `memset` → `bzero` → `memcpy` → `memmove` → `memchr` → `memcmp`.

**Edge cases**

- `memset` on an `int` array with value 1: explain why the ints aren't 1 afterwards
- `memmove` with `dst > src` (overlap to the right), `dst < src`, `dst == src`, `n = 0`
- `memchr`/`memcmp`: data containing `'\0'` in the middle (they must *not* stop there), and bytes above 127
- NULL pointers: libc crashes on `memcpy(NULL, "a", 1)`. Decide on and be able to justify your policy on NULL handling. Some testers check `memcpy(NULL, NULL, n)`. Know what your code does and why.

### Session 2: Bounded string copy/concat (2–2.5 h) ⚠️

| Prototype | Description |
|---|---|
| `size_t ft_strlcpy(char *dst, const char *src, size_t size);` | Copies up to `size - 1` chars and null-terminates if `size > 0`; returns `strlen(src)` |
| `size_t ft_strlcat(char *dst, const char *src, size_t size);` ⚠️ | Appends `src` to `dst` within a total buffer of `size`; returns the length it tried to create |

`strlcat` is the most commonly failed Part 1 function. Plan it on paper first: what's the return value when `size` ≤ the current length of `dst`?

**Edge cases**

- `strlcpy`: `size = 0` (write nothing, still return `strlen(src)`), `size = 1`, `size` exactly `strlen(src)`, `size` larger, empty `src`
- `strlcat`: `size = 0`; `size` < `strlen(dst)`; `size == strlen(dst)`; `size` just enough; `dst` not null-terminated within `size`. Compare every case against the BSD version with `-lbsd`.

### Session 3: Search and parse (2 h) ⚠️

| Prototype | Description |
|---|---|
| `char *ft_strnstr(const char *big, const char *little, size_t len);` ⚠️ | Finds `little` inside the first `len` chars of `big` |
| `int ft_atoi(const char *nptr);` ⚠️ | Converts the initial part of a string to `int` |

**Edge cases**

- `strnstr`: empty `little` (returns `big`); `little` longer than `len`; a match that starts inside `len` but ends past it (must fail); `len = 0`; a partial match followed by a real match (`"aaab"` / `"aab"`)
- `atoi`: leading whitespace (all six: space, `\t \n \v \f \r`); `"+42"`, `"-42"`, `"+-42"` → 0, `"--42"` → 0, `"  -42abc"` → -42; `"-2147483648"`; letters first → 0. Overflow is undefined behavior in libc, so know what yours does but don't obsess over it.

### Session 4: Test and Norm (1 h)

Compare everything against libc/libbsd. Run Norminette.

### Common mistakes

- Doing arithmetic on `void *` directly
- `memmove` checking the wrong direction, or using `memcpy` for both directions
- Unsigned underflow in loops like `while (i < size - 1)` when `size` is 0 ⚠️
- `strlcat` return value wrong when truncating
- `atoi` accepting multiple signs, or skipping whitespace after the sign

### Checkpoint

1. Draw a case where `memcpy` corrupts data but `memmove` doesn't.
2. Why does `strlcpy` return `strlen(src)` instead of the number of chars copied?
3. What happens with `size - 1` when `size` is `0` and the type is `size_t`?
4. Why cast to `unsigned char` in `memcmp`?

**Estimated time:** 7–8 hours

---

## Day 3: Heap Allocation, New Strings, and Output

**Main objective:** Start using `malloc` responsibly. Every function today either allocates, and must return NULL on failure without leaking, or writes to a file descriptor.

### Topics to learn

- `malloc` / `free`, heap vs stack, why you can't return a local array
- Always allocating `+1` for `'\0'`
- Integer overflow in size calculations (`nmemb * size`)
- `malloc(0)` is implementation-defined; your `calloc` must satisfy the subject's rule regardless
- File descriptors: 0, 1, 2, and what `write(fd, buf, n)` does
- Recursion, useful for `putnbr_fd`, and the `INT_MIN` problem (why `-(-2147483648)` doesn't fit in an `int`)

### Before coding, understand

- For each function, the output length must be known *before* `malloc`. Write the length formula on paper first.
- Decide your NULL-input policy for Part 2 (e.g. `ft_strjoin(NULL, "a")`) and apply it consistently. Be ready to justify it in evaluation.

### Session 1: Allocation basics (1.5–2 h)

| Prototype | Description |
|---|---|
| `void *ft_calloc(size_t nmemb, size_t size);` ⚠️ | Allocates `nmemb * size` zeroed bytes |
| `char *ft_strdup(const char *s);` | Returns a malloc'd copy of `s` |

**`calloc` edge cases**

- `nmemb` or `size` = 0: the subject requires a unique pointer that can be passed to `free()`. Think about how to guarantee that given `malloc(0)` varies by system.
- Overflow: `ft_calloc(SIZE_MAX, 2)` must return NULL, not a tiny buffer. Work out how to detect that the multiplication overflows *without* overflowing.
- Confirm the memory is actually zeroed.

### Session 2: String builders (3 h) ⚠️

| Prototype | Description |
|---|---|
| `char *ft_substr(char const *s, unsigned int start, size_t len);` ⚠️ | New string from `s[start]`, at most `len` chars |
| `char *ft_strjoin(char const *s1, char const *s2);` | New string `s1 + s2` |
| `char *ft_strtrim(char const *s1, char const *set);` ⚠️ | Copy of `s1` with `set` chars removed from both ends |
| `char *ft_itoa(int n);` ⚠️ | Integer to malloc'd decimal string |

Order: `substr` → `strjoin` → `strtrim` (can reuse `substr` + `strchr`) → `itoa`.

**Edge cases**

- `substr`: `start` ≥ `strlen(s)` → return an empty string (not NULL); `len` larger than what remains (allocate only what's needed, not `len` bytes, or `ft_substr("hi", 0, SIZE_MAX)` breaks); `len = 0`
- `strtrim`: all chars in `set` → empty string; empty `set`; empty `s1`; set chars in the middle must stay
- `itoa`: `0` (easy to return an empty string by accident), `-1`, `INT_MAX`, `INT_MIN` ⚠️, powers of 10

### Session 3: File-descriptor output (1.5 h)

| Prototype | Description |
|---|---|
| `void ft_putchar_fd(char c, int fd);` | Writes one char to `fd` |
| `void ft_putstr_fd(char *s, int fd);` | Writes a string to `fd` |
| `void ft_putendl_fd(char *s, int fd);` | Writes a string followed by `'\n'` |
| `void ft_putnbr_fd(int n, int fd);` ⚠️ | Writes an integer in decimal (no malloc) |

**Edge cases:** `INT_MIN` in `putnbr_fd`; `s = NULL` in `putstr_fd` (decide on a policy: crash or do nothing); test `fd = 2` with `./a.out 2>/dev/null` to confirm the output goes to stderr.

### Session 4: Leak checking and Norm (1 h)

- Run your tests under `valgrind --leak-check=full` (Linux) or compile with `-fsanitize=address -g`.
- Free every result in your test mains, otherwise you'll get false positives.

### Common mistakes

- Forgetting `+1` for `'\0'`, which leads to off-by-one heap overflows that only Valgrind catches
- `substr` returning NULL for `start > len` instead of `""`
- `itoa` negating `INT_MIN` in an `int`
- `strtrim` reading before the start of the string when trimming the end
- `calloc` using `nmemb * size` without an overflow check

### Checkpoint

1. Why can't `ft_strdup` just return a local `char buf[100]`?
2. What does `ft_substr("hello", 10, 3)` return, and why not NULL?
3. How does your `putnbr_fd` handle `-2147483648`?
4. How did you detect overflow in `calloc`?

**Estimated time:** 7–8 hours

---

## Day 4: `ft_split`, Function Pointers, and Linked Lists

**Main objective:** Tackle the two hardest functions (`split` and `lstmap`) while you're fresh, and learn function pointers and structs.

### Topics to learn

- `char **`: an array of pointers to strings
- Freeing partially built structures on failure (the core difficulty of `split` and `lstmap`)
- Function pointers: reading `char (*f)(unsigned int, char)` and calling `f`
- Structs, `->`, self-referential structs
- Pointer to pointer (`t_list **lst`): why you need it to modify the caller's head pointer
- The difference between freeing a node and freeing its content

### Before coding, understand

- For `split`, plan on paper in three steps: (1) count words, (2) allocate the array, (3) extract each word, and if any allocation fails, free everything already allocated. Use `static` helpers, since the Norm's 25-line limit makes this necessary.
- Draw box-and-arrow diagrams for every list function before writing it.

### Session 1: Iterators (45 min)

| Prototype | Description |
|---|---|
| `char *ft_strmapi(char const *s, char (*f)(unsigned int, char));` | New string where each char is `f(index, char)` |
| `void ft_striteri(char *s, void (*f)(unsigned int, char*));` | Calls `f(index, &char)` on each char in place |

Test with your own small functions (e.g. "uppercase on even indexes").

### Session 2: `ft_split` (2.5–3 h) ⚠️⚠️

| Prototype | Description |
|---|---|
| `char **ft_split(char const *s, char c);` | NULL-terminated array of the words in `s` separated by `c` |

This function is flagged as the hardest in Part 2. The allocation-failure cleanup is what evaluators check most.

**Edge cases**

- `"  hello  world  "` with `' '` → `["hello", "world", NULL]`
- Consecutive, leading, and trailing delimiters
- Empty string `""` → `[NULL]` (an array containing only NULL, not NULL itself)
- String made only of delimiters → `[NULL]`
- `c = '\0'` → the whole string as one word
- No delimiter present → one word
- **Simulated malloc failure:** temporarily make the 3rd allocation fail in a test build and confirm with Valgrind that nothing leaks. Remove the hack afterwards.

### Session 3: Linked lists, basics (1.5–2 h)

| Prototype | Description |
|---|---|
| `t_list *ft_lstnew(void *content);` | New node with `content`, `next = NULL` |
| `void ft_lstadd_front(t_list **lst, t_list *new);` | Inserts `new` at the head |
| `unsigned int ft_lstsize(t_list *lst);` | Counts nodes (note the `unsigned int` return in v19.3) |
| `t_list *ft_lstlast(t_list *lst);` | Returns the last node |
| `void ft_lstadd_back(t_list **lst, t_list *new);` | Appends `new` at the end |

**Edge cases:** empty list (`*lst == NULL`) for both add functions (`add_back` on an empty list must update the head); `lstlast(NULL)`; `lstsize(NULL)` → 0; `lstnew(NULL)` is valid content.

### Session 4: Linked lists, memory and mapping (2–2.5 h) ⚠️

| Prototype | Description |
|---|---|
| `void ft_lstdelone(t_list *lst, void (*del)(void *));` | Frees one node's content via `del`, then the node; does not touch `next` |
| `void ft_lstclear(t_list **lst, void (*del)(void *));` ⚠️ | Frees the node and all successors; sets `*lst` to NULL |
| `void ft_lstiter(t_list *lst, void (*f)(void *));` | Applies `f` to every node's content |
| `t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));` ⚠️⚠️ | New list of `f(content)`; cleans up fully on failure |

**Edge cases**

- `lstclear`: you must save `next` before freeing the current node (use-after-free otherwise); empty list; confirm `*lst == NULL` afterwards
- `lstmap`: if creating a node fails, the content that `f` just produced must be freed with `del` (it's not in any node yet), and the whole new list must be cleared. This subtle leak is the classic `lstmap` evaluation question. Test with `del = free` and content from `strdup`.

### Common mistakes

- `split` returning NULL for an empty string instead of `[NULL]`
- `split` leaking earlier words when a later `malloc` fails
- Using a node after freeing it in `lstclear`
- `lstadd_back` not handling an empty list
- Freeing the original list's content in `lstmap` (it must stay intact)

### Checkpoint

1. Why does `ft_lstadd_front` take `t_list **` instead of `t_list *`?
2. In `lstmap`, if `lstnew` fails, what exactly do you free and in what order?
3. Walk through `ft_split(",,a,,b,", ',')` step by step, including every `malloc`.
4. Read this prototype aloud: `void *(*f)(void *)`.

**Estimated time:** ~8 hours. If you run over, move `lstiter`/`lstmap` to Day 5's buffer. Don't rush `split`.

---

## Day 5: Buffer, Verification, and Evaluation Prep

**Main objective:** Turn "it works on my tests" into "I can defend every line."

### Session 1: Buffer (1 h)

Finish anything left from Day 4. If nothing is left, re-test `split`, `lstmap`, and `strlcat`.

### Session 2: Comprehensive testing (1.5–2 h)

1. Run your own test mains for all 43 functions.
2. Then run a community tester (e.g. libftTester, libft-unit-test, or francinette) *after* your own tests, as a cross-check. Some testers still assume `int ft_lstsize`, or bonus-file layouts from older subjects, so read failures critically rather than blindly "fixing" them.
3. For every failure: reproduce it in your own main, understand it, then fix it.

### Session 3: Leaks and undefined behavior (1 h)

- Valgrind every allocating function and all list functions
- Build tests with `-fsanitize=address,undefined -g` to catch out-of-bounds reads and signed overflow
- Re-check `substr`, `strtrim`, and `itoa` for off-by-one reads

### Session 4: Norm, Makefile, and repo hygiene (1 h)

- `norminette` on every `.c` and `libft.h`: zero errors
- Makefile: `make`, `make` (no relink), `make clean`, `make fclean`, `make re`, with flags exactly `-Wall -Wextra -Werror`
- Repo contains only `Makefile`, `libft.h`, `ft_*.c`, and `README.md`. No test files, `.o` files, `a.out`, or `.DS_Store`.
- Every helper function is `static`, and there are no global variables

### Session 5: README (45 min)

- Italic first line: *This project has been created as part of the 42 curriculum by \<login\>.*
- **Description**, **Instructions**, **Resources** (man pages, references, and an honest description of how AI was used), plus the required detailed description of the library, e.g. a table of every function grouped by category

### Session 6: Rewrite from memory (1.5 h)

With notes closed, rewrite these on paper or in a scratch file, then compare: `memmove`, `strlcat`, `atoi`, `itoa`, `split`, `lstclear`, `lstmap`. Wherever you blank, that's what to review.

### Session 7: Mock evaluation (45 min)

Have a peer (or a rubber duck) pick random functions and ask "why?" at every line. Practice small live modifications, since the subject says evaluators may ask for one. Examples: make `split` accept a set of delimiters, make `putnbr_fd` print in hexadecimal, add an `ft_lstsize` that stops at a given node.

### Common mistakes on the final day

- "Fixing" tester failures that are actually correct for v19.3
- Committing test files
- Last-minute edits without re-running Norminette

### Checkpoint

Can you explain every function in under a minute each, including one edge case it handles?

**Estimated time:** 7–8 hours

---

## 5-Day Checklist

### Day 1

- [ ] Repo, `libft.h` with guards and `t_list`, working Makefile with no relinking
- [ ] 7 character functions return exactly 1 or 0
- [ ] `strlen`, `strchr`, `strrchr`, `strncmp` tested, including the `'\0'` search
- [ ] Norminette clean

### Day 2

- [ ] 6 memory functions; `memmove` tested with overlap in both directions
- [ ] `strlcpy`/`strlcat` match `-lbsd` for all `size` cases
- [ ] `strnstr`, `atoi` edge cases pass
- [ ] Norminette clean

### Day 3

- [ ] `calloc` handles 0 and overflow; `strdup` done
- [ ] `substr`, `strjoin`, `strtrim`, `itoa` handle their edge cases
- [ ] 4 `_fd` functions; `putnbr_fd(INT_MIN)` works
- [ ] Valgrind shows no leaks

### Day 4

- [ ] `strmapi`, `striteri`
- [ ] `split` passes all edge cases, with no leaks on simulated failure
- [ ] 9 list functions; `lstclear` sets `*lst = NULL`; `lstmap` cleans up on failure

### Day 5

- [ ] All testers reviewed; failures understood
- [ ] Valgrind and sanitizers clean
- [ ] Norminette: 0 errors; repo contains only required files
- [ ] README complete, with the AI usage described
- [ ] Rewrote the 7 hard functions from memory
- [ ] Mock evaluation done

---

## Must-Understand C Concepts Before Submitting

- Pointers, pointer arithmetic, `*` vs `&`, pointer-to-pointer
- `const` placement (`const char *` vs `char *const`)
- `void *` and why you cast to `unsigned char *`
- `char` signedness; `int` params in `is*`/`memset`/`strchr`
- `size_t`, unsigned wraparound, and integer overflow
- Stack vs heap; the lifetime of local variables
- `malloc`/`free` rules: `+1` for `'\0'`, one `free` per `malloc`, no double free, no use-after-free
- Undefined behavior: what it is, and why libc doesn't protect against NULL
- Overlapping memory
- Structs, `->`, self-referential structs
- Function pointers: syntax, passing, calling
- File descriptors and `write`
- Compilation pipeline: preprocessing → compiling → assembling → linking; static libraries and `ar`
- Makefile dependency logic
- `static` functions (file scope)

---

## Self-Evaluation Quiz

1. What's the difference between `memcpy` and `memmove`, and how does your `memmove` decide which direction to copy?
2. What does `ft_strlcat` return when `size` is smaller than the length of `dst`? Why is that useful?
3. Why must `ft_isalpha` take an `int` instead of a `char`?
4. What does `ft_strchr(s, '\0')` return?
5. Why does `ft_memcmp` compare `unsigned char` values?
6. How do you detect `nmemb * size` overflow in `ft_calloc` without causing it?
7. What does your `ft_calloc(0, 5)` return, and why does the subject care?
8. What does `ft_substr("abc", 5, 2)` return?
9. How does `ft_itoa` handle `INT_MIN`, and why is it a special case?
10. What does `ft_split("", ' ')` return? What about `ft_split("abc", '\0')`?
11. In `ft_split`, if the 4th word's `malloc` fails, what do you free?
12. Why does `ft_lstclear` take `t_list **` but `ft_lstdelone` takes `t_list *`?
13. Why must you store `next` before freeing a node?
14. In `ft_lstmap`, what leaks if you forget to call `del` when node creation fails?
15. Why doesn't `ft_lstdelone` free `lst->next`?
16. What does `static` mean on a function, and why does the subject require it for helpers?
17. What would cause your Makefile to relink, and how did you prevent it?
18. Why is `restrict` forbidden in your prototypes?
19. Why do you need `-lbsd` to test `strlcpy` on Linux?
20. What's undefined behavior? Give two examples from libft where libc doesn't protect you.

If you can answer all 20 without notes, you're ready for evaluation.

---

## Suggested Daily Workflow

For each function, follow this loop:

1. **Learn (5–10 min):** Read the man page, or the subject table for Part 2/3.
2. **Understand the original (5–10 min):** Call the real function with odd inputs and observe the results.
3. **Plan (5–15 min):** Write pseudocode or draw the memory on paper, and list the edge cases *before* coding.
4. **Code (10–40 min):** Write it and compile with `-Wall -Wextra -Werror`.
5. **Test (10–20 min):** Compare against the original on normal and edge cases, with Valgrind for anything that allocates.
6. **Review (5 min):** Run Norminette, then explain the function out loud in two sentences.

### Daily rhythm

- Work in 50-minute focused blocks with 10-minute breaks. After three blocks, take a longer break.
- Start each day with 20 minutes rewriting one hard function from the previous day from memory.
- End each day with Norminette, a commit, and the day's checkpoint questions.
- When stuck for more than 30 minutes, ask a peer before anything else. That's the subject's recommended practice, and explaining your bug aloud often solves it.
- Keep a short log of edge cases you discovered. It becomes your evaluation cheat sheet and material for the README.
