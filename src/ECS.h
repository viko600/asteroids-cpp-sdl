#pragma once

#include <iostream>
#include <vector>
#include <memory>
#include <bitset>
#include <array>
#include <algorithm>

class Component;
class Entity;

using ComponentID = std::size_t;

inline ComponentID getComponentId(){
    static ComponentID lastId = 0;
    return lastId++;
}

template <typename T> inline ComponentID getComponentId() noexcept{
    static ComponentID component = getComponentId();
    return component;
}

constexpr std::size_t maxComponents = 32;
using ComponentBitset = std::bitset<maxComponents>;
using ComponentArray = std::array<Component*, maxComponents>;

class Component
{
public:
    Entity* entity;

    virtual void init() {};
    virtual void update() {};
    virtual void draw() {};

    virtual ~Component() {};
};

class Entity
{
private:
    bool active = true;
    std::vector<std::unique_ptr<Component>> components;

    ComponentBitset bitset;
    ComponentArray componentArray;

public:
    void update() {
        for (auto& c : components) c->update();
    };
    void draw() {
        for (auto& c : components) c->draw();
    };
    bool isActive() { return active; };
    void destroy() { active = false; };

    template <typename T> bool hasComponent(){
        return bitset[getComponentId<T>()];
    }

    template <typename T, typename... TArgs>
    T& addComponent(TArgs&&... myArgs){
        T* c(new T(std::forward<TArgs>(myArgs)...));
        c->entity = this;
        std::unique_ptr<Component> comp { c };
        components.emplace_back(std::move(comp));

        componentArray[getComponentId<T>()] = c;
        bitset[getComponentId<T>()] = true;

        c->init();
        return *c;
    };

    template <typename T> T& getComponent() {
        auto ptr(componentArray[getComponentId<T>()]);
        return *static_cast<T*>(ptr);
    }
};

class Manager
{
private:
    std::vector<std::unique_ptr<Entity>> entities;

public:
    void update() {
        for(auto& e : entities) e->update();
    }

    void draw() {
        for (auto& e : entities) e->draw();
    }

    void refresh() {
        entities.erase(std::remove_if(entities.begin(), entities.end(),
            [](const std::unique_ptr<Entity> &ent){
                return !ent->isActive();
            }
        ), std::end(entities));
    };

    template <typename T> bool collision() {
        for(auto& ent : entities){
            std::cout << ent->getComponent<T>().tag << std::endl;
        }
        return true;
    }

    void destroy(Entity *entity) {
        entity->destroy();
    }

    Entity& addNewEntity(){
        Entity* e = new Entity();
        std::unique_ptr<Entity> ePtr { e };
        entities.emplace_back(std::move(ePtr));
        return *e;
    }
};