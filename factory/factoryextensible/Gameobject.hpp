// #pragma once
#ifndef GAME_OBJECT_HPP
#define GAME_OBJECT_HPP

class IGameObject
{
public:
    virtual ~IGameObject() {}
    virtual void Update() = 0;
    virtual void Render() = 0;
};

class Plane : public IGameObject
{
public:
    Plane(int x, int y){ };
    void Update(){ };
    void Render(){ };
    static IGameObject *Create()
    {
        return new Plane(0, 0);
    }
};

class Boat : public IGameObject
{
public:
    Boat(int x, int y){ };
    void Update(){ };
    void Render(){ };
    static IGameObject *Create()
    {
        return new Plane(0, 0);
    }
};
#endif