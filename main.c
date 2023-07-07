#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// ������� ��� ���������� ���������
unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; i++) {
        result *= i;
    }
    return result;
}

// ������� ��� ���������� ������� �������
unsigned long long countAnagrams(char* word) {
    int counts[26] = {0};
    int length = strlen(word);

    // ������ ������� ����� ����� � ����
    for (int i = 0; i < length; i++) {
        counts[word[i] - 'A']++;
    }

    // ���������� ������� ������� �� �������� n! / (n1! * n2! * ... * nk!),
    // �� n - �������� ������� ����, � n1, n2, ..., nk - ������� ����� �����
    unsigned long long totalAnagrams = factorial(length);
    for (int i = 0; i < 26; i++) {
        if (counts[i] > 1) {
            totalAnagrams /= factorial(counts[i]);
        }
    }

    return totalAnagrams;
}

int main() {
    char word[15];
    printf("Enter the word: ");
    scanf("%s", word);

    unsigned long long anagramCount = countAnagrams(word);
    printf("Number of possible anagrams: %llu\n", anagramCount);

    return 0;
}
