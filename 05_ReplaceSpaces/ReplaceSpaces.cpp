/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{
    if(str == nullptr || length <= 0)
        return;

    int str_length = 0, blank_count = 0;

    while (str[str_length] != '\0')
    {
        if (str[str_length++] == ' ')
        {
            blank_count++;
        }
    }
    
    int new_length = str_length + blank_count * 2;

    if (new_length > length)
    {
        return;
    }

    int index_str = str_length, index_new = new_length;

    while (index_str < index_new)
    {
        if (str[index_str] == ' ')
        {
            str[index_new--] = '0';

            str[index_new--] = '2';

            str[index_new--] = '%';
        }
        else
        {
            str[index_new--] = str[index_str];
        }
        
        index_str--;
    }
}

// ====================测试代码====================
void Test(const std::string& testName, char str[], int length, char expected[])
{
    if (!testName.empty())
    {
        std::cout << testName << " begins: ";
    }
    
    ReplaceBlank(str, length);

    if(expected == nullptr && str == nullptr)
        printf("passed.\n");
    else if(expected == nullptr && str != nullptr)
        printf("failed.\n");
    else if(strcmp(str, expected) == 0)
        printf("passed.\n");
    else
        printf("failed.\n");
}

// 空格在句子中间
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";

    char expected[] = "hello%20world";

    Test("Test1", str, length, expected);
}

// 空格在句子开头
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";

    char expected[] = "%20helloworld";

    Test("Test2", str, length, expected);
}

// 空格在句子末尾
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";

    char expected[] = "helloworld%20";

    Test("Test3", str, length, expected);
}

// 连续有两个空格
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";

    char expected[] = "hello%20%20world";

    Test("Test4", str, length, expected);
}

// 传入nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
    const int length = 100;

    char str[length] = "";

    char expected[] = "";

    Test("Test6", str, length, expected);
}

//传入内容为一个空格的字符串
void Test7()
{
    const int length = 100;

    char str[length] = " ";

    char expected[] = "%20";

    Test("Test7", str, length, expected);
}

// 传入的字符串没有空格
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";

    char expected[] = "helloworld";

    Test("Test8", str, length, expected);
}

// 传入的字符串全是空格
void Test9()
{
    const int length = 100;

    char str[length] = "   ";

    char expected[] = "%20%20%20";

    Test("Test9", str, length, expected);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();

    return 0;
}

