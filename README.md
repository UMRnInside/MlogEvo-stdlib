# MlogEvo-stdlib
"Standard libraries" for MlogEvo.

It's hard to distribute MlogEvo Standard Library with MlogEvo, for the `egg` format does NOT include those C header files, and `wheel` format drops its hierarchy.

## Install
1. Download the standard library. Of course, you can click Code -> Download ZIP (on GitHub) instead.
```bash
# Use git
git clone https://github.com/UMRnInside/MlogEvo-stdlib --depth 1
```
2. Install this into Python include directory
```bash
cd MlogEvo-stdlib
python3 install_stdlib.py
```

## Uninstall
```bash
cd MlogEvo-stdlib
python3 uninstall_stdlib.py
```

# Usage without installation
```bash
python3 -m mlogevo -I/path/to/MlogEvo-stdlib/include your-source-code.c
```
