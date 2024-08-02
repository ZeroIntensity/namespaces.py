# namespaces.py

## No more stupid dots

- Tired of using the boring old `foo.bar` notation?
- Feel like cheating on your type checker?
- Want to pretend like you're writing C++, even though you aren't?

Fear not, for `namespaces.py` is here!

## Example

```py
import namespaces

namespaces.inject()

class Test:
    @staticmethod
    def hello():
        print("hello world!")


Test[::"hello"]()  # hello world!
```

## Features

- Cool `::` C++ like symbol to make you feel special
- Show your linter who's boss
- Pretend this is a feature, I wanted to have 3 listed here to make it seem more even

## Installation

```
$ pip install namespaces.py
```

## Docs?

I'm gonna pretend you didn't ask that.

## Compatibility

Aw come on, discovering broken versions is half the fun.
