#ifndef __JSONCDACCORD_H
#define __JSONCDACCORD_H

#include <json-c/json.h>

enum jdac_errors {
    JDAC_ERR_VALID = 0,
    JDAC_ERR_GENERAL_ERROR,
    JDAC_ERR_JSON_NOT_FOUND,
    JDAC_ERR_SCHEMA_NOT_FOUND,
    JDAC_ERR_WRONG_ARGS,
    JDAC_ERR_SCHEMA_ERROR,
    JDAC_ERR_INVALID,
    JDAC_REGEX_MISMATCH,
    JDAC_REGEX_MATCH,
    JDAC_REGEX_COMPILE_FAILED,
    JDAC_ERR_MAX
};

int jdac_validate_file(const char *jsonfile, const char *jsonschemafile);
int jdac_validate(json_object *jobj, json_object *jschema);
int jdac_ref_set_localpath(const char *_localpath);

const char *jdac_errorstr(unsigned int jdac_errors);

#endif //__JSONCDACCORD_H
