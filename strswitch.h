#ifndef _STR_SWITCH_H_
#define _STR_SWITCH_H_

#include <string.h>

#if 1

typedef struct StringPair {
    int id;
    const char *str;
} StringPair_t;


#define STRINGPAIR_END (StringPair_t){.id = -1, .str = NULL}

#define StrCase(index, ...) case (index): ((void)(NULL,##__VA_ARGS__));
#define StrDefault()        default:

#define StrSwitch(input_str, strpair_array) \
        switch(({ int __case_value = -1;                \
            const StringPair_t *_ptr = strpair_array;   \
            while(_ptr->str) {                          \
                if(!strcmp(input_str, _ptr->str)) {     \
                    __case_value = _ptr->id;  break;    \
                } _ptr++;                               \
            } __case_value;}))
/*
#define StrSwitch(input_str, strpair_array) \
        int __case_value = -1;                          \
        {                                               \
            const StringPair_t *_ptr = strpair_array;   \
            while(_ptr->str) {                          \
                if(strcmp(input_str, _ptr->str) == 0) { \
                    __case_value = _ptr->id;            \
                    break;                              \
                }                                       \
                _ptr++;                                 \
            }                                           \
        } switch(__case_value)
*/

/* Usage 

    const char *command = "start";

    StringPair_t commands[] = {
        {1, "start"},
        {2, "stop"},
        {3, "restart"},
        STRINGPAIR_END
    };

    StrSwitch(command, commands) {
        StrCase(1, "start") {
            printf("Starting...\n");
            break;
        }
        StrCase(2)
            printf("Stopping...\n");
            break;
        StrCase(3)
            printf("Restarting...\n");
            break;
        StrDefault()
            printf("Unknown command\n");
    }

*/
#endif


#if 0

#define StrSwitch(x)    { int _hit_flag = 0, _continue_flag = 0; const char *_str = x; do {{
#define StrCase(str)    } if ((_continue_flag != 0) || strcmp(_str, str) == 0) { _hit_flag = 1; _continue_flag = 1;
#define StrDefault()    } if ((_hit_flag == 0) || (_continue_flag != 0)) {
#define StrSwitchEnd    }} while(0); }

/* Usage 

    const char * key = "CommandA";

    StrSwitch(key) {

        StrCase("CommandA")
        StrCase("CommandB") {
            printf("match str %s\n", key);
            break;
        }

        StrDefault() {
            printf("match str unknown\n");
            break;
        }
        
    } StrSwitchEnd

*/
#endif


#endif
// End
 
