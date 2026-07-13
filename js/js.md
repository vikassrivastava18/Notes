What is the difference between var, let and const
```
var is function scoped while let and const are block scoped. All three are hoisted but var is initialized with undefined, wheras let and const remian in the Temporal Dead Zone until the declaration is reached, causing a ReferenceEror if accessed beforehanf. const neither allows reassignmnet nor redeclaration and must be initialized when declared. let allows reassignment but not redeclaration
```

Closure and lexical scoping
The inner function remembers the lexical environment in which it was defined
```
function counter() {
    let count = 0;

    return function () {
        count++;
        console.log(count);
    };
}

const c1 = counter();

c1();
c1();
c1();

const c2 = counter();

c2();
// 1, 2, 3 and 1

def multiplier(x) {
  return function(y) {
    return x * y
  }
}

const double = multiplier(2)
double(3) // 6

const triple = multiplire(3)
triple(5) // 15
```


### Spread parameter
```
const category = 'Computing';
const categories = ['Gaming', 'Multimedia'];
const productCategories = [...categories, category];
```

On objects
```
const product = {
  name: 'Keyboard',
  price: 75
};
const newProduct = {
  ...product,
  price: 100, // overwrite the price property of product
  category: 'Computing'
};
```

