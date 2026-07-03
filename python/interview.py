import re

## Validate email
email = "vikas@gmail.india.com"

if re.search(r"^\w+@(\w+.)+\.(edu|in|com)", email):
    print("Email valid")

## Groups
name = input("Enter your name: ").strip()
if matches := re.search(r"^(\w+) (.+)", name):
    name = f"{matches.group(1)} {matches.group(2)}"
    print(f"hello {name}")