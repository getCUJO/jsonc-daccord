#ifndef __JDAC_OPTIONAL_H
#define __JDAC_OPTIONAL_H

#include <json-c/json.h>

typedef struct storage_node {
    char JSONPtrURI[128];
    char id[128];
    char anchor[32];
    char dynamicAnchor[32];
    json_object *json_instance_ptr;
    json_object *json_schema_ptr;
    int is_root;
    struct storage_node *next;
} storage_node;

// clang-format off
int _jdac_match_string_with_regex  (const char* regex_pattern, const char* value);
int _jdac_check_pattern                    (json_object *jobj, json_object *jschema, json_object *joutput_node);
int _jdac_check_patternproperties          (json_object *jobj, json_object *jschema, json_object *joutput_node);
int _jdac_check_additionalproperties       (json_object *jobj, json_object *jschema, json_object *joutput_node);
int _jdac_check_propertynames              (json_object *jobj, json_object *jschema, json_object *joutput_node);
int _jdac_check_subschemalogic             (json_object *jobj, json_object *jschema, json_object *joutput_node);
int _jdac_check_contains_and_minmaxcontains(json_object *jobj, json_object *jschema, json_object *joutput_node);
// clang-format off

char *_jdac_download_schema(const char *url);
const char *_jdac_download_resolve(const char *uri);

int _jdac_store_traverse_json(storage_node **head, json_object *jschema, char *pathbuffer);
void _jdac_store_free(storage_node **head);
void _jdac_store_print(storage_node *head);
json_object *_jdac_store_resolve(storage_node *list, const char *uri);
storage_node *_jdac_store_get_root_node(storage_node *head);

int _jdac_check_ref(json_object *jobj, json_object *jschema, storage_node *storage_list,
                    json_object *joutput_node);

#endif // __JDAC_OPTIONAL_H
