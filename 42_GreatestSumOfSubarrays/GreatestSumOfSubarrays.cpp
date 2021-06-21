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

// ������42�����������������
// ��Ŀ������һ���������飬������������Ҳ�и�����������һ���������Ķ����
// �����һ�������顣������������ĺ͵����ֵ��Ҫ��ʱ�临�Ӷ�ΪO(n)��

#include <cstdio>
#include <vector>

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
    if((pData == nullptr) || (nLength <= 0))
    {
        g_InvalidInput = true;
        return 0;
    }

    g_InvalidInput = false;

    // int nCurSum = 0;
    // int nGreatestSum = 0x80000000;
    // for(int i = 0; i < nLength; ++i)
    // {
    //     if(nCurSum <= 0)
    //         nCurSum = pData[i];
    //     else
    //         nCurSum += pData[i];

    //     if(nCurSum > nGreatestSum)
    //         nGreatestSum = nCurSum;
    // }

    // return nGreatestSum;

    // DP
    std::vector<int> greatest_sum(nLength);

    greatest_sum[0] = pData[0];

    int sum_max = greatest_sum[0];

    for (size_t i = 1; i < nLength; i++)
    {
        if (greatest_sum[i - 1] > 0)
        {
            greatest_sum[i] = greatest_sum[i - 1] + pData[i];
        }
        else
        {
            greatest_sum[i] = pData[i];
        }
        
        sum_max = std::max(sum_max, greatest_sum[i]);
    }
    
    return sum_max;
} 

// ====================���Դ���====================
void Test(const char* testName, int* pData, int nLength, int expected, bool expectedFlag)
{
    if(testName != nullptr)
        printf("%s begins: \n", testName);

    int result = FindGreatestSumOfSubArray(pData, nLength);
    if(result == expected && expectedFlag == g_InvalidInput)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

// 1, -2, 3, 10, -4, 7, 2, -5
void Test1()
{
    int data[] = {1, -2, 3, 10, -4, 7, 2, -5};
    Test("Test1", data, sizeof(data) / sizeof(int), 18, false);
}

// �������ֶ��Ǹ���
// -2, -8, -1, -5, -9
void Test2()
{
    int data[] = {-2, -8, -1, -5, -9};
    Test("Test2", data, sizeof(data) / sizeof(int), -1, false);
}

// �������ֶ�������
// 2, 8, 1, 5, 9
void Test3()
{
    int data[] = {2, 8, 1, 5, 9};
    Test("Test3", data, sizeof(data) / sizeof(int), 25, false);
}

// ��Ч����
void Test4()
{
    Test("Test4", nullptr, 0, 0, true);
}

int main(int argc, char* argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();

    return 0;
}

