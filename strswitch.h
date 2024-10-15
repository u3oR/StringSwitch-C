#ifndef _STR_SWITCH_H_
#define _STR_SWITCH_H_

#include <string.h>

typedef struct StringPair {
    int id;
    const char *str;
} StringPair_t;

#define STRINGPAIR_END (StringPair_t){.id = -1, .str = NULL}

#define StrCase(index, str) case (index): ((void)str);
#define StrDefault()        default:

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

/* Usage 
const StringPair_t pair[] = {
    {1, "CommandA"},
    {2, "CommandB"},
    {3, "CommandC"},
    STRINGPAIR_END
};
const char *key = "CommandC";
StrSwitch(key, pair)
{
    StrCase(1, "CommandA")
    {
        // do something ...
        break;
    }
    StrDefault()
    {
        // unknown command
        break;
    }
}
*/

#define StrSwitchV2(input_str, ...) \
    int __case_value = -1;                          \
    {                                               \
        const StringPair_t strpair_array[] = {      \
            __VA_ARGS__,                            \
            STRINGPAIR_END                          \
        };                                          \
        const StringPair_t *ptr = strpair_array;    \
        while(ptr->str != STRINGPAIR_END.str) {     \
            if(strcmp(ptr->str, inout_str) == 0) {  \
                __case_value = ptr->id;             \
                break;                              \
            }                                       \
            ptr++;                                  \
        }                                           \
    } switch (__case_value)

/* Usage
StrSwitchV2(str, 
    {1, "CMDA"},
    {2, "CMDB"},
    {3, "CMDC"})
{
    case 1:
        break;
    case 2:
        break;
    default:
        break;
}
*/

#if 1

#define StrSwitch(x) { do {
#define StrCase(str) 
#defien StrSwitchEnd() while(0); } 

#endif


#endif
// End
