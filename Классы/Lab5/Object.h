#pragma once

class Object
{
public:
    Object (void);
public:
    virtual ~Object (void);
    virtual void Show () = 0;
};

