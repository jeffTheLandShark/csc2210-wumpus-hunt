/*
 *
 *
 */

#ifndef ITEM_H
#define ITEM_H

#include "player.h"
#include "innards.h"


class Items : public Innards {
public:
  Items(char symbol) : Innards(symbol) {}
  virtual ~Items() = default;
  virtual void pickup(Player player);

private:
  bool used = false;
};

class AirTank : public Items {
public:
  AirTank() : AirTank(5) {}
  AirTank(int air) : Items('?'), air(air) {}
  void pickup(Player player) override;

private:
  int air;
};

class Weapon : public Items {
public:
  Weapon() : Items('>') {}
  virtual bool use(Player player, char direction);
};

class Net : public Weapon {
public:
  void pickup(Player player) override;
  bool use(Player player, char direction) override;
};

class Harpoon : public Weapon {
public:
  void pickup(Player player) override;
  bool use(Player player, char direction) override;
};
#endif //ITEM_H
