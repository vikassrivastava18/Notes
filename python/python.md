## REGEX

Symbols used
```
.   any character except the new line
*   0 or more repetition
?   0 or 1 repetion
+   1 or more repetition
{m} m repetitions
{m-n}   m-n repetitions   
```
Additional Patterns
```
\d  decimal digit
\D  not a decimal digit
\s  whitespace characters
\S not a whitespace character
\w  word character, as well as numbers and underscore
```

Pattern matching (Returns True/False)
Below regex searches for a pattern starting with `w` (includes word character, digits, underscore). It should be followed by `@`, then one or more `w` and `.` together. It must have end with something in the group: edu or com ....
```
if re.search(r"^\w+@(\w+\.)?\w+\.(edu|com|org|net|gov)$", email):
    print("Valid")
else:
    print("Invalid")
```

Groups
The pattern contained in () is extracted as groups indexed from 1
```
name = input("What's your name: ").strip()
if matches := re.search(r"^(.+) (.+)", name):
    name = f"{matches.group(1)} {matches.group(2)}"

print(f"hello {name}")
```

Extract input
Extract username from a twitter account. The index of username will be 2, 1 could be None if `www.` is not in the URL
```
url = input("URL: ").strip()

if matches := re.search(f"^https?://(www\.)?twitter\.com/(.+)", url, re.IGNORECASE):
    print(matches.groups())
```
