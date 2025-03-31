#include <iostream>
#include <cstdio>
using namespace std;

int main ()
{
    setlocale (LC_ALL, "ru");
    char writeData [] =
    "Aнтон любит учиться.\n"
    "Сегодня хорошая погода.\n"
    "Aлина учиться в университете.\n"
    "Aвтобус опять не приехал во время.\n"
    "Я люблю баскетбол.\n"
    "Aлександр работает в IT-компании.\n"
    "Илья завтра сдает историю.\n"
    "Aлексей написал код сам.\n"
    "Компьютеры надо заменить.\n"
    "Это строка очень стильная.\n";
    FILE* fp1 = fopen("/Users/nikita/Documents/PSTU/Лабы/Lab9/F1.txt", "w");
    if (fp1)
    {
        for (int i = 0; writeData[i] != '\0'; ++i)
        {
            fputc(writeData[i], fp1);
        }
        fclose(fp1);
    }
    
    FILE* inFP = fopen("/Users/nikita/Documents/PSTU/Лабы/Lab9/F1.txt", "r");
    FILE* outFP = fopen("/Users/nikita/Documents/PSTU/Лабы/Lab9/F2.txt", "w");
    
    if (inFP && outFP)
    {
        char line[256];
        while (fgets(line, sizeof(line), inFP))
        {
            if (line[0] == 'A')
            {
                fputs(line, outFP);
            }
        }
        fflush(outFP);
        fclose(inFP);
        fclose(outFP);
    }
    
    FILE* readFP = fopen("/Users/nikita/Documents/PSTU/Лабы/Lab9/F2.txt", "r");
    if (readFP)
    {
        char buffer[1000];
        char curChar;
        int i = 0;
        while ((curChar = fgetc(readFP)) != EOF && i < sizeof(buffer) - 1)
        {
            buffer[i++] = curChar;
        }
        buffer[i] = '\0';
        
        int wordCount = 0;
        bool inWord = false;
        for (int j = 0; buffer[j] != '\0'; j++)
        {
            if (buffer[j] == ' ' || buffer[j] == '\n')
            {
                inWord = false;
            }
            else if (!inWord)
            {
                inWord = true;
                wordCount++;
            }
        }
        fclose(readFP);
        
        puts(buffer);
        cout << "Количество слов в F2.txt: " << wordCount << endl;
    }
    
    return 0;
}
    
    
