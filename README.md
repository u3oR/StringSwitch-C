# StringSwitch-C

Description (English/Chinese):
This repository provides two versions of a C macro that simulate a switch statement for string matching. The macros allow developers to implement a switch-case style structure based on string input, which is not natively supported in C. The repository contains both a predefined string-integer mapping approach (StrSwitch) and a more flexible variadic version (StrSwitchV2).

本仓库提供了两个版本的 C 语言宏，用于模拟基于字符串的 switch 语句。这些宏允许开发者使用基于字符串输入的 switch-case 结构，解决了 C 语言不支持字符串 switch 的问题。仓库中包含预定义字符串-整数映射的实现（StrSwitch），以及一个更灵活的变参版本（StrSwitchV2）。

Features (English/Chinese):
StrSwitch Macro: Uses a predefined StringPair_t array, which allows the user to associate strings with integer IDs for efficient string-based switching.

StrSwitch 宏：使用预定义的 StringPair_t 数组，允许用户将字符串与整数 ID 关联，以便实现高效的基于字符串的切换。

StrSwitchV2 Macro: A more flexible, variadic version that accepts inline string-ID pairs directly as arguments without requiring a predefined array.

StrSwitchV2 宏：更灵活的变参版本，允许用户直接传递字符串-ID 对作为参数，无需预定义数组。

String-based case matching: Allows direct string comparisons in the switch-case structure, giving the look and feel of a typical switch statement.

基于字符串的 case 匹配：允许在 switch-case 结构中直接进行字符串比较，模拟出与标准 switch 语句相似的用法。

Compact and readable syntax: The syntax closely resembles the standard switch-case structure, making it familiar and easy to use for C developers.

简洁且可读的语法：语法设计类似于标准的 switch-case 结构，使 C 开发者可以轻松使用。

Example Usage (English/Chinese):
StrSwitch (Predefined String Array) / StrSwitch（预定义字符串数组）:

```c
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
        // Handle CommandA
        break;
    }
    StrCase(2, "CommandB")
    {
        // Handle CommandB
        break;
    }
    StrDefault()
    {
        // Handle unknown commands
        break;
    }
}
```

StrSwitchV2 (Variadic String Matching) / StrSwitchV2（变参字符串匹配）:
```c
const char *key = "CMDB";

StrSwitchV2(key,
    {1, "CMDA"},
    {2, "CMDB"},
    {3, "CMDC"})
{
    case 1:
        // Handle CMDA
        break;
    case 2:
        // Handle CMDB
        break;
    default:
        // Handle unknown commands
        break;
}
```

// END
