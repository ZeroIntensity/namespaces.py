from setuptools import Extension, setup

if __name__ == '__main__':
    setup(name="namespaces.py", license="MIT", ext_modules=[Extension("namespaces", ["./mod.c"])],)
