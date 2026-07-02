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


## OOP
```
class Milk:
    def __init__(self, amount):
        self.name = "milk"
        self.amount = amount
    
    def __str__(self):
        return f"Milk amount: {self.amount}"

class Coconut:
    def __init__(self, amount):
        self.name = "coconut"
        self.amount = amount
    
    def __str__(self):
        return f"Coconut amount: {self.amount}"

class Juice:
    def __init__(self, amount):
        self.name = "juice"
        self.amount = amount
    
    def __str__(self):
        return f"Juice amount: {self.amount}"

class Smoothie:
    def __init__(self, ingredients):
        self._ingredients = ingredients

    def __str__(self) -> str:
        return "Smoothie contains: " + ", ".join([str(ingredient) for ingredient in 
                                                 self._ingredients])
        
    def __add__(self, other):
        comb_ingredients = list(set([ing.name for ing in sm2._ingredients]).union(
                                set([ing.name for ing in sm._ingredients])))
        return ", ".join(comb_ingredients)
```

### Getters and Setters
```

class Dog:
    def __init__(self,  name) -> None:
        self._name = name

    def get_name(self):
        return self._name

    def set_name(self, new_name):
        self._name = new_name

class Dog:
    def __init__(self, name) -> None:
        self._name = name

    @property
    def name(self):
        return self._name
    
    @name.setter
    def name(self, new_name):
        self._name = new_name        
```

### Inheritance

```
class Vehicle:
    def __init__(self, make, model, year) -> None:
        self.make = make
        self.model = model
        self.year = year

    def ride(self):
        print(f"{self.make} {self.model} is riding")

    def __str__(self):
        return f"{self.year} {self.make} {self.model}"

class Car(Vehicle):
    def __init__(self, make, model, year, has_sunroof):
        super().__init__(make, model, year)
        self.has_sunroof = has_sunroof

    def __str__(self):
        # overwrite the parent method
        return f"Car: {self.make} {self.model} with sunroof" if self.has_sunroof\
         else f"Car: {self.make} {self.model}"

class Truck(Vehicle):
    def __init__(self, make, model, year, payload_capacity):
        super().__init__(make, model, year)
        self.payload_capacity = payload_capacity

    def __str__(self):
        # Extend a parent method
        vehicle_info = super().__str__()
        return f"{vehicle_info}, Truck capacity: {self.payload_capacity}"

class Motorcycle(Vehicle):
    pass
```
