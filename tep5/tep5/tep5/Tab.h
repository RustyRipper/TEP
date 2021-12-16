#pragma once
#define DEFAULT_LENGTH 10

class Tab
{
public:
    Tab() { tab = new int[DEFAULT_LENGTH]; size = DEFAULT_LENGTH; }
    Tab(const Tab& cOther);
    Tab(Tab&& cOther)noexcept;
    ~Tab();

    bool setSize(int newSize);
    int getSize() { return(size); }

    Tab operator=(const Tab& other);
    Tab operator=(Tab&& other)noexcept;

private:
    void copy(const Tab& other);
    void move(Tab& other);
    int* tab;
    int size;
};
