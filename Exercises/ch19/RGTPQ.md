# Red Green Thing Priority Queue: A Very Colorful Assignment

By Adonis, Akshay and Trostin

## The task

Given the following:

```C++
enum Color {RED, GREEN};

struct RGThing {
    Color color; 
    string label;
};

struct RGTpair {
    RGThing thing1;
    RGThing thing2;
};
```

Create a `RGTPQ` class implements a priority queue of `RGThing`s with the following member functions:

- `bool empty();`
- `void insert(RGThing);`
- `RGTpair remove();`

However, **there's a catch:** the queue excepts `RGThing`s in the insert function, but only returns in `RGTpair`s. This means that pairs of red and green elements are given higher priority than single red and green elements.

## Implementation

There are two main ways to implement this:

1. Two queues: one that holds pairs of red and green, another that holds individual elements.
2. One queue where the elements are alternating between red and green and loose elements are at the end of the queue.

### How to do the second implementation

Akshay did the second implementation with one queue, so let's take a look at that:

#### `void insert(RGThing)`

In order for pairs to work in one queue, red and green elements have to be right next to one another, and loose elements should be at the back, like so:

``` txt
R G R G R R   <-- Notice how the reds without corresponding greens are at the end
```

For this to happen, the insert function has to work in two main ways:

**Rule 1:** New greens should be placed BEHIND the red closest to the front WITHOUT a corresponding green:

Before:

```txt
R R R R R
```

After green:

```txt
Green placed right behind the front red
  |
  V
R G R R R R
```

After second green:

```txt
Green placed right behind the front red that DOES NOT have a corresponding green
      |
      V
R G R G R R R
  Ʌ
  |
(The front red already has a corresponding green)
```

**Rule 2:** New reds should be placed AHEAD of the green closest to the front WITHOUT a corresponding red:

Before:

```txt
G G G G G
```

After red:

```txt
Red placed right ahead of the front green
|
V
R G G G G G
```

After second red:

```txt
Red placed right ahead of the front green that DOES NOT have a corresponding green
    |
    V
R G R G G G G
Ʌ
|
(The front green already has a corresponding red)
```

Based on these rules, here is a basic algorithm for `insert(RGThing)`:

```txt
1. If the element is red,
    1.1 Start looping through the queue from the back.
    1.2 If you find a green,
        1.2.1 Check if that green has a corresponding red ahead of it.
            1.2.1.1 If it doesn't, then insert this red ahead of that green.
            1.2.1.1 If it does, then advance past that pair and continue.
    1.3 If you find a red,
        1.3.1 Advance past it.
    1.4 If you have reached the end of the queue, just insert the red at the end.

2. If the element is green,
    2.1 Start looping through the queue from the front.
    2.2 If you find a red,
        2.2.1 Check if that red has a corresponding green behind it.
            2.2.1.1 If it doesn't, then insert this green behind that red.
            2.2.1.2 If it does, then advance past that pair and continue.
    2.3 If you find a green,
        2.3.1 Advance past it.
    2.4 If you have reached the end of the queue, just insert the green at the end.
```

#### `RGTpair remove()`

This function is simple: provided that the `insert(RGThing)` did its job, The front of the queue should be a red and the one behind it a green. All you have to do is check some edge cases.

Below is the logic:

```txt
1. If the length of the queue is 0,
    1.1 Throw underflow error.
2. If the length of the queue is 1,
    2.1 There are no pairs, so throw underflow error.
3. Get the front two elements from the queue.
    3.1 If the first one is not red or the last one is not green, there are no pairs, just elements of one color. So, throw underflow error.
```

#### `bool empty()`

Return whether or not the length of the queue is 0.
