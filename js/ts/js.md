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

### Rest parameters

```
function addProduct(name, ...categories) {
  const product = {
    name: name,
    categories: categories.join(',')
  };
  return product;
}

console.log(addProduct('Vikas', 'Electronics', 'Computers', 'Gadgets')); // { name: 'Vikas', categories: 'Electronics,Computers,Gadgets' }
```

### Optional chaining
```
if (order !== undefined) {
  const product = order.product;
}

const product = order?.product

const order = {
  product: {
    name: 'Laptop',
    price: 1200
  }
};
const name = order?.product?.name;
console.log(name); // Laptop

const student = {
  details: {
  }
};
const roll = student?.details?.roll;
console.log(roll); // undefined
```

### Nullish coalescing
```
const quantity = qty ? qty : 1;
const quantity = qty ?? 1;
```

### Class
```
class Animal {
  constructor(name) {
    this.name = name;
  }

  speak() {
    console.log(`${this.name} makes a noise.`);
  }
}

class Dog extends Animal {
  constructor(name) {
    super(name); // call the super class constructor and pass in the name parameter
  }

  speak() {
    console.log(`${this.name} barks.`);
  }
}

const d = new Dog("Mitzie");
d.speak(); // Mitzie barks.
```



