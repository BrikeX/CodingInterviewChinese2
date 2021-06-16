/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������5���滻�ո�
// ��Ŀ����ʵ��һ�����������ַ����е�ÿ���ո��滻��"%20"���������롰We are happy.����
// �������We%20are%20happy.����

#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>

/*length Ϊ�ַ�����str�������������ڻ�����ַ���str��ʵ�ʳ���*/
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

// ====================���Դ���====================
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

// �ո��ھ����м�
void Test1()
{
    const int length = 100;

    char str[length] = "hello world";

    char expected[] = "hello%20world";

    Test("Test1", str, length, expected);
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
    const int length = 100;

    char str[length] = " helloworld";

    char expected[] = "%20helloworld";

    Test("Test2", str, length, expected);
}

// �ո��ھ���ĩβ
void Test3()
{
    const int length = 100;

    char str[length] = "helloworld ";

    char expected[] = "helloworld%20";

    Test("Test3", str, length, expected);
}

// �����������ո�
void Test4()
{
    const int length = 100;

    char str[length] = "hello  world";

    char expected[] = "hello%20%20world";

    Test("Test4", str, length, expected);
}

// ����nullptr
void Test5()
{
    Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
    const int length = 100;

    char str[length] = "";

    char expected[] = "";

    Test("Test6", str, length, expected);
}

//��������Ϊһ���ո���ַ���
void Test7()
{
    const int length = 100;

    char str[length] = " ";

    char expected[] = "%20";

    Test("Test7", str, length, expected);
}

// ������ַ���û�пո�
void Test8()
{
    const int length = 100;

    char str[length] = "helloworld";

    char expected[] = "helloworld";

    Test("Test8", str, length, expected);
}

// ������ַ���ȫ�ǿո�
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

