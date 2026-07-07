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

