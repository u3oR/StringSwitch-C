# StringSwitch-C

## README for `strswitch.h`

---

#### Overview
This project provides a macro-based utility for string matching using `switch-case` semantics in C. It defines two methods to facilitate efficient string comparisons with cleaner syntax. This header simplifies the process of handling multiple string cases, improving readability and reducing error-prone code.

---

### Features
- **Two implementations**: Choose between two methods based on code style and preference.
- **Macro-driven string comparisons**: Use familiar `switch-case` constructs for string matching.
- **Easy-to-read code**: Reduces the complexity of repetitive `if-else` string comparisons.
- **Support for a default case** when no string matches.

---

### Usage

#### First Implementation (Enabled by `#if 1`)

In this version, you define string pairs using the `StringPair_t` structure. Each pair consists of an `id` and a corresponding string. The `StrSwitch` macro performs string comparisons and evaluates cases based on the `id`.

**Example:**
```c
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
```

---

#### Second Implementation (Enabled by `#if 0`)

The second version offers an alternative string matching syntax. It uses `StrSwitch`, `StrCase`, `StrDefault`, and `StrSwitchEnd` macros to simulate a `switch-case` structure for strings.

**Example:**
```c
const char *key = "CommandA";

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
```

---

### 中文

#### 概述
该项目提供了基于宏定义的工具，用于在 C 语言中实现类似 `switch-case` 的字符串匹配。此头文件定义了两种方法，简化了字符串匹配的过程，使代码更清晰、更易读，并减少了重复性代码的出错风险。

---

### 功能特点
- **两种实现方式**：可以根据代码风格和需求选择不同的实现。
- **基于宏的字符串比较**：使用类似 `switch-case` 的语法结构进行字符串匹配。
- **代码清晰易读**：减少了复杂的 `if-else` 语句。
- **支持默认情况**：当没有匹配的字符串时执行默认操作。

---

### 用法

#### 第一种实现方式（通过 `#if 1` 启用）

在此实现中，通过 `StringPair_t` 结构体定义字符串对。每对包含一个 `id` 和对应的字符串。`StrSwitch` 宏用于进行字符串比较，并根据 `id` 匹配对应的 `case`。

**示例：**
```c
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
```

---

#### 第二种实现方式（通过 `#if 0` 启用）

此实现方式提供了另一种字符串匹配的语法。通过 `StrSwitch`、`StrCase`、`StrDefault` 和 `StrSwitchEnd` 宏来模拟字符串的 `switch-case` 结构。

**示例：**
```c
const char *key = "CommandA";

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
```

---

This README provides a detailed guide on how to use the two string-switch implementations, including both Chinese and English documentation.
