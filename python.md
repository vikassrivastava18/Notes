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
```
if re.search(r"^\w+@(\w+\.)?\w+\.(edu|com|org|net|gov)$", email):
    print("Valid")
else:
    print("Invalid")
```

Groups
```
name = input("What's your name: ").strip()
if matches := re.search(r"^(.+) (.+)", name):
    name = f"{matches.group(1)} {matches.group(2)}"

print(f"hello {name}")
```

Extract input
```
url = input("URL: ").strip()

if matches := re.search(f"^https?://(www\.)?twitter\.com/(.+)", url, re.IGNORECASE):
    print(matches.groups())
```
