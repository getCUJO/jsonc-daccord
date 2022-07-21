# json-c d'accord library (libjsoncdac)

jsonc-daccord is a lightweight JSON Schema validation library written in C, and is taking advantage of the libjson-c library.

## Design Goals

The goal is to have a lightweight JSON Schema validation implementation in C using json-c. json-c is popular in OpenWRT communities. Initially I just wanted it to support a small subset of JSON Schema to suit a need to validate simple json files. See the minimum build supports below. However to suit a broader audience, supporting more JSON Schema is important.

Currently the footprint of libjsoncdac.so is 8KB. The keep the footprint from bloating out, new features should be selectable using CMake options.

Minimal build supports:
- all: type, enum, required, properties.
- objects: anyOf.
- strings: minLength, maxLength.
- integers: minimum, maximum.
- arrays: minItems, maxItems, uniqeItems, items.

## Example Use

You can pass json and schema as either filepaths or `json_object`:

```
    int jdac_validate(const char *jsonfile, const char *jsonschemafile);

    int jdac_validate_node(json_object *jobj, json_object *jschema);
```

For return values, see: [jsoncdaccord.h](include/jsoncdaccord.h)

Link your binary to: `-ljsoncdac -ljson-c`

Use the #include header: `#include <jsoncdaccord.h>`

Example C code (based on jdac-cli):

```
#include <stdio.h>
#include <json-c/json.h>
#include <jsoncdaccord.h>

int main(int argc, char *argv[])
{
    if (argc!=3) {
        printf("jdac-cli needs two arguments: paths to json and schema\n");
        return JDAC_ERR_WRONG_ARGS;
    }
    printf("validating %s with %s\n", argv[1], argv[2]);
    int err = jdac_validate(argv[1], argv[2]);
    if (err==JDAC_ERR_VALID) {
        printf("validation ok\n");
    } else {
        printf("validate failed %d\n", err);
    }
    return err;
}
```

## Install

Building from source:

Install json-c and libcmocka-dev (used in the debug builds).

- Release version:

```
git clone --branch libjsoncdac-0.1 https://github.com/domoslabs/jsonc-daccord &&\
cd jsonc-daccord && mkdir build && cd build &&\
cmake .. -DCMAKE_BUILD_TYPE=Release && make && sudo make install
```

- Debug version:
```
git clone --branch libjsoncdac-0.1 https://github.com/domoslabs/jsonc-daccord &&\
cd jsonc-daccord && mkdir build && cd build &&\
cmake .. -DCMAKE_BUILD_TYPE=Debug && make && sudo make install
```

Note: After install you might need to run `sudo ldconfig`.

## Run tests
For debug builds:
```
ctest
ctest -V # to see output of tests
```

Running test suites are currently optional, and are select with `RUN_TEST_SUITS=ON` in the cmake options.

## Command Line Interface
You can try the library with the jdac-cli command.

```
jdac-cli path-to-json path-to-schema
```
## To do
- ref, defs
- anyOf: any type
- prevent infinite recursion

## Related links

https://json-schema.org/draft/2020-12/json-schema-core.html
