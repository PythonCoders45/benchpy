from setuptools import setup, Extension

benchpy_module = Extension('benchpy_core', sources=['benchpy_core.c'])

setup(
    name='benchpy',
    version='0.1',
    description='C-powered benchmarking for Python',
    ext_modules=[benchpy_module]
)
